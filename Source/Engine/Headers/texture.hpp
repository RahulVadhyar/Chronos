#pragma once
/** \file texture.hpp

 \brief Contains the functions for image manipulation along with the Texture class.
*/
namespace Chronos {
namespace Engine {

    /**
    \brief Creates a ```VkSampler```

    @param device Device to create the sampler on.
    @param textureSampler Sampler to be created.
    */
    void createTextureSampler(Chronos::Engine::Device device, VkSampler* textureSampler);

    /**
    \brief For a given image dimensons, it creates a ```VkImage``` and ```VkDeviceMemory``` for the image.

    @param device Sevice to create the image on.
    @param width Width of the image.
    @param height Height of the image.
    @param format Format of the image. More information [here.](https://registry.khronos.org/vulkan/specs/1.3-extensions/man/html/VkFormat.html)
    @param tiling Tiling structure of the image. Options are ```VK_IMAGE_TILING_OPTIMAL``` and ```VK_IMAGE_TILING_LINEAR```
    @param usage The usage of the image. Common options are  ```VK_IMAGE_USAGE_SAMPLED_BIT```, ```VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT```,
    ```VK_IMAGE_USAGE_INPUT_ATTACHMENT_BIT``` and ```VK_IMAGE_USAGE_TRANSIENT_ATTACHMENT_BIT```.
    @param properties The properties of the image. Common options are ```VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT```, ```VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT```,
    ```VK_MEMORY_PROPERTY_HOST_COHERENT_BIT``` and ```VK_MEMORY_PROPERTY_HOST_CACHED_BIT```.
    @param image The image to be created.
    @param imageMemory The memory for the image to be created.
    @param numSamples The number of samples for the image. Common options are ```VK_SAMPLE_COUNT_1_BIT```, ```VK_SAMPLE_COUNT_2_BIT```,
    ```VK_SAMPLE_COUNT_4_BIT``` and ```VK_SAMPLE_COUNT_8_BIT```. Generally ```VK_SAMPLE_COUNT_1_BIT``` is used unless the image is used with MSAA.
    */
    void createImage(Chronos::Engine::Device device, uint32_t width, uint32_t height,
        VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage,
        VkMemoryPropertyFlags properties, VkImage* image,
        VkDeviceMemory* imageMemory, VkSampleCountFlagBits numSamples);

    /**
    \brief Transiton a ```VkImage``` from one layout to another.

    Only the following transitions are supported:
    - ```VK_IMAGE_LAYOUT_UNDEFINED``` to ```VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL```
    - ```VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL``` to ```VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL```

    @param image The image to be transitioned.
    @param format The format of the image.
    @param oldLayout The old layout of the image(```VK_IMAGE_LAYOUT_UNDEFINED```  or  ```VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL```).
    @param newLayout The new layout of the image(```VK_IMAGE_LAYOUT_TRANSFER_DST_OPTIMAL``` or ```VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL```).
    */

    void transitionImageLayout(VkImage image, VkFormat format,
        VkImageLayout oldLayout, VkImageLayout newLayout,
        VkCommandPool commandPool, Chronos::Engine::Device device);

    /**
    \brief Copy data from a buffer to an image.

    @param buffer The buffer to copy data from.
    @param image The image to copy data to.
    @param width Width of the image.
    @param height Height of the image.
    @param commandPool The command pool to create the temporary command buffer from.
    @param device The device that has the image.
    */
    void copyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width,
        uint32_t height, VkCommandPool commandPool,
        Chronos::Engine::Device device);

    /**
    \brief Create a ```VkImageView``` for a given ```VkImage```.

    For each image, we need to create an image view. This is used to specify how the image is to be used.

    @param device The device that has the image.
    @param format The format of the image.
    @param image The image to create the image view for.

    @return The created image view.
    */
    VkImageView createImageView(Chronos::Engine::Device device, VkFormat format, VkImage image);

    /**
    \brief This class holds the Vulkan data and objects needed for a texture.

    The items needed for creating a texture that are stored in this class are:
    - ```VkDeviceMemory``` for the texture memory
    - ```VkImage``` for the texture
    - ```VkImageView``` for the texture image view
    */
    class Texture {
    public:
        /**
        \brief The memory for the texture.
        */
        VkDeviceMemory textureImageMemory;

        /**
        \brief The image for the texture
        */
        VkImage textureImage;

        /**
        \brief The image view for the texture.
        */
        VkImageView textureImageView;

        /**
        \brief Create the texture by loading the texture from the given path. Only supports jpg and png images.
        */
        void create(Chronos::Engine::Device device, VkCommandPool commandPool,
            std::string texturePath);

        /**
        \brief Create the texture by loading the texture from the given raw data.

        Used in Text Rendering
        */
        void create(Chronos::Engine::Device device, VkCommandPool commandPool,
            void* data, size_t texWidth, size_t texHeight, VkDeviceSize imageSize, VkFormat format);

        /**
        \brief Destroy the texture assets.
        */
        void destroy();

    private:
        /**
        \brief The device that has the texture.
        */
        Chronos::Engine::Device device;
    };
};
};