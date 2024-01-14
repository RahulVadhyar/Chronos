/** \file guiHeaders.hpp

 \brief Contains the swapChain class along with all the swapChain related functions.
*/
#pragma once
#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "device.hpp"
namespace Chronos {
namespace Engine {
    struct SwapChainSupportDetails {
        VkSurfaceCapabilitiesKHR capabilities;
        std::vector<VkSurfaceFormatKHR> formats;
        std::vector<VkPresentModeKHR> presentModes;
    };

    VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities,
        GLFWwindow* window);
    VkPresentModeKHR chooseSwapPresentMode(
        const std::vector<VkPresentModeKHR>& availablePresentModes);
    VkSurfaceFormatKHR chooseSwapSurfaceFormat(
        const std::vector<VkSurfaceFormatKHR>& availableFormats);
    SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device,
        VkSurfaceKHR surface);

    class SwapChain {
    public:
        
        void init(Chronos::Engine::Device* device, VkSurfaceKHR surface, GLFWwindow* window);
        void recreate();
        void cleanup();
        void changeMsaa();
        VkExtent2D swapChainExtent;
        VkSwapchainKHR swapChain;
        VkSurfaceKHR surface;
        std::vector<VkImageView> swapChainImageViews;
        VkImageView colorImageView;
        VkFormat swapChainImageFormat;
    private:
        Chronos::Engine::Device* device;

        GLFWwindow* window;
        VkImage colorImage;
        VkDeviceMemory colorImageMemory;
        std::vector<VkImage> swapChainImages;

        void create();
        void createImageViews();
        void createColorResources();
    };
};
};