#pragma once
namespace Chronos{
    namespace Engine{
    class TextureManager{
    public:
        std::map<int, Chronos::Engine::Texture> textures;
        int nextFreeTextureNo = 0;
        
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool);
        int addTexture(std::string texturePath);
        void removeTexture(int textureNo);
        Chronos::Engine::Texture getTexture(int textureNo);
        void destroy();

    private:
        Chronos::Engine::Device* device;
        VkCommandPool commandPool;
    };

    };
};