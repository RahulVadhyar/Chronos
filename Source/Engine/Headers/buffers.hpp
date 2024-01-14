#pragma once

/**
This function creates a buffer and allocates memory for it.
*/

void createBuffer(Chronos::Engine::Device device, VkDeviceSize size, VkBufferUsageFlags usage,
    VkMemoryPropertyFlags properties, VkBuffer* buffer,
    VkDeviceMemory* bufferMemory);

/**
This is copy a buffer to another buffer.
Generally used to copy data from CPU to GPU via staging buffer.
*/
void copyBuffer(Chronos::Engine::Device device, VkBuffer srcBuffer, VkBuffer dstBuffer,
    VkDeviceSize size, VkCommandPool commandPool);

/**
This is a wrapper class for the VkBuffer and VkDeviceMemory.
This is used to manage a buffer that is permeant.
*/
class Buffer {
public:
    VkBuffer buffer;
    VkDeviceMemory memory;
    Chronos::Engine::Device device;
    VkDeviceSize size;
    void create(Chronos::Engine::Device device, VkBufferUsageFlags flags,
        VkMemoryPropertyFlags properties);
    void copy(void* data, VkCommandPool commandPool);
    void destroy();
};

/**
This is a Uniform buffer for storing the uniform variables in the shaders
Currently used only for shapes.
Can be updated on the fly.
*/
class UniformBuffer : public Buffer {
public:
    void* data;
    void create(Chronos::Engine::Device device);
    void update(VkExtent2D swapChainExtent, float x, float y, float rotation,
        float x_size, float y_size);
};
