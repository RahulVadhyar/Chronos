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
#include "helper.hpp"

VkCommandBuffer Chronos::Engine::beginSingleTimeCommands(
    VkCommandPool commandPool, VkDevice device)
{
    // used for staging buffers. We need a temproary command buffer to copy the
    // data to the device buffer
    VkCommandBufferAllocateInfo allocInfo {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandPool = commandPool;
    allocInfo.commandBufferCount = 1;

    VkCommandBuffer commandBuffer;
    vkAllocateCommandBuffers(device, &allocInfo, &commandBuffer);

    VkCommandBufferBeginInfo beginInfo {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    beginInfo.flags = VK_COMMAND_BUFFER_USAGE_ONE_TIME_SUBMIT_BIT;

    vkBeginCommandBuffer(commandBuffer, &beginInfo);

    return commandBuffer;
}

void Chronos::Engine::endSingleTimeCommands(VkCommandBuffer* commandBuffer,
    Chronos::Engine::Device device, VkCommandPool commandPool)
{
    vkEndCommandBuffer(*commandBuffer);

    VkSubmitInfo submitInfo {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.commandBufferCount = 1;
    submitInfo.pCommandBuffers = commandBuffer;

    vkQueueSubmit(device.graphicsQueue, 1, &submitInfo, VK_NULL_HANDLE);
    vkQueueWaitIdle(device.graphicsQueue);

    vkFreeCommandBuffers(device.device, commandPool, 1, commandBuffer);
}

uint32_t Chronos::Engine::findMemoryType(uint32_t typeFilter,
    VkMemoryPropertyFlags properties, VkPhysicalDevice physicalDevice)
{
    VkPhysicalDeviceMemoryProperties memProperties;
    vkGetPhysicalDeviceMemoryProperties(physicalDevice, &memProperties);
    for (uint32_t i = 0; i < memProperties.memoryTypeCount; i++) {
	if ((typeFilter & (1 << i))
	    && (memProperties.memoryTypes[i].propertyFlags & properties)
		== properties) {
	    return i;
	}
    }
    throw std::runtime_error("failed to find suitable memory type!");
}

void Chronos::Engine::createBuffer(Chronos::Engine::Device device,
    VkDeviceSize size, VkBufferUsageFlags usage,
    VkMemoryPropertyFlags properties, VkBuffer* buffer,
    VkDeviceMemory* bufferMemory)
{
    VkBufferCreateInfo bufferInfo {};
    bufferInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
    bufferInfo.size = size;
    bufferInfo.usage = usage;
    bufferInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateBuffer(device.device, &bufferInfo, nullptr, buffer)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create buffer!");
    }

    VkMemoryRequirements memRequirements;
    vkGetBufferMemoryRequirements(device.device, *buffer, &memRequirements);

    VkMemoryAllocateInfo allocInfo {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = findMemoryType(
	memRequirements.memoryTypeBits, properties, device.physicalDevice);

    if (vkAllocateMemory(device.device, &allocInfo, nullptr, bufferMemory)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to allocate buffer memory!");
    }

    vkBindBufferMemory(device.device, *buffer, *bufferMemory, 0);
}

void Chronos::Engine::copyBuffer(Chronos::Engine::Device device,
    VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size,
    VkCommandPool commandPool)
{
    // copies data from a buffer to another buffer
    VkCommandBuffer commandBuffer
	= Chronos::Engine::beginSingleTimeCommands(commandPool, device.device);
    VkBufferCopy copyRegion {};
    copyRegion.srcOffset = 0;
    copyRegion.dstOffset = 0;
    copyRegion.size = size;
    vkCmdCopyBuffer(commandBuffer, srcBuffer, dstBuffer, 1, &copyRegion);
    Chronos::Engine::endSingleTimeCommands(&commandBuffer, device, commandPool);
}

Chronos::Engine::QueueFamilyIndices Chronos::Engine::findQueueFamilies(
    VkPhysicalDevice device, VkSurfaceKHR surface)
{
    Chronos::Engine::QueueFamilyIndices indices;
    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(
	device, &queueFamilyCount, nullptr);
    // get the queue families
    std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
    vkGetPhysicalDeviceQueueFamilyProperties(
	device, &queueFamilyCount, queueFamilies.data());
    // check if the queue family has the required properties
    int i = 0;
    for (const auto& queueFamily : queueFamilies) {
	if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
	    indices.graphicsFamily = i;
	}
	VkBool32 presentSupport = false;
	vkGetPhysicalDeviceSurfaceSupportKHR(
	    device, i, surface, &presentSupport);
	if (presentSupport) {
	    indices.presentFamily = i;
	}
	if (indices.isComplete()) {
	    break;
	}
	i++;
    }
    return indices;
}

VkCommandPool Chronos::Engine::createCommandPool(
    Chronos::Engine::Device device, VkSurfaceKHR surface)
{
    VkCommandPool commandPool;
    QueueFamilyIndices queueFamilyIndices
	= Chronos::Engine::findQueueFamilies(device.physicalDevice, surface);
    VkCommandPoolCreateInfo poolInfo {};
    poolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    poolInfo.queueFamilyIndex = queueFamilyIndices.graphicsFamily.value();
    poolInfo.flags
	= VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT; // Optional
    if (vkCreateCommandPool(device.device, &poolInfo, nullptr, &commandPool)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create command pool!");
    }
    return commandPool;
}

VkRenderPass Chronos::Engine::createRenderPass(Chronos::Engine::Device device,
    SwapChain swapChain, VkImageLayout initalLayout, VkImageLayout finalLayout,
    VkImageLayout msaaFinalLayout, bool msaa, bool clearFramebuffer,
    bool dependency)
{
    VkRenderPass renderPass;
    VkAttachmentDescription colorAttachment {};
    colorAttachment.format = swapChain.swapChainImageFormat;
    // if using msaa, set the bits
    if (msaa && device.msaaSamples != VK_SAMPLE_COUNT_1_BIT) {
	colorAttachment.samples = device.msaaSamples;
    } else {
	colorAttachment.samples = VK_SAMPLE_COUNT_1_BIT;
    }
    // when using multiple render passes, we dont want to clear the framebuffer
    // each pass
    if (clearFramebuffer) {
	colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_CLEAR;
    } else {
	colorAttachment.loadOp = VK_ATTACHMENT_LOAD_OP_LOAD;
    }
    colorAttachment.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    colorAttachment.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    colorAttachment.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    colorAttachment.initialLayout = initalLayout; // initial layout of image
    colorAttachment.finalLayout
	= finalLayout; // final layout of image if not using msaa

    VkAttachmentDescription colorAttachmentResolve {};
    colorAttachmentResolve.format = swapChain.swapChainImageFormat;
    colorAttachmentResolve.samples = VK_SAMPLE_COUNT_1_BIT;
    colorAttachmentResolve.loadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    colorAttachmentResolve.storeOp = VK_ATTACHMENT_STORE_OP_STORE;
    colorAttachmentResolve.stencilLoadOp = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    colorAttachmentResolve.stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    colorAttachmentResolve.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    colorAttachmentResolve.finalLayout
	= msaaFinalLayout; // final layout if using msaa

    VkAttachmentReference colorAttachmentRef {};
    colorAttachmentRef.attachment = 0;
    colorAttachmentRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference colorAttachmentResolveRef {};
    colorAttachmentResolveRef.attachment = 1;
    colorAttachmentResolveRef.layout = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpass {};
    subpass.pipelineBindPoint = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpass.colorAttachmentCount = 1;
    subpass.pColorAttachments = &colorAttachmentRef;
    if (msaa && device.msaaSamples != VK_SAMPLE_COUNT_1_BIT) {
	subpass.pResolveAttachments = &colorAttachmentResolveRef;
    } else {
	subpass.pResolveAttachments = nullptr;
    }
    // if we are using multiple render passes, then we need to wait for other
    // commands to finish
    VkSubpassDependency subpassDependencies[2];
    subpassDependencies[0].srcSubpass = VK_SUBPASS_EXTERNAL;
    subpassDependencies[0].dstSubpass = 0;
    subpassDependencies[0].srcStageMask = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    subpassDependencies[0].dstStageMask
	= VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    subpassDependencies[0].srcAccessMask = VK_ACCESS_MEMORY_READ_BIT;
    subpassDependencies[0].dstAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT
	| VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    subpassDependencies[0].dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;

    subpassDependencies[1].srcSubpass = 0;
    subpassDependencies[1].dstSubpass = VK_SUBPASS_EXTERNAL;
    subpassDependencies[1].srcStageMask
	= VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    subpassDependencies[1].dstStageMask = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    subpassDependencies[1].srcAccessMask = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT
	| VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    subpassDependencies[1].dstAccessMask = VK_ACCESS_MEMORY_READ_BIT;
    subpassDependencies[1].dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;

    std::vector<VkAttachmentDescription> attachments = { colorAttachment };
    if (msaa && device.msaaSamples != VK_SAMPLE_COUNT_1_BIT) {
	attachments.push_back(colorAttachmentResolve);
    }

    VkRenderPassCreateInfo renderPassInfo {};
    renderPassInfo.sType = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    renderPassInfo.attachmentCount = static_cast<uint32_t>(attachments.size());
    renderPassInfo.pAttachments = attachments.data();
    renderPassInfo.subpassCount = 1;
    renderPassInfo.pSubpasses = &subpass;
    if (dependency) {
	renderPassInfo.dependencyCount = 2;
	renderPassInfo.pDependencies = subpassDependencies;
    }
    if (vkCreateRenderPass(device.device, &renderPassInfo, nullptr, &renderPass)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create render pass!");
    }
    return renderPass;
}

std::vector<VkFramebuffer> Chronos::Engine::createFramebuffer(
    Chronos::Engine::Device device, SwapChain swapChain,
    VkRenderPass renderPass, bool msaa)
{
    std::vector<VkFramebuffer> framebuffers;
    framebuffers.resize(swapChain.swapChainImageViews.size());
    for (size_t i = 0; i < swapChain.swapChainImageViews.size(); i++) {
	std::vector<VkImageView> attachments;
	if (msaa && device.msaaSamples != VK_SAMPLE_COUNT_1_BIT) {
	    attachments = { swapChain.colorImageView,
		swapChain.swapChainImageViews[i] };
	} else {
	    attachments = { swapChain.swapChainImageViews[i] };
	}
	VkFramebufferCreateInfo framebufferInfo {};
	framebufferInfo.sType = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
	framebufferInfo.renderPass = renderPass;
	framebufferInfo.attachmentCount
	    = static_cast<uint32_t>(attachments.size());
	framebufferInfo.pAttachments = attachments.data();
	framebufferInfo.width = swapChain.swapChainExtent.width;
	framebufferInfo.height = swapChain.swapChainExtent.height;
	framebufferInfo.layers = 1;
	if (vkCreateFramebuffer(
		device.device, &framebufferInfo, nullptr, &framebuffers[i])
	    != VK_SUCCESS) {
	    throw std::runtime_error("failed to create framebuffer!");
	}
    }
    return framebuffers;
}

    std::vector<VkCommandBuffer> Chronos::Engine::createCommandBuffer(
	Chronos::Engine::Device device, Chronos::Engine::SwapChain swapChain,
	VkCommandPool commandPool)
{
    std::vector<VkCommandBuffer> commandBuffers;
    commandBuffers.resize(swapChain.swapChainImageViews.size());
    VkCommandBufferAllocateInfo allocInfo {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
    if (vkAllocateCommandBuffers(
	    device.device, &allocInfo, commandBuffers.data())
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to allocate command buffers!");
    }
    return commandBuffers;
}

