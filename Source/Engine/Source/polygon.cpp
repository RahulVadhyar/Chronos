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
#include "shape.hpp"
#include "polygon.hpp"
#include "earcut.hpp"
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

void Chronos::Engine::Polygon::init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
VkSampler textureSampler, Chronos::Engine::Texture texture, VkRenderPass* renderPass, std::vector<std::array<float, 2>> vertices){
    this->vertexShaderPath = SPIV_SHADER_PATH"/textureVert.spv";
    this->fragmentShaderPath = SPIV_SHADER_PATH"/textureFrag.spv";
    this->texture = texture;


    for (auto& vertex : vertices) {
        TexturedVertex tv = {{vertex[0], vertex[1]}, {0.0f, 0.0f}};
        this->vertices.push_back(tv);
    }
    std::vector<uint32_t> triangleIndices = mapbox::earcut<uint32_t>(std::array<std::vector<std::array<float, 2>>, 2>{vertices, {}});
    for (uint32_t i = 0; i < triangleIndices.size(); i++){
        if(triangleIndices[i] >= vertices.size()){
            throw std::runtime_error("Index" + std::to_string(triangleIndices[i]) + " out of range");
        }
        this->indices.push_back(triangleIndices[i]);
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