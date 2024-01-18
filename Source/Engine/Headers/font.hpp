#pragma once
#include "object.hpp"
#include "stb_font_consolas_24_latin1.inl"
namespace Chronos {
namespace Engine{
    class Font : public Chronos::Engine::Object {
    public:
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, VkRenderPass* renderPass);
        void destroy();
        void clear();
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
        void update(uint32_t currentFrame);
        VkBuffer vertexBuffer;
        uint32_t numLetters;
        Chronos::Engine::TextParams params;
    private:
        void createDescriptorSets();
        std::vector<VkDescriptorType> getDescriptorTypes();
        std::vector<VkShaderStageFlagBits> getDescriptorStages();
        PipelineAttributes getPipelineAttributes();
        void updateBuffer();
        uint32_t maxTextLength = 2048;
        stb_fontchar stbFontData[STB_FONT_consolas_24_latin1_NUM_CHARS];

        VkDeviceMemory vertexBufferMemory;

        Chronos::Engine::Texture fontTexture;
        glm::vec4* mappedMemory;
    };
};
};