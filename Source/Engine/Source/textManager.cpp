#include "textManager.hpp"
#include "font.hpp"

void Chronos::Engine::TextManager::init(Chronos::Engine::Device* device, Chronos::Engine::SwapChain* swapChain, VkCommandPool commandPool){
    Chronos::Engine::ObjectManager<Chronos::Engine::Font>::init(device, swapChain, commandPool);

    



}

void Chronos::Engine::TextManager::createRenderPass(){
#ifdef DISPLAY_IMGUI
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