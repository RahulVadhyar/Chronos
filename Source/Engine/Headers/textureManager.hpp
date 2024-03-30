#pragma once
/**
\file textureManager.hpp

\brief Contains the class for managing textures in the Chronos::Engine namespace.
*/
namespace Chronos{
    namespace Engine{

    /**
    \brief This is the texture manager for Chronos. It handles creation, modification, updating and desrtuction of textures.

    Once created, they can be removed or referenced by their texture number.
    */
    class TextureManager{
    public:

        /**
        \brief The textures that are managed by this class. They are mapped via texture nos
        */
        std::map<int, Chronos::Engine::Texture> textures;
        int nextFreeTextureNo = 0;
        
        /**
        \brief Initializes the texture manager.

        @param device The device that has the textures.
        @param commandPool The command pool to create the temporary command buffer from.
        */
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool);

        /**
        \brief Adds a texture to the texture manager.

        @param texturePath The path to the texture(only jpg or png).
        @param textureName The name of the texture(must be unique).
        @return The texutreNoof the texture that was added.
        */
        int addTexture(std::string texturePath, std::string textureName);
        
        /**
        \brief Removes a texture from the texture manager.

        @param textureNo The textureNo of the texture to remove.
        */
        void removeTexture(int textureNo);

        /**

        \brief Gets the texture from the texture manager.

        @param textureNo The textureNo of the texture to get.

        @return The texture that was requested.
        */
        Chronos::Engine::Texture getTexture(int textureNo);
        
        /**
        \brief Destroys the texture manager.
        */
        void destroy();

    private:
        Chronos::Engine::Device* device;
        VkCommandPool commandPool;
    };

    };
};