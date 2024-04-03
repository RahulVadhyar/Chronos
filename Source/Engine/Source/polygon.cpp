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

#include "stlheader.hpp"
#include "vulkanHeaders.hpp"
#include "device.hpp"
#include "swapchain.hpp"
#include "helper.hpp"
#include "buffers.hpp"
#include "Vertex.hpp"
#include "engineStructs.hpp"
#include "commonStructs.hpp"
#include "object.hpp"
#include "texture.hpp"
#include "polygon.hpp"
#include "earcut.hpp"

void Chronos::Engine::Polygon::init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
VkSampler textureSampler, Chronos::Engine::Texture texture, VkRenderPass* renderPass, std::vector<std::array<float, 2>> vertices){
    this->vertexShaderPath = SPIV_SHADER_PATH"/textureVert.spv";
    this->fragmentShaderPath = SPIV_SHADER_PATH"/textureFrag.spv";
    this->texture = texture;

    //we copy the vertices to the vertex struct. For the texture cooring we use the same vertex coordinates, but we map them to the range [0, 1] from [-1, 1]
    for (auto& vertex : vertices) {
        TexturedVertex tv = {{vertex[0], vertex[1]}, {(vertex[0] + 1.0f)/2.0f, (vertex[1] + 1.0f)/2.0f}};
        this->vertices.push_back(tv);
    }

    //we use the earcut library to triangulate the polygon and generate the indicies
    std::vector<uint32_t> triangleIndices = mapbox::earcut<uint32_t>(std::array<std::vector<std::array<float, 2>>, 2>{vertices, {}});
    for (uint32_t i = 0; i < triangleIndices.size(); i++){
        if(triangleIndices[i] >= vertices.size()){
            throw std::runtime_error("Index" + std::to_string(triangleIndices[i]) + " out of range");
        }
        this->indices.push_back(triangleIndices[i]);
    }

    Chronos::Engine::Object::init(device, commandPool, swapChain, textureSampler, renderPass);

    // create the vertex and index buffers and copy the data

    polygonVertexBuffers.resize(MAX_FRAMES_IN_FLIGHT);
    for (auto& buffer : polygonVertexBuffers){
        buffer.size = sizeof(this->vertices[0]) * this->vertices.size();
        buffer.create(*device,
            VK_BUFFER_USAGE_VERTEX_BUFFER_BIT,
            VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT); //we use host visible and coherent memory to be able to map it and to edit the vertiuces
        copyVerticestoBuffer(buffer);
    }
    copyVertices.resize(MAX_FRAMES_IN_FLIGHT, false);

    indexBuffer.size = sizeof(this->indices[0]) * this->indices.size();
    indexBuffer.create(*device,
        VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT,
        VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT); //inidcies will not change
    indexBuffer.copy(this->indices.data(), commandPool);
    
}

void Chronos::Engine::Polygon::copyVerticestoBuffer(Chronos::Engine::Buffer vertexBuffer){
    if(vkMapMemory(device->device, vertexBuffer.memory, 0, VK_WHOLE_SIZE, 0, &this->mappedMemory)
        != VK_SUCCESS){
        throw std::runtime_error("Failed to map memory");
    }
    if(this->mappedMemory == nullptr){
        throw std::runtime_error("Memory not mapped, current address is " + std::to_string((uint64_t)this->mappedMemory));
    }
    memcpy(this->mappedMemory, this->vertices.data(), (size_t)vertexBuffer.size);
    vkUnmapMemory(device->device, vertexBuffer.memory);
}

void Chronos::Engine::Polygon::updateVertices(std::vector<std::array<float, 2>>vertices){
    //There are a vertex buffer, one for each frame in flight. We need to update all of them
    //however, some of them may be in use, hence we just set bools correspoding to each buffer to true
    //on update of the frame, we will copy the vertices to the buffer if the bool is true for that frame
    assert(vertices.size() == this->vertices.size());
    this->vertices.clear();
    for (auto& vertex : vertices) {
        TexturedVertex tv = {{vertex[0], vertex[1]}, {(vertex[0] + 1.0f)/2.0f, (vertex[1] + 1.0f)/2.0f}};
        this->vertices.push_back(tv);
    }
    for(int i = 0; i < copyVertices.size(); i++){
        copyVertices[i] = true;
    }
}

void Chronos::Engine::Polygon::update(uint32_t currentFrame){
    if (copyVertices[currentFrame]){
        copyVerticestoBuffer(polygonVertexBuffers[currentFrame]);
        copyVertices[currentFrame] = false;
    }
    uniformBuffers[currentFrame].update(swapChain->swapChainExtent, params.x,
        params.y, params.rotation, params.xSize,
        params.ySize);
}

void Chronos::Engine::Polygon::destroy(){
    for (auto& buffer : polygonVertexBuffers){
        buffer.destroy();
    }
    indexBuffer.destroy();
    Chronos::Engine::Object::destroy();
}

void Chronos::Engine::Polygon::createDescriptorSets(){
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

std::vector<VkDescriptorType> Chronos::Engine::Polygon::getDescriptorTypes(){
    return {VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER};
}

std::vector<VkShaderStageFlagBits> Chronos::Engine::Polygon::getDescriptorStages(){
    return {VK_SHADER_STAGE_VERTEX_BIT, VK_SHADER_STAGE_FRAGMENT_BIT};
}

Chronos::Engine::PipelineAttributes Chronos::Engine::Polygon::getPipelineAttributes(){
    Chronos::Engine::PipelineAttributes pipelineAttributes;

    auto bindingDescription = TexturedVertex::getBindingDescription();
    auto attributeDescriptions = TexturedVertex::getAttributeDescriptions();

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