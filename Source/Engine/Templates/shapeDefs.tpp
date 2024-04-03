/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once
template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::init(Chronos::Engine::Device* device, VkCommandPool commandPool,
    SwapChain* swapChain, VkSampler textureSampler,
    Chronos::Engine::Texture texture, VkRenderPass* renderPass)
    requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    this->vertexShaderPath = SPIV_SHADER_PATH"/textureVert.spv";
    this->fragmentShaderPath = SPIV_SHADER_PATH"/textureFrag.spv";
    this->texture = texture;

    Chronos::Engine::Object::init(device, commandPool, swapChain, textureSampler, renderPass);

    // create the vertex and index buffers and copy the data
    vertexBuffer.size = sizeof(vertices[0]) * vertices.size();
    vertexBuffer.create(*device,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    vertexBuffer.copy(vertices.data(), commandPool);

    indexBuffer.size = sizeof(indices[0]) * indices.size();
    indexBuffer.create(*device,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    indexBuffer.copy(indices.data(), commandPool);
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
    VkRenderPass* renderPass,  VkSampler textureSampler)
    requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{

    this->vertexShaderPath = SPIV_SHADER_PATH"/colorVert.spv";
    this->fragmentShaderPath = SPIV_SHADER_PATH"/colorFrag.spv";

    colorBuffers.resize(MAX_FRAMES_IN_FLIGHT);
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        colorBuffers[i].create(*device);
    }

    Chronos::Engine::Object::init(device, commandPool, swapChain, textureSampler, renderPass);

    // create the vertex and index buffers and copy the data
    vertexBuffer.size = sizeof(vertices[0]) * vertices.size();
    vertexBuffer.create(*device,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    vertexBuffer.copy(vertices.data(), commandPool);

    indexBuffer.size = sizeof(indices[0]) * indices.size();
    indexBuffer.create(*device,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    indexBuffer.copy(indices.data(), commandPool);
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::tempDestroy()
    requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    vertexBuffer.destroy();
    indexBuffer.destroy();
    Chronos::Engine::Object::destroy();
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::tempDestroy()
    requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
    vertexBuffer.destroy();
    indexBuffer.destroy();
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        colorBuffers[i].destroy();
    }
    Chronos::Engine::Object::destroy();
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::tempCreateDescriptorSets()
    requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
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
        VkDescriptorBufferInfo bufferInfo {};
        bufferInfo.buffer = uniformBuffers[i].buffer;
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(UniformBufferObject);
        VkWriteDescriptorSet descriptorWrite {};

        VkDescriptorImageInfo imageInfo {};
        imageInfo.imageLayout = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL;
        imageInfo.imageView = texture.textureImageView;
        imageInfo.sampler = textureSampler;

        std::array<VkWriteDescriptorSet, 2> descriptorWrites {};

        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].dstSet = descriptorSets[i];
        descriptorWrites[0].dstBinding = 0;
        descriptorWrites[0].dstArrayElement = 0;
        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrites[0].descriptorCount = 1;
        descriptorWrites[0].pBufferInfo = &bufferInfo;

        descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[1].dstSet = descriptorSets[i];
        descriptorWrites[1].dstBinding = 1;
        descriptorWrites[1].dstArrayElement = 0;
        descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descriptorWrites[1].descriptorCount = 1;
        descriptorWrites[1].pImageInfo = &imageInfo;

        vkUpdateDescriptorSets(device->device,
            static_cast<uint32_t>(descriptorWrites.size()),
            descriptorWrites.data(), 0, nullptr);
    }
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::tempCreateDescriptorSets()
    requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
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
        VkDescriptorBufferInfo bufferInfo {};
        bufferInfo.buffer = uniformBuffers[i].buffer;
        bufferInfo.offset = 0;
        bufferInfo.range = sizeof(UniformBufferObject);

        VkDescriptorBufferInfo bufferInfo2 {};
        bufferInfo2.buffer = colorBuffers[i].buffer;
        bufferInfo2.offset = 0;
        bufferInfo2.range = sizeof(UniformColorBufferObject);

        std::array<VkWriteDescriptorSet, 2> descriptorWrites {};

        descriptorWrites[0].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[0].dstSet = descriptorSets[i];
        descriptorWrites[0].dstBinding = 0;
        descriptorWrites[0].dstArrayElement = 0;
        descriptorWrites[0].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrites[0].descriptorCount = 1;
        descriptorWrites[0].pBufferInfo = &bufferInfo;

        descriptorWrites[1].sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
        descriptorWrites[1].dstSet = descriptorSets[i];
        descriptorWrites[1].dstBinding = 1;
        descriptorWrites[1].dstArrayElement = 0;
        descriptorWrites[1].descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
        descriptorWrites[1].descriptorCount = 1;
        descriptorWrites[1].pBufferInfo = &bufferInfo2;

        vkUpdateDescriptorSets(device->device,
            static_cast<uint32_t>(descriptorWrites.size()),
            descriptorWrites.data(), 0, nullptr);
    }
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::tempUpdate(uint32_t currentFrame)
    requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    uniformBuffers[currentFrame].update(swapChain->swapChainExtent, params.x,
        params.y, params.rotation, params.xSize,
        params.ySize);
}

