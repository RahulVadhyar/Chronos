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

#include "vulkanHeaders.hpp"

#include "device.hpp"
#include "swapchain.hpp"
#include "buffers.hpp"
#include "helper.hpp"
#include "texture.hpp"
#include "object.hpp"
#include "objectManager.hpp"
#include "commonStructs.hpp"
#include "engineStructs.hpp"
#include "text.hpp"
#include "textManager.hpp"

void Chronos::Engine::TextManager::createRenderPass()
{
#ifdef ENABLE_EDITOR
    renderPass = Chronos::Engine::createRenderPass(*device, *swapChain,
	VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
	VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
	VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL, true, false, true);
#else
    renderPass = Chronos::Engine::createRenderPass(*device, *swapChain,
	VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
	VK_IMAGE_LAYOUT_PRESENT_SRC_KHR,
	VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, true, false, true);
#endif
}

void Chronos::Engine::TextManager::render(
    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3])
{
    Chronos::Engine::ObjectManager<Chronos::Engine::Text>::render(
	currentFrame, imageIndex, bgColor);

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
	if (this->objectsToBeRemoved.count(object.first) > 0)
	    continue;
	vkCmdBindPipeline(commandBuffers[currentFrame],
	    VK_PIPELINE_BIND_POINT_GRAPHICS, object.second.graphicsPipeline);
	vkCmdSetViewport(commandBuffers[currentFrame], 0, 1, &viewport);
	vkCmdSetScissor(commandBuffers[currentFrame], 0, 1, &scissor);
	VkBuffer vertexBuffers[] = { object.second.vertexBuffer };
	VkDeviceSize offsets[] = { 0 };
	vkCmdBindVertexBuffers(
	    commandBuffers[currentFrame], 0, 1, vertexBuffers, offsets);
	vkCmdBindVertexBuffers(
	    commandBuffers[currentFrame], 1, 1, vertexBuffers, offsets);
	vkCmdBindDescriptorSets(commandBuffers[currentFrame],
	    VK_PIPELINE_BIND_POINT_GRAPHICS, object.second.pipelineLayout, 0, 1,
	    &object.second.descriptorSets[currentFrame], 0, nullptr);
	for (uint32_t j = 0; j < object.second.numLetters; j++) {
	    vkCmdDraw(commandBuffers[currentFrame], 4, 1, j * 4, 0);
	}
    }
    Chronos::Engine::ObjectManager<Chronos::Engine::Text>::endRender(
	currentFrame);
}

int Chronos::Engine::TextManager::addFont(
    Chronos::Engine::Text font, Chronos::Engine::FontTypes fontStyle)
{
    font.init(
	device, commandPool, swapChain, textureSampler, &renderPass, fontStyle);
    return Chronos::Engine::ObjectManager<Chronos::Engine::Text>::addObject(
	font);
}

void Chronos::Engine::TextManager::remove(int fontNo)
{
    if (objects.count(fontNo) == 0) {
	throw std::runtime_error("Font does not exist");
    }
    Chronos::Engine::ObjectManager<Chronos::Engine::Text>::remove(fontNo);
}
