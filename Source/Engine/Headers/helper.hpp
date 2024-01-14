#pragma once
#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "swapchain.hpp"

struct QueueFamilyIndices {
    std::optional<uint32_t> graphicsFamily;
    std::optional<uint32_t> presentFamily;
    bool isComplete()
    {
        return graphicsFamily.has_value() && presentFamily.has_value();
    }
};

const std::vector<const char*> deviceExtensions = {
    VK_KHR_SWAPCHAIN_EXTENSION_NAME
};

/**
This is used to create a temporary commandBuffer for single use. Generally used for transfering data to the GPU.
After using the buffer, it must be destroyed using endSingleTimeCommands.
*/
VkCommandBuffer beginSingleTimeCommands(VkCommandPool commandPool,
    VkDevice device);

/**
This is used to end the temporary commandBuffer for single use. Generally used for transfering data to the GPU.
These buffers are created using beginSingleTimeCommands.
*/
void endSingleTimeCommands(VkCommandBuffer* commandBuffer, Chronos::Engine::Device device,
    VkCommandPool commandPool);

/**
This is used to find a memory type that is suitable for the buffer that we are creating.
It takes in the typeFilter and VkMemoryPropertyFlags to find such a memory type.
It finds this on the physical device that we provide it
*/
uint32_t findMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties,
    VkPhysicalDevice physicalDevice);

/**
This is used to create a buffer of a given size, usage and properties.
It also allocates memory for the buffer.
*/
void createBuffer(Chronos::Engine::Device device, VkDeviceSize size, VkBufferUsageFlags usage,
    VkMemoryPropertyFlags properties, VkBuffer* buffer,
    VkDeviceMemory* bufferMemory);

/**
This is used to copy a buffer from a source buffer to a destination buffer of a given size.
This is used to transfer data to the GPU.
It does this by creating a command buffer and submitting it to the queue.
*/
void copyBuffer(Chronos::Engine::Device device, VkBuffer srcBuffer, VkBuffer dstBuffer,
    VkDeviceSize size, VkCommandPool commandPool);

/**
This gets the needed extensions to be enabled in vulkan, including the presesntation and KHR extensions
*/
std::vector<const char*> getRequiredExtensions();

/**
This is used to find the queue families that are supported by the physical device that we provide it.
*/
QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device,
    VkSurfaceKHR surface);

/**
This is used to check if the physical device that we provide it supports the extensions that we need.
*/
bool checkDeviceExtensionSupport(VkPhysicalDevice device);

/**
This is to check whether the physical device that we provide it can render to the surface that we provide it.
*/
bool isDeviceSuitable(VkPhysicalDevice physicalDevice, VkSurfaceKHR surface);

/**
This creates a command pool
*/
VkCommandPool createCommandPool(Chronos::Engine::Device device, VkSurfaceKHR surface);

/**
For a given swap chain, layouts, this creates a render pass

@param initalLayout The initial layout of the incoming image. If this from the previous frame(no render pass before it) then this is ```VK_IMAGE_LAYOUT_UNDEFINED```,
else it is advised to use ```VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL```. 

@param finalLayout The final layout of the outgoing image before MSAA. If this is going to be presented to the screen, then this is ```VK_IMAGE_LAYOUT_PRESENT_SRC_KHR```,
else it is advised to use ```VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL```. If MSAA is enabled, then this is ```VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL```,
as then msaaFinalLayout is used for the final layout if this is the final render pass.

@param msaaFinalLayout The final layout of the outgoing image if MSAA is enabled. 
This is due to the fact that MSAA resolves the image, hence it change the layout of the image.
If this is going to be presented to the screen, then this is ```VK_IMAGE_LAYOUT_PRESENT_SRC_KHR```,
else it is advised to use ```VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL```.

@param msaa Whether MSAA is enabled or not.

@param clearFramebuffer Whether the framebuffer should be cleared or not. If this is the first render pass, then this should be true. 
Else it should be false, else the previous contents rendered to the framebuffer from the previous render pass will be cleared.

@param dependency Whether the render pass should wait for other render passes to finish. If there are render passes before this, then this should be true.
Else it should be false.
*/
VkRenderPass createRenderPass(Chronos::Engine::Device device, SwapChain swapChain,
    VkImageLayout initalLayout,
    VkImageLayout finalLayout,
    VkImageLayout msaaFinalLayout, bool msaa,
    bool clearFramebuffer, bool dependency);

/**
This creates a frame buffer for a given swap chain, renderpass style. if MSAA used then the ```msaa``` flag should be true.
*/
std::vector<VkFramebuffer> createFramebuffer(Chronos::Engine::Device device, SwapChain swapChain,
    VkRenderPass renderPass,
    bool msaa);

/**

*/
std::vector<VkCommandBuffer> createCommandBuffer(Chronos::Engine::Device device,
    SwapChain swapChain,
    VkCommandPool commandPool);
std::vector<char> readFile(const std::string& filename);
VkShaderModule createShaderModule(const std::vector<char>& code,
    VkDevice device);
VkSampleCountFlagBits getMaxUsableSampleCount(VkPhysicalDevice physicalDevice);

std::string getAbsolutePath(std::string relativePath);