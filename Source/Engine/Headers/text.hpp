#pragma once
#include "swapchain.hpp"
#include "stb_font_consolas_24_latin1.inl"
namespace Chronos {
namespace Engine {
    enum TextAlignment { Left,
        Center,
        Right };
    class Text {
    public:
        uint32_t maxTextLength = 2048;
        stb_fontchar stbFontData[STB_FONT_consolas_24_latin1_NUM_CHARS];
        uint32_t numLetters;
        float scale = 4.0f;

        const char* vertexShaderPath = "../ThirdParty/Chronos/Shaders/textVert.spv";
        const char* fragmentShaderPath = "../ThirdParty/Chronos/Shaders/textFrag.spv";
        Chronos::Engine::Device* device;
        Chronos::Engine::SwapChain* swapChain;
        VkCommandPool commandPool;
        VkSampler textureSampler;
        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        VkImage texture;
        VkImageView textureImageView;
        VkDeviceMemory textureImageMemory;
        glm::vec4* mappedMemory;

        std::vector<VkCommandBuffer> commandBuffers;
        VkRenderPass renderPass;
        std::vector<VkFramebuffer> framebuffers;
        std::vector<VkDescriptorSet> descriptorSets;
        VkDescriptorSetLayout descriptorSetLayout;
        VkDescriptorPool descriptorPool;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain);
        void createGraphicsPipeline();
        void createDescriptorPool();
        void createDescriptorSetLayout();
        void createDescriptorSets();
        void destroy();
        void recreateGraphicsPipeline();
        void beginUpdate();
        void add(std::string text, float x, float y, TextAlignment alignment);
        void endUpdate();
        void changeMsaa();
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
        void recreate();
        void cleanup();
    };
};
};