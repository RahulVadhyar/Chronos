#include "engine.hpp"
#include "font.hpp"

void Chronos::Engine::Font::init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, VkRenderPass* renderPass){
    vertexShaderPath = "ThirdParty/Chronos/Shaders/textVert.spv";
    fragmentShaderPath = "ThirdParty/Chronos/Shaders/textFrag.spv";


    // initalize the font
    const uint32_t fontWidth = STB_FONT_consolas_24_latin1_BITMAP_WIDTH;
    const uint32_t fontHeight = STB_FONT_consolas_24_latin1_BITMAP_HEIGHT;

    static unsigned char fontpixels[fontHeight][fontWidth];

    stb_font_consolas_24_latin1(stbFontData, fontpixels, fontHeight);

    fontTexture.create(*device, commandPool, (void*)&fontpixels[0][0], static_cast<size_t>(fontWidth),
     static_cast<size_t>(fontHeight), static_cast<VkDeviceSize>(fontWidth*fontHeight), VK_FORMAT_R8_UNORM);

    // create the vertex buffer
    VkDeviceSize bufferSize = maxTextLength * sizeof(glm::vec4);
    Chronos::Engine::createBuffer(*device, bufferSize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        &vertexBuffer, &vertexBufferMemory);


    Chronos::Engine::Object::init(device, commandPool, swapChain, textureSampler, renderPass);
}

std::vector<VkDescriptorType> Chronos::Engine::Font::getDescriptorTypes()
{
    return std::vector<VkDescriptorType> {VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER,
        VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER };
}

std::vector<VkShaderStageFlagBits> Chronos::Engine::Font::getDescriptorStages()
{
    return std::vector<VkShaderStageFlagBits> {VK_SHADER_STAGE_FRAGMENT_BIT,
        VK_SHADER_STAGE_VERTEX_BIT};
}

void Chronos::Engine::Font::createDescriptorSets(){
    std::vector<VkDescriptorSetLayout> layouts(MAX_FRAMES_IN_FLIGHT,
        descriptorSetLayout);
    VkDescriptorSetAllocateInfo allocInfo {};
    allocInfo.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
    allocInfo.descriptorPool = descriptorPool;
    allocInfo.descriptorSetCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
    allocInfo.pSetLayouts = layouts.data();
    descriptorSets.resize(MAX_FRAMES_IN_FLIGHT);
    if (vkAllocateDescriptorSets(device->device, &allocInfo,
            descriptorSets.data())
        != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate descriptor sets!");
    }
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {

        VkDescriptorImageInfo imageInfo {};
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        imageInfo.imageView = fontTexture.textureImageView;
        imageInfo.sampler = textureSampler;

        VkDescriptorBufferInfo bufferInfo {};
        bufferInfo.buffer = uniformBuffers[i].buffer;
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(UniformBufferObject);
        VkWriteDescriptorSet descriptorWrite {};

        std::array<VkWriteDescriptorSet, 2> descriptorWrites {};

        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].dstSet = descriptorSets[i];
        descriptorWrites[0].dstBinding = 0;
        descriptorWrites[0].dstArrayElement = 0;
        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptorWrites[0].descriptorCount = 1;
        descriptorWrites[0].pImageInfo = &imageInfo;

        descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[1].dstSet = descriptorSets[i];
        descriptorWrites[1].dstBinding = 1;
        descriptorWrites[1].dstArrayElement = 0;
        descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrites[1].descriptorCount = 1;
        descriptorWrites[1].pBufferInfo = &bufferInfo;

        vkUpdateDescriptorSets(device->device,
            static_cast<uint32_t>(descriptorWrites.size()),
            descriptorWrites.data(), 0, nullptr);
    }

};

