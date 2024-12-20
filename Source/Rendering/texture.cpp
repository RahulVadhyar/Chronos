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

#include "texture.hpp"
#include "helper.hpp"
#define STB_IMAGE_IMPLEMENTATION
#ifndef WIN32
#ifndef __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstringop-overflow"
#endif
#endif
#include "stb_image.h"
#ifndef WIN32
#ifndef __clang__
#pragma GCC diagnostic pop
#endif
#endif
#ifdef ENABLE_EDITOR
#include "editorHeaders.hpp"
#endif

void Chronos::Engine::createImage(Chronos::Engine::Device device,
    uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling,
    VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage* image,
    VkDeviceMemory* imageMemory, VkSampleCountFlagBits numSamples)
{
    VkImageCreateInfo imageInfo {};
    imageInfo.sType = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imageInfo.imageType = VK_IMAGE_TYPE_2D;
    imageInfo.extent.width = width;
    imageInfo.extent.height = height;
    imageInfo.extent.depth = 1;
    imageInfo.mipLevels = 1;
    imageInfo.arrayLayers = 1;
    imageInfo.format = format;
    imageInfo.tiling = tiling;
    imageInfo.initialLayout = VK_IMAGE_LAYOUT_UNDEFINED;
    imageInfo.usage = usage;
    imageInfo.samples = numSamples;
    imageInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

    if (vkCreateImage(device.device, &imageInfo, nullptr, image)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create image!");
    }

    VkMemoryRequirements memRequirements;
    vkGetImageMemoryRequirements(device.device, *image, &memRequirements);

    VkMemoryAllocateInfo allocInfo {};
    allocInfo.sType = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    allocInfo.allocationSize = memRequirements.size;
    allocInfo.memoryTypeIndex = Chronos::Engine::findMemoryType(
	memRequirements.memoryTypeBits, properties, device.physicalDevice);

    if (vkAllocateMemory(device.device, &allocInfo, nullptr, imageMemory)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to allocate image memory!");
    }

    vkBindImageMemory(device.device, *image, *imageMemory, 0);
}
void Chronos::Engine::Texture::create(Chronos::Engine::Device device,
    VkCommandPool commandPool, std::string texturePath, std::string textureName)
{
    this->texturePath = texturePath;
    this->textureName = textureName;
    int texWidth = 0, texHeight = 0, texChannels = 0;
    this->device = device;
    VkDeviceSize imageSize;
    uint8_t* pixels;

    if (texturePath.ends_with(".png") || texturePath.ends_with(".jpg")) {
	pixels = stbi_load(texturePath.c_str(), &texWidth, &texHeight,
	    &texChannels, STBI_rgb_alpha);
	imageSize = texWidth * texHeight * 4;
	this->width = texWidth;
	this->height = texHeight;
	if (!pixels) {
	    throw std::runtime_error(
		"failed to load texture image " + texturePath);
	}
    } else {
	throw std::runtime_error("unsupported texture format " + texturePath);
    }

    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    Chronos::Engine::createBuffer(device, imageSize,
	VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
	VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT
	    | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
	&stagingBuffer, &stagingBufferMemory);

    void* data;
    vkMapMemory(device.device, stagingBufferMemory, 0, imageSize, 0, &data);
    memcpy(data, pixels, static_cast<size_t>(imageSize));
    vkUnmapMemory(device.device, stagingBufferMemory);

    stbi_image_free(pixels);

    Chronos::Engine::createImage(device, texWidth, texHeight,
	VK_FORMAT_R8G8B8A8_SRGB, VK_IMAGE_TILING_OPTIMAL,
	VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, &textureImage, &textureImageMemory,
	VK_SAMPLE_COUNT_1_BIT);

    Chronos::Engine::transitionImageLayout(textureImage,
	VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
	commandPool, device);
    Chronos::Engine::copyBufferToImage(stagingBuffer, textureImage,
	static_cast<uint32_t>(texWidth), static_cast<uint32_t>(texHeight),
	commandPool, device);
    Chronos::Engine::transitionImageLayout(textureImage,
	VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
	VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, commandPool, device);
    vkDestroyBuffer(device.device, stagingBuffer, nullptr);
    vkFreeMemory(device.device, stagingBufferMemory, nullptr);
    textureImageView
	= createImageView(device, VK_FORMAT_R8G8B8A8_SRGB, textureImage);
#ifdef ENABLE_EDITOR
    Chronos::Engine::createTextureSampler(device, &textureSampler);
    descriptorSet = ImGui_ImplVulkan_AddTexture(textureSampler,
	textureImageView, VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);

#endif
}

