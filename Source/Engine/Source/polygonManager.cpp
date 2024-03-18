#include "stlheader.hpp"
#include "vulkanHeaders.hpp"
#include "device.hpp"
#include "swapchain.hpp"
#include "buffers.hpp"
#include "helper.hpp"
#include "texture.hpp"
#include "Vertex.hpp"
#include "object.hpp"
#include "objectManager.hpp"
#include "polygon.hpp"
#include "polygonManager.hpp"

void Chronos::Engine::PolygonManager::render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]){
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
    for (auto& shape : objects) {
        vkCmdBindPipeline(commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS, shape.second.graphicsPipeline);
        vkCmdSetViewport(commandBuffers[currentFrame], 0, 1, &viewport);
        vkCmdSetScissor(commandBuffers[currentFrame], 0, 1, &scissor);
        VkBuffer vertexBuffers[] = { shape.second.vertexBuffer.buffer };
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffers[currentFrame], 0, 1, vertexBuffers,
            offsets);
        vkCmdBindIndexBuffer(commandBuffers[currentFrame], shape.second.indexBuffer.buffer,
            0, VK_INDEX_TYPE_UINT16);
        vkCmdBindDescriptorSets(commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS,
            shape.second.pipelineLayout, 0, 1,
            &shape.second.descriptorSets[currentFrame], 0, nullptr);
        vkCmdDrawIndexed(commandBuffers[currentFrame],
            static_cast<uint32_t>(shape.second.indices.size()), 1, 0, 0, 0);
    }
    endRender(currentFrame);
}

void Chronos::Engine::PolygonManager::createRenderPass(){
    /*
   For the render pass the formats are as follows:
           initial - undefined; this is due to the fact that image is cleared
           final(color and msaa) - color attachment optimal; this is due to the
   fact that the image going to next renderpass(Text) Also we are clearing the
   framebuffer
   */
    this->renderPass = Chronos::Engine::createRenderPass(*device, *swapChain,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, true,
        false, false);
}