template <Chronos::Engine::VertexLike VertexStruct>
void Chronos::Engine::Shape<VertexStruct>::tempUpdate(uint32_t currentFrame)
    requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
    uniformBuffers[currentFrame].update(swapChain->swapChainExtent, params.x,
        params.y, params.rotation, params.xSize,
        params.ySize);
    colorBuffers[currentFrame].update({ params.color[0], params.color[1], params.color[2] });
}

template <Chronos::Engine::VertexLike VertexStruct>
std::vector<VkDescriptorType> Chronos::Engine::Shape<VertexStruct>::tempGetDescriptorTypes()
    requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    return std::vector<VkDescriptorType> { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER,
        VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER };
}

template <Chronos::Engine::VertexLike VertexStruct>
std::vector<VkDescriptorType> Chronos::Engine::Shape<VertexStruct>::tempGetDescriptorTypes()
    requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
    return std::vector<VkDescriptorType> { VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER };
}

template <Chronos::Engine::VertexLike VertexStruct>
std::vector<VkShaderStageFlagBits> Chronos::Engine::Shape<VertexStruct>::tempGetDescriptorStages()
    requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
{
    return std::vector<VkShaderStageFlagBits> { VK_SHADER_STAGE_VERTEX_BIT,
        VK_SHADER_STAGE_FRAGMENT_BIT };
}

template <Chronos::Engine::VertexLike VertexStruct>
std::vector<VkShaderStageFlagBits> Chronos::Engine::Shape<VertexStruct>::tempGetDescriptorStages()
    requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
{
    return std::vector<VkShaderStageFlagBits> { VK_SHADER_STAGE_VERTEX_BIT, VK_SHADER_STAGE_FRAGMENT_BIT };
}

template <Chronos::Engine::VertexLike VertexStruct>
Chronos::Engine::PipelineAttributes Chronos::Engine::Shape<VertexStruct>::getPipelineAttributes()
{
    Chronos::Engine::PipelineAttributes pipelineAttributes;

    auto bindingDescription = VertexStruct::getBindingDescription();
    auto attributeDescriptions = VertexStruct::getAttributeDescriptions();

    pipelineAttributes.bindingDescriptions.resize(1);
    pipelineAttributes.bindingDescriptions[0] = bindingDescription;

    pipelineAttributes.attributeDescriptions.resize(attributeDescriptions.size());
    for (int i = 0; i < attributeDescriptions.size(); i++) {
        pipelineAttributes.attributeDescriptions[i] = attributeDescriptions[i];
    }

    pipelineAttributes.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
    pipelineAttributes.frontFace = VK_FRONT_FACE_COUNTER_CLOCKWISE;

    pipelineAttributes.colorBlendAttachment.colorWriteMask = VK_COLOR_COMPONENT_R_BIT | VK_COLOR_COMPONENT_G_BIT | VK_COLOR_COMPONENT_B_BIT | VK_COLOR_COMPONENT_A_BIT;
    pipelineAttributes.colorBlendAttachment.blendEnable = VK_FALSE;
    pipelineAttributes.colorBlendAttachment.srcColorBlendFactor = VK_BLEND_FACTOR_ONE;
    pipelineAttributes.colorBlendAttachment.dstColorBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
    pipelineAttributes.colorBlendAttachment.colorBlendOp = VK_BLEND_OP_ADD; // Optional
    pipelineAttributes.colorBlendAttachment.srcAlphaBlendFactor = VK_BLEND_FACTOR_ONE; // Optional
    pipelineAttributes.colorBlendAttachment.dstAlphaBlendFactor = VK_BLEND_FACTOR_ZERO; // Optional
    pipelineAttributes.colorBlendAttachment.alphaBlendOp = VK_BLEND_OP_ADD; // Optional

    return pipelineAttributes;
}
