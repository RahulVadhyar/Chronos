#pragma once
/** \file device.hpp

 \brief Contains the [Device](#Chronos::Engine::Device) class.
*/
namespace Chronos {
namespace Engine {

    /**
    \brief This initializes, manages and destroys the logical and physical devices(GPU).

    It also manages the various queues that are used for rendering and presentation.
    MSAA is also handled here due to the fact that it is a device managed property.
    */
    class Device {
    public:
        /**
        \brief This is the logical device that is used by Vulkan.
        */
        VkDevice device;

        /**
        \brief This is the physical device that is used by Vulkan.


        Generally used for allocating memory and buffers.
        */
        VkPhysicalDevice physicalDevice;

        /**
        \brief  This is the queue that is used for graphics rendering.
        */
        VkQueue graphicsQueue;

        /**
        \brief This is the queue that is used for presentation of the rendered frames.
        */
        VkQueue presentQueue;

        /**
        \brief This sets the MSAA samples count.

        During initialization it is set to maximium number possible. This can be changed on the fly.
        However it requires the swapchain to be recreated along with textures and any other assosicated buffers and objects.
        */
        VkSampleCountFlagBits msaaSamples = VK_SAMPLE_COUNT_1_BIT;

        /**
        \brief This is the function that initializes the devices and queues.


        It picks the best device(GPU) based on the requirements and features that we require.

        @param instance The Vulkan instance that is used by the application.
        @param surface The surface that is used by the application for presenting the rendered images.
        */
        void init(VkInstance instance, VkSurfaceKHR surface);

        /**
        \brief This is the function that destroys the device.


        We need to make sure that all the objects that are created using the device are destroyed before this is called.
        Else Vulkan Valiation layers will become angry at us.
        */
        void destroy();

    private:
        /**
        \brief  This is the function that picks the best device based on the requirements and features that we require.

        It finds all the physical devices(GPUs) that are available and then checks if they are suitable for our application.
        If none of the devices are suitable then it throws an error.
        If there are multiple suitable devices, then it gets the first usable device.
        the maximum number of MSAA samples is also set here.

        @param instance The Vulkan instance that is used by the application.
        @param surface The surface that is used by the application for presenting the rendered images.
        */
        void pickPhysicalDevice(VkInstance instance, VkSurfaceKHR surface);

        /**
        \brief This creates the logical device.

        Along with creating the logical device, it creates the queues that are used for rendering and presentation.
        anisotropy and other features are also enabled here.

        @param surface The surface that is used by the application for presenting the rendered images.
        */
        void createLogicalDevice(VkSurfaceKHR surface);
    };
};
};