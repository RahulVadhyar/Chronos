#pragma once
#include "shapeManager.hpp"
namespace Chronos {
namespace Editor {

    class GUI {
    public:
        Chronos::Engine::Device* device;
        Chronos::Engine::SwapChain* swapChain;
        VkSurfaceKHR surface;
        GLFWwindow* window;

        VkCommandPool commandPool;
        VkDescriptorPool descriptorPool;
        std::vector<VkCommandBuffer> commandBuffers;
        std::vector<VkFramebuffer> framebuffers;
        VkRenderPass renderPass;

        void init(Chronos::Engine::Device* device, GLFWwindow* window, Chronos::Engine::SwapChain* swapChain,
            VkInstance instance, VkSurfaceKHR surface);
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
        void destroy();
        void update(); // need to reorganize thnis
        void recreate(); // destroy framebuffer
        void changeMsaa(); // destroy renderpass
        void cleanup();
    };
}; // namespace Editor
}; // namespace Chronos