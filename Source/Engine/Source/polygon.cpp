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
#include "polygon_triangulation.h"

void Chronos::Engine::Polygon::init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
VkSampler textureSampler, Chronos::Engine::Texture texture, VkRenderPass* renderPass, std::vector<std::array<float, 2>> vertices){
    this->vertexShaderPath = SPIV_SHADER_PATH"/textureVert.spv";
    this->fragmentShaderPath = SPIV_SHADER_PATH"/textureFrag.spv";
    this->texture = texture;

    const uint32_t nvertices = vertices.size();
    std::vector<vertex_t> polytriVertices;
    for (auto& vertex : vertices) {
        vertex_t v;
        v.x = vertex[0];
        v.y = vertex[1];
        polytriVertices.push_back(v);
        TexturedVertex tv = {{vertex[0], vertex[1]}, {0.0f, 0.0f}};
        this->vertices.push_back(tv);
    }
    PolygonTriangulation::TriangleBuffer_t triangles;
    PolygonTriangulation::Triangulate(1, &nvertices, polytriVertices.data(), triangles);
    for (auto& t : triangles) {
        indices.push_back(t.v0);
        indices.push_back(t.v1);
        indices.push_back(t.v2);
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