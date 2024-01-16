#include "object.hpp"
namespace Chronos {
namespace Engine{
    //just need to add the text to be rendered.
    class Font : public Chronos::Engine::Object {
    public:
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, VkRenderPass* renderPass);
        void update(uint32_t currentFrame);
        void destroy();

    private:
        uint32_t maxTextLength = 2048;
        stb_fontchar stbFontData[STB_FONT_consolas_24_latin1_NUM_CHARS];
        uint32_t numLetters;
        float scale = 4.0f;

        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;

        Chronos::Engine::Texture fontTexture;
        glm::vec4* mappedMemory;
    };
};
};