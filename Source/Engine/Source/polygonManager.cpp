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
#include "objectManager.hpp"
#include "polygonManager.hpp"
void Chronos::Engine::PolygonManager::render(uint32_t currentFrame, uint32_t imageIndex,
    float bgColor[3])
{
    Chronos::Engine::ObjectManager<Chronos::Engine::Polygon>::render(currentFrame, imageIndex, bgColor);

    VkViewport viewport {};
    viewport.x = 0.0f;
    viewport.y = 0.0f;
    viewport.width = static_cast<float>(swapChain->swapChainExtent.width);
    viewport.height = static_cast<float>(swapChain->swapChainExtent.height);
    viewport.minDepth = 0.0f;
    viewport.maxDepth = 1.0f;

    VkRect2D scissor {};
    scissor.offset = { 0, 0 };
    scissor.extent = swapChain->swapChainExtent;

    // render the shapes
    for (auto& polygon : objects) {
        if(this->objectsToBeRemoved.count(polygon.first) > 0) continue;
        vkCmdBindPipeline(commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS, polygon.second.graphicsPipeline);
        vkCmdSetViewport(commandBuffers[currentFrame], 0, 1, &viewport);
        vkCmdSetScissor(commandBuffers[currentFrame], 0, 1, &scissor);
        VkBuffer vertexBuffers[] = { polygon.second.polygonVertexBuffers[currentFrame].buffer }; //note that we have multiple vertex buffers
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffers[currentFrame], 0, 1, vertexBuffers,
            offsets);
        vkCmdBindIndexBuffer(commandBuffers[currentFrame], polygon.second.indexBuffer.buffer,
            0, VK_INDEX_TYPE_UINT16);
        vkCmdBindDescriptorSets(commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            polygon.second.pipelineLayout, 0, 1,
            &polygon.second.descriptorSets[currentFrame], 0, nullptr);
        vkCmdDrawIndexed(commandBuffers[currentFrame],
            static_cast<uint32_t>(polygon.second.indices.size()), 1, 0, 0, 0);
    }
    endRender(currentFrame);
}

int Chronos::Engine::PolygonManager::addPolygon(Chronos::Manager::ShapeParams shapeParams, std::vector<std::array<float, 2>> vertices, 
            Chronos::Engine::Texture texture)
{
    Chronos::Engine::Polygon polygon;
    polygon.init(device, commandPool, swapChain, textureSampler, texture, &renderPass, 
        vertices);
    int shapeNo = Chronos::Engine::ObjectManager<Chronos::Engine::Polygon>::addObject(polygon);
    objects[shapeNo].params = shapeParams;
    return shapeNo;
}

void Chronos::Engine::PolygonManager::createRenderPass()
{
    renderPass = Chronos::Engine::createRenderPass(*device, *swapChain,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, true,
        false, false);
}