Chronos::Engine::PipelineAttributes Chronos::Engine::Font::getPipelineAttributes()
{
    PipelineAttributes pipelineAttributes;
    pipelineAttributes.bindingDescriptions = std::vector<VkVertexInputBindingDescription> {2};
    pipelineAttributes.bindingDescriptions[0].binding = 0;
    pipelineAttributes.bindingDescriptions[0].stride = sizeof(glm::vec4);
    pipelineAttributes.bindingDescriptions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    pipelineAttributes.bindingDescriptions[1].binding = 1;
    pipelineAttributes.bindingDescriptions[1].stride = sizeof(glm::vec4);
    pipelineAttributes.bindingDescriptions[1].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    pipelineAttributes.attributeDescriptions = std::vector<VkVertexInputAttributeDescription> {2};
    pipelineAttributes.attributeDescriptions[0].binding = 0;
    pipelineAttributes.attributeDescriptions[0].location = 0;
    pipelineAttributes.attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
    pipelineAttributes.attributeDescriptions[0].offset = 0;

    pipelineAttributes.attributeDescriptions[1].binding = 1;
    pipelineAttributes.attributeDescriptions[1].location = 1;
    pipelineAttributes.attributeDescriptions[1].format = VK_FORMAT_R32G32_SFLOAT;
    pipelineAttributes.attributeDescriptions[1].offset = sizeof(glm::vec2);

    pipelineAttributes.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
    pipelineAttributes.frontFace = VK_FRONT_FACE_CLOCKWISE;

    pipelineAttributes.colorBlendAttachment.blendEnable = VK_TRUE;
    pipelineAttributes.colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    pipelineAttributes.colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
    pipelineAttributes.colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
    pipelineAttributes.colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD;
    pipelineAttributes.colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA;
    pipelineAttributes.colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO;
    pipelineAttributes.colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD;

    return pipelineAttributes;
}

void Chronos::Engine::Font::destroy(){
    Chronos::Engine::Object::destroy();
    vkDestroyBuffer(device->device, vertexBuffer, nullptr);
    vkFreeMemory(device->device, vertexBufferMemory, nullptr);
    fontTexture.destroy();
}


void Chronos::Engine::Font::updateBuffer(){
if (vkMapMemory(device->device, vertexBufferMemory, 0, VK_WHOLE_SIZE, 0,
            (void**)&mappedMemory)
        != VK_SUCCESS) {
        throw std::runtime_error("failed to map memory!");
    }

        numLetters = 0;

    const uint32_t firstChar = STB_FONT_consolas_24_latin1_FIRST_CHAR;

    assert(mappedMemory != nullptr);

    const float charW = 1.5f * params.scale / swapChain->swapChainExtent.width;
    const float charH = 1.5f * params.scale / swapChain->swapChainExtent.height;

    float fbW = (float)swapChain->swapChainExtent.width;
    float fbH = (float)swapChain->swapChainExtent.height;
    float x = (0 / fbW * 2.0f);
    float y = (0 / fbH * 2.0f);

    // Calculate text width
    float textWidth = 0;
    for (auto letter : params.text) {
        stb_fontchar* charData = &stbFontData[(uint32_t)letter - firstChar];
        textWidth += charData->advance * charW;
    }
    // switch (alignment) {
    // case Right:
    //     x -= textWidth;
    //     break;
    // case Center:
        x -= textWidth / 2.0f;
    //     break;
    // case Left:
    //     break;
    // }

    // Generate a uv mapped quad per char in the new text
    for (auto letter : params.text) {
        stb_fontchar* charData = &stbFontData[(uint32_t)letter - firstChar];

        mappedMemory->x = (x + (float)charData->x0 * charW);
        mappedMemory->y = (y + (float)charData->y0 * charH);
        mappedMemory->z = charData->s0;
        mappedMemory->w = charData->t0;
        mappedMemory++;

        mappedMemory->x = (x + (float)charData->x1 * charW);
        mappedMemory->y = (y + (float)charData->y0 * charH);
        mappedMemory->z = charData->s1;
        mappedMemory->w = charData->t0;
        mappedMemory++;

        mappedMemory->x = (x + (float)charData->x0 * charW);
        mappedMemory->y = (y + (float)charData->y1 * charH);
        mappedMemory->z = charData->s0;
        mappedMemory->w = charData->t1;
        mappedMemory++;

        mappedMemory->x = (x + (float)charData->x1 * charW);
        mappedMemory->y = (y + (float)charData->y1 * charH);
        mappedMemory->z = charData->s1;
        mappedMemory->w = charData->t1;
        mappedMemory++;

        x += charData->advance * charW;
        numLetters++;

    }
    
    vkUnmapMemory(device->device, vertexBufferMemory);
    mappedMemory = nullptr;
}

void Chronos::Engine::Font::clear(){
    if (vkMapMemory(device->device, vertexBufferMemory, 0, VK_WHOLE_SIZE, 0,
            (void**)&mappedMemory)
        != VK_SUCCESS) {
        throw std::runtime_error("failed to map memory!");
    }
    numLetters = 0;
    mappedMemory = nullptr;

    vkUnmapMemory(device->device, vertexBufferMemory);
    mappedMemory = nullptr;
}

void Chronos::Engine::Font::update(uint32_t currentFrame){
    updateBuffer();
    uniformBuffers[currentFrame].update(swapChain->swapChainExtent, params.x, params.y, params.rotation - 90, 1.0f, -1.0f);
}
