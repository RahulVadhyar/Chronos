#include "font.hpp"
#include "stb_font_consolas_24_latin1.inl"

Chronos::Engine::Font::init(){
    vertexShaderPath = "ThirdParty/Chronos/Shaders/textVert.spv";
    fragmentShaderPath = "ThirdParty/Chronos/Shaders/textFrag.spv";

    Chronos::Engine::Object::init(device, commandPool, swapChain, textureSampler, renderPass);

    // initalize the font
    const uint32_t fontWidth = STB_FONT_consolas_24_latin1_BITMAP_WIDTH;
    const uint32_t fontHeight = STB_FONT_consolas_24_latin1_BITMAP_HEIGHT;

    static unsigned char fontpixels[fontHeight][fontWidth];
    stb_font_consolas_24_latin1(stbFontData, fontpixels, fontHeight);

    // create the vertex buffer
    VkDeviceSize bufferSize = maxTextLength * sizeof(glm::vec4);
    Chronos::Engine::createBuffer(*device, bufferSize, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
        &vertexBuffer, &vertexBufferMemory);

    fontTexture.create(*device, commandPool, (void*)&fontpixels[0][0], static_cast<size_t>(fontWidth),
     static_cast<size_t>(fontHeight), static_cast<VkDeviceSize>(fontWidth*fontHeight), VK_FORMAT_R8_UNORM);

createDescriptorSets();
}

std::vector<VkDescriptorType> Chronos::Engine::Font::getDescriptorTypes()
{
    return std::vector<VkDescriptorType> {VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER };
}

std::vector<VkShaderStageFlagBits> Chronos::Engine::Font::getDescriptorStages()
{
    return std::vector<VkShaderStageFlagBits> {VK_SHADER_STAGE_FRAGMENT_BIT};
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

        std::array<VkWriteDescriptorSet, 1> descriptorWrites {};

        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].dstSet = descriptorSets[i];
        descriptorWrites[0].dstBinding = 0;
        descriptorWrites[0].dstArrayElement = 0;
        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptorWrites[0].descriptorCount = 1;
        descriptorWrites[0].pImageInfo = &imageInfo;

        vkUpdateDescriptorSets(device->device,
            static_cast<uint32_t>(descriptorWrites.size()),
            descriptorWrites.data(), 0, nullptr);
    }

};

Chronos::Engine::PipelineAttributes Chronos::Engine::Font::getPipelineAttributes()
{
    PipelineAttributes pipelineAttributes;
    pipelineAttributes.bindingDescriptions = std::vector<VkVertexInputBindingDescription> [2];
    pipelineAttributes.bindingDescriptions[0].binding = 0;
    pipelineAttributes.bindingDescriptions[0].stride = sizeof(glm::vec4);
    pipelineAttributes.bindingDescriptions[0].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    pipelineAttributes.bindingDescriptions[1].binding = 1;
    pipelineAttributes.bindingDescriptions[1].stride = sizeof(glm::vec4);
    pipelineAttributes.bindingDescriptions[1].inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

    pipelineAttributes.attributeDescriptions = std::vector<VkVertexInputAttributeDescription> [2];
    pipelineAttributes.attributeDescriptions[0].binding = 0;
    pipelineAttributes.attributeDescriptions[0].location = 0;
    pipelineAttributes.attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
    pipelineAttributes.attributeDescriptions[0].offset = 0;

    pipelineAttributes.attributeDescriptions[1].binding = 1;
    pipelineAttributes.attributeDescriptions[1].location = 1;
    pipelineAttributes.attributeDescriptions[1].format = VK_FORMAT_R32G32_SFLOAT;
    pipelineAttributes.attributeDescriptions[1].offset = 0;

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