#include "textManager.hpp"
#include "objectManagerDefs.hpp"
#include "font.hpp"

void Chronos::Engine::TextManager::createRenderPass(){
#ifdef ENABLE_EDITOR
    renderPass = Chronos::Engine::createRenderPass(
        *device, *swapChain, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, true, false, true);
#else
    renderPass = Chronos::Engine::createRenderPass(
        *device, *swapChain, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
        true, false, true);
#endif
}

void Chronos::Engine::TextManager::render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]){
    Chronos::Engine::ObjectManager<Chronos::Engine::Font>::render(currentFrame, imageIndex, bgColor);
    
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
    for (auto& object : objects) {
        vkCmdBindPipeline(commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS, object.second.graphicsPipeline);
        vkCmdSetViewport(commandBuffers[currentFrame], 0, 1, &viewport);
        vkCmdSetScissor(commandBuffers[currentFrame], 0, 1, &scissor);
        VkBuffer vertexBuffers[] = { object.second.vertexBuffer };
        VkDeviceSize offsets[] = { 0 };
        vkCmdBindVertexBuffers(commandBuffers[currentFrame], 0, 1, vertexBuffers,
            offsets);
        vkCmdBindVertexBuffers(commandBuffers[currentFrame], 1, 1, vertexBuffers,
            offsets);
        vkCmdBindDescriptorSets(commandBuffers[currentFrame],
            VK_PIPELINE_BIND_POINT_GRAPHICS, object.second.pipelineLayout, 0, 1,
            &object.second.descriptorSets[currentFrame], 0, nullptr);
        for (uint32_t j = 0; j < object.second.numLetters; j++) {
            vkCmdDraw(commandBuffers[currentFrame], 4, 1, j * 4, 0);
        }
    }
    Chronos::Engine::ObjectManager<Chronos::Engine::Font>::endRender(currentFrame);

}

int Chronos::Engine::TextManager::addFont(Chronos::Engine::Font font){
    font.init(device, commandPool, swapChain, textureSampler, &renderPass);
    return Chronos::Engine::ObjectManager<Chronos::Engine::Font>::addObject(font);
}

void Chronos::Engine::TextManager::remove(int fontNo){
    Chronos::Engine::ObjectManager<Chronos::Engine::Font>::remove(fontNo);
}