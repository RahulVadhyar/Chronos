#pragma once
#include "object.hpp"
#include "stb_font_consolas_24_latin1.inl"
namespace Chronos {
namespace Engine{
    //just need to add the text to be rendered.
    class Font : public Chronos::Engine::Object {
    public:
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, VkRenderPass* renderPass);
        void destroy();
        void addText(std::string text, float x, float y);
        void clear();
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
        void update(uint32_t currentFrame){};
        VkBuffer vertexBuffer;
        uint32_t numLetters;
    private:
        void createDescriptorSets();
        std::vector<VkDescriptorType> getDescriptorTypes();
        std::vector<VkShaderStageFlagBits> getDescriptorStages();
        PipelineAttributes getPipelineAttributes();
        std::string text;
        float x, y;
        uint32_t maxTextLength = 2048;
        stb_fontchar stbFontData[STB_FONT_consolas_24_latin1_NUM_CHARS];
        float scale = 1.0f;

        VkDeviceMemory vertexBufferMemory;

        Chronos::Engine::Texture fontTexture;
        glm::vec4* mappedMemory;
    };
};
};