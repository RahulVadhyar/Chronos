#pragma once

/**
\brief This manages the logical and physical devices.

It also manages the various queues that are used for rendering and presentation.
MSAA is also handled here due to the fact that it is a device managed property.
*/
namespace Chronos{
    namespace Engine{

class Device {
public:

    /**
    This is the logical device that is used by Vulkan.
    */
    VkDevice device;

    /**
    This is the physical device that is used by Vulkan. 
    Generally used for allocating memory and buffers.
    */
    VkPhysicalDevice physicalDevice;
    
    /**
    This is the queue that is used for graphics rendering.
    */
    VkQueue graphicsQueue;

    /**
    This is the queue that is used for presentation of the rendered frames.
    */
    VkQueue presentQueue;

    /**
    This sets the MSAA samples count. By default it is set to 1x. This can be changed on the fly.
    However it requires the swapchain to be recreated along with textures and any other assosicated buffers and objects.
    */
    VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

    /**
    This is the function that initializes the devices and queues.
    It picks the best device based on the requirements and features that we require.
    */
    void init(VkInstance instance, VkSurfaceKHR surface);

    /**
    This is the function that destroys the device.
    We need to make sure that all the objects that are created using the device are destroyed before this is called.
    Else Vulkan Valiation layers will become angry at us.
    */
    void destroy();

private:

    /**
    This is the function that picks the best device based on the requirements and features that we require.
    */
    void pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);
    
    /**
    This creates the logical device.
    */
    void createLogicalDevice(VkSurfaceKHR surface);
};
    };
};