void Chronos::Engine::Texture::create(Chronos::Engine::Device device,
    VkCommandPool commandPool, void* data, size_t texWidth, size_t texHeight,
    VkDeviceSize imageSize, VkFormat format, std::string textureName)
{
    this->textureName = textureName;
    this->texturePath = "NA";
    this->device = device;
    VkBuffer stagingBuffer;
    VkDeviceMemory stagingBufferMemory;
    Chronos::Engine::createBuffer(device, imageSize,
	VK_BUFFER_USAGE_TRANSFER_SRC_BIT,
	VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT
	    | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
	&stagingBuffer, &stagingBufferMemory);

    void* mappedData;
    vkMapMemory(
	device.device, stagingBufferMemory, 0, imageSize, 0, &mappedData);
    memcpy(mappedData, data, static_cast<size_t>(imageSize));
    vkUnmapMemory(device.device, stagingBufferMemory);

    Chronos::Engine::createImage(device, texWidth, texHeight, format,
	VK_IMAGE_TILING_OPTIMAL,
	VK_IMAGE_USAGE_TRANSFER_DST_BIT | VK_IMAGE_USAGE_SAMPLED_BIT,
	VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, &textureImage, &textureImageMemory,
	VK_SAMPLE_COUNT_1_BIT);

    Chronos::Engine::transitionImageLayout(textureImage,
	VK_IMAGE_LAYOUT_UNDEFINED, VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
	commandPool, device);
    Chronos::Engine::copyBufferToImage(stagingBuffer, textureImage,
	static_cast<uint32_t>(texWidth), static_cast<uint32_t>(texHeight),
	commandPool, device);
    Chronos::Engine::transitionImageLayout(textureImage,
	VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL,
	VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL, commandPool, device);
    vkDestroyBuffer(device.device, stagingBuffer, nullptr);
    vkFreeMemory(device.device, stagingBufferMemory, nullptr);
    textureImageView = createImageView(device, format, textureImage);
}

void Chronos::Engine::transitionImageLayout(VkImage image,
    VkImageLayout oldLayout, VkImageLayout newLayout, VkCommandPool commandPool,
    Chronos::Engine::Device device)
{
    VkCommandBuffer commandBuffer
	= Chronos::Engine::beginSingleTimeCommands(commandPool, device.device);
    VkImageMemoryBarrier barrier {};
    barrier.sType = VK_STRUCTURE_TYPE_IMAGE_MEMORY_BARRIER;
    barrier.oldLayout = oldLayout;
    barrier.newLayout = newLayout;
    barrier.srcQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.dstQueueFamilyIndex = VK_QUEUE_FAMILY_IGNORED;
    barrier.image = image;
    barrier.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    barrier.subresourceRange.baseMipLevel = 0;
    barrier.subresourceRange.levelCount = 1;
    barrier.subresourceRange.baseArrayLayer = 0;
    barrier.subresourceRange.layerCount = 1;
    VkPipelineStageFlags sourceStage;
    VkPipelineStageFlags destinationStage;

    if (oldLayout == VK_IMAGE_LAYOUT_UNDEFINED
	&& newLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL) {
	barrier.srcAccessMask = 0;
	barrier.dstAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;

	sourceStage = VK_PIPELINE_STAGE_TOP_OF_PIPE_BIT;
	destinationStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
    } else if (oldLayout == VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL
	&& newLayout == VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL) {
	barrier.srcAccessMask = VK_ACCESS_TRANSFER_WRITE_BIT;
	barrier.dstAccessMask = VK_ACCESS_SHADER_READ_BIT;

	sourceStage = VK_PIPELINE_STAGE_TRANSFER_BIT;
	destinationStage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
    } else {
	throw std::invalid_argument("unsupported layout transition!");
    }

    vkCmdPipelineBarrier(commandBuffer, sourceStage, destinationStage, 0, 0,
	nullptr, 0, nullptr, 1, &barrier);
    Chronos::Engine::endSingleTimeCommands(&commandBuffer, device, commandPool);
}

void Chronos::Engine::copyBufferToImage(VkBuffer buffer, VkImage image,
    uint32_t width, uint32_t height, VkCommandPool commandPool,
    Chronos::Engine::Device device)
{
    VkCommandBuffer commandBuffer
	= Chronos::Engine::beginSingleTimeCommands(commandPool, device.device);
    VkBufferImageCopy region {};
    region.bufferOffset = 0;
    region.bufferRowLength = 0;
    region.bufferImageHeight = 0;
    region.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    region.imageSubresource.mipLevel = 0;
    region.imageSubresource.baseArrayLayer = 0;
    region.imageSubresource.layerCount = 1;
    region.imageOffset = { 0, 0, 0 };
    region.imageExtent = { width, height, 1 };
    vkCmdCopyBufferToImage(commandBuffer, buffer, image,
	VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL, 1, &region);
    Chronos::Engine::endSingleTimeCommands(&commandBuffer, device, commandPool);
}

VkImageView Chronos::Engine::createImageView(
    Chronos::Engine::Device device, VkFormat format, VkImage image)
{
    VkImageViewCreateInfo viewInfo {};
    viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    viewInfo.image = image;
    viewInfo.viewType = VK_IMAGE_VIEW_TYPE_2D;
    viewInfo.format = format;
    viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
    viewInfo.subresourceRange.baseMipLevel = 0;
    viewInfo.subresourceRange.levelCount = 1;
    viewInfo.subresourceRange.baseArrayLayer = 0;
    viewInfo.subresourceRange.layerCount = 1;

    VkImageView imageView;

    if (vkCreateImageView(device.device, &viewInfo, nullptr, &imageView)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create texture image view!");
    }
    return imageView;
}

void Chronos::Engine::createTextureSampler(
    Chronos::Engine::Device device, VkSampler* textureSampler)
{
    VkPhysicalDeviceProperties properties {};
    vkGetPhysicalDeviceProperties(device.physicalDevice, &properties);
    VkSamplerCreateInfo samplerInfo {};
    samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
    samplerInfo.magFilter = VK_FILTER_LINEAR;
    samplerInfo.minFilter = VK_FILTER_LINEAR;
    samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_REPEAT;
    samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_REPEAT;
    samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_REPEAT;
    samplerInfo.anisotropyEnable = VK_TRUE;
    samplerInfo.maxAnisotropy = properties.limits.maxSamplerAnisotropy;
    samplerInfo.borderColor = VK_BORDER_COLOR_INT_OPAQUE_BLACK;
    samplerInfo.unnormalizedCoordinates = VK_FALSE;
    samplerInfo.compareEnable = VK_FALSE;
    samplerInfo.compareOp = VK_COMPARE_OP_ALWAYS;
    samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
    samplerInfo.mipLodBias = 0.0f;
    samplerInfo.minLod = 0.0f;
    samplerInfo.maxLod = 0.0f;
    if (vkCreateSampler(device.device, &samplerInfo, nullptr, textureSampler)
	!= VK_SUCCESS) {
	throw std::runtime_error("failed to create texture sampler!");
    }
}

void Chronos::Engine::Texture::destroy()
{
    vkDestroyImageView(device.device, textureImageView, nullptr);
    vkDestroyImage(device.device, textureImage, nullptr);
    vkFreeMemory(device.device, textureImageMemory, nullptr);
}
