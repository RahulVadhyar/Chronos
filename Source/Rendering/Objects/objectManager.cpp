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

#include "objectManager.hpp"
#include "helper.hpp"
#include "texture.hpp"
#include "ColoredRectangle.hpp"
#include "TexturedRectangle.hpp"
#include "text.hpp"
void Chronos::Engine::ObjectManager::init(Chronos::Engine::Device* device,
    Chronos::Engine::SwapChain* swapChain, VkCommandPool commandPool)
{
    this->device = device;
    this->swapChain = swapChain;
    this->commandPool = commandPool;

    Chronos::Engine::createTextureSampler(*device, &textureSampler);

    this->renderPass
	= Chronos::Engine::createRenderPass(*this->device, *this->swapChain,
	    VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
	    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, true, true, false);
    commandBuffers = Chronos::Engine::createCommandBuffer(
	*device, *swapChain, commandPool);
    framebuffers = Chronos::Engine::createFramebuffer(
	*device, *swapChain, renderPass, true);
}
void Chronos::Engine::ObjectManager::destroy()
{
    vkDestroySampler(device->device, textureSampler, nullptr);
    vkDestroyRenderPass(device->device, renderPass, nullptr);
    for (auto framebuffer : framebuffers)
	vkDestroyFramebuffer(device->device, framebuffer, nullptr);
    for (auto& objectMap : objects) {
	objectMap.second->destroy();
    }
}
void Chronos::Engine::ObjectManager::render(
    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3])
{
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

    vkResetCommandBuffer(commandBuffers[currentFrame], 0);
    VkCommandBufferBeginInfo beginInfo {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    if (vkBeginCommandBuffer(commandBuffers[currentFrame], &beginInfo)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to begin recording command buffer!");
    }

    VkRenderPassBeginInfo renderPassInfo {};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassInfo.renderPass = renderPass;
    renderPassInfo.framebuffer = framebuffers[imageIndex];
    renderPassInfo.renderArea.offset = { 0, 0 };
    renderPassInfo.renderArea.extent = swapChain->swapChainExtent;
    VkClearValue clearColor
	= { { { bgColor[0], bgColor[1], bgColor[2], 1.0f } } }; // bg color
    renderPassInfo.clearValueCount = 1;
    renderPassInfo.pClearValues = &clearColor;

    vkCmdBeginRenderPass(commandBuffers[currentFrame], &renderPassInfo,
	VK_SUBPASS_CONTENTS_INLINE);

    for (auto& object : this->objects) {
	if (this->objectsToBeRemoved.count(object.first) > 0)
	    continue;
	object.second->render(currentFrame, imageIndex, bgColor, viewport,
	    scissor, commandBuffers);
    }

    vkCmdEndRenderPass(commandBuffers[currentFrame]);

    if (vkEndCommandBuffer(commandBuffers[currentFrame]) != VK_SUCCESS) {
	throw std::runtime_error("failed to record command buffer!");
    }
}
void Chronos::Engine::ObjectManager::changeMsaa()
{
    vkDestroyRenderPass(device->device, renderPass, nullptr);
    this->renderPass
	= Chronos::Engine::createRenderPass(*this->device, *this->swapChain,
	    VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
	    VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, true, true, false);
    recreate();
    for (auto& objectMap : objects) {
	objectMap.second->recreateGraphicsPipeline();
    }
}
void Chronos::Engine::ObjectManager::recreate()
{
    cleanup();
    framebuffers = createFramebuffer(*device, *swapChain, renderPass, true);
}
void Chronos::Engine::ObjectManager::cleanup()
{
    for (auto framebuffer : framebuffers)
	vkDestroyFramebuffer(device->device, framebuffer, nullptr);
}

int Chronos::Engine::ObjectManager::addObject(Object* object)
{
    int objectNo = nextFreeObjectNo;
    nextFreeObjectNo++;
    objects[objectNo] = object;
    return objectNo;
}
void Chronos::Engine::ObjectManager::remove(int objectNo)
{
    for (bool& flag : objectsToBeRemoved[objectNo]) {
	flag = true;
    }
}
void Chronos::Engine::ObjectManager::update(uint32_t currentFrame)
{
    for (auto& objectMap : objectsToBeRemoved) {
	objectMap.second[currentFrame] = false;
	bool toBeRemoved = true;
	for (bool flag : objectMap.second) {
	    if (flag) {
		toBeRemoved = false;
		break;
	    }
	}
	if (toBeRemoved) {
	    objects[objectMap.first]->destroy();
	    objectsToBeRemoved.erase(objectMap.first);
	    objects.erase(objectMap.first);
	    Object* object = objects[objectMap.first];
	    switch (object->objectType) {
	    case Chronos::Engine::ObjectType::TypeColoredRectangle:
		delete (Chronos::Engine::ColoredRectangle*)object;
		break;
	    case Chronos::Engine::ObjectType::TypeTexturedRectangle:
		delete (Chronos::Engine::TexturedRectangle*)object;
		break;
	    case Chronos::Engine::ObjectType::TypeText:
		delete (Chronos::Engine::Text*)object;
		break;
	    default:
		throw std::runtime_error("Invalid object type");
	    }
	}
    }
    for (auto& objectMap : objects) {
	if (objectsToBeRemoved.count(objectMap.first) == 0) {
	    objectMap.second->update(currentFrame);
	}
    }
}