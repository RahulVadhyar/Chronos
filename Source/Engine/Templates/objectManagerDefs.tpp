#pragma once
template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::init(Chronos::Engine::Device* device, SwapChain* swapChain,
    VkCommandPool commandPool)
{
    this->device = device;
    this->swapChain = swapChain;
    this->commandPool = commandPool;

    Chronos::Engine::createTextureSampler(*device, &textureSampler);

    createRenderPass();
    commandBuffers = Chronos::Engine::createCommandBuffer(*device, *swapChain, commandPool);
    framebuffers = Chronos::Engine::createFramebuffer(*device, *swapChain, renderPass, true);
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::destroy()
{
    vkDestroySampler(device->device, textureSampler, nullptr);
    vkDestroyRenderPass(device->device, renderPass, nullptr);
    for (auto framebuffer : framebuffers)
        vkDestroyFramebuffer(device->device, framebuffer, nullptr);
    for (auto& objectMap : objects) {
        objectMap.second.destroy();
    }
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::render(uint32_t currentFrame, uint32_t imageIndex,
    float bgColor[3])
{
    vkResetCommandBuffer(commandBuffers[currentFrame], 0);
    VkCommandBufferBeginInfo beginInfo {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    if (vkBeginCommandBuffer(commandBuffers[currentFrame], &beginInfo) != VK_SUCCESS) {
        throw std::runtime_error("failed to begin recording command buffer!");
    }

    VkRenderPassBeginInfo renderPassInfo {};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = renderPass;
    renderPassInfo.framebuffer = framebuffers[imageIndex];
    renderPassInfo.renderArea.offset = { 0, 0 };
    renderPassInfo.renderArea.extent = swapChain->swapChainExtent;
    VkClearValue clearColor = { bgColor[0], bgColor[1], bgColor[2],
        1.0f }; // bg color
    renderPassInfo.clearValueCount = 1;
    renderPassInfo.pClearValues = &clearColor;

    vkCmdBeginRenderPass(commandBuffers[currentFrame], &renderPassInfo,
        VK_SUBPASS_CONTENTS_INLINE);
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::endRender(uint32_t currentFrame)
{
    vkCmdEndRenderPass(commandBuffers[currentFrame]);

    if (vkEndCommandBuffer(commandBuffers[currentFrame]) != VK_SUCCESS) {
        throw std::runtime_error("failed to record command buffer!");
    }
}
template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::changeMsaa()
{
    vkDestroyRenderPass(device->device, renderPass, nullptr);
    renderPass = Chronos::Engine::createRenderPass(*device, *swapChain, VK_IMAGE_LAYOUT_UNDEFINED,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, true,
        true, false);
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::cleanup()
{
    for (auto framebuffer : framebuffers)
        vkDestroyFramebuffer(device->device, framebuffer, nullptr);
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::recreate()
{
    cleanup();
    framebuffers = createFramebuffer(*device, *swapChain, renderPass, true);
}

template <Chronos::Engine::ObjectLike Object>
int Chronos::Engine::ObjectManager<Object>::addObject(Object object)
{
    int objectNo = nextFreeObjectNo;
    nextFreeObjectNo++;
    objects[objectNo] = object;
    return objectNo;
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::remove(int objectNo)
{
    objects[objectNo].destroy();
    objects.erase(objectNo);
}

template <Chronos::Engine::ObjectLike Object>
void Chronos::Engine::ObjectManager<Object>::update(uint32_t currentFrame)
{
    for (auto& objectMap : objects) {
        objectMap.second.update(currentFrame);
    }
}