#pragma once

void createTextureSampler(Chronos::Engine::Device device, VkSampler* textureSampler);
void createImage(Chronos::Engine::Device device, uint32_t width, uint32_t height,
    VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
    VkMemoryPropertyFlags properties, VkImage* image,
    VkDeviceMemory* imageMemory, VkSampleCountFlagBits numSamples);

void transitionImageLayout(VkImage image, VkFormat format,
    VkImageLayout oldLayout, VkImageLayout newLayout,
    VkCommandPool commandPool, Chronos::Engine::Device device);
void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
    uint32_t height, VkCommandPool commandPool,
    Chronos::Engine::Device device);
VkImageView createImageView(Chronos::Engine::Device device, VkFormat format, VkImage image);

class Texture {
public:
    VkDeviceMemory textureImageMemory;
    VkImage textureImage;
    VkImageView textureImageView;

    Chronos::Engine::Device device;

    void create(Chronos::Engine::Device device, VkCommandPool commandPool,
        std::string texturePath);
    void destroy();
};