#include "stlheader.hpp"
#include "vulkanHeaders.hpp"
#include "device.hpp"
#include "texture.hpp"
#include "textureManager.hpp"

void Chronos::Engine::TextureManager::init(Chronos::Engine::Device* device, VkCommandPool commandPool)
{
    this->device = device;
    this->commandPool = commandPool;
}

int Chronos::Engine::TextureManager::addTexture(std::string texturePath, std::string textureName)
{
    int textureNo = nextFreeTextureNo++;
    textures[textureNo].create(*device, commandPool, texturePath, textureName);
    return textureNo;
}

void Chronos::Engine::TextureManager::removeTexture(int textureNo)
{
    textures[textureNo].destroy();
    textures.erase(textureNo);
}

void Chronos::Engine::TextureManager::destroy()
{
    for (auto& texture : textures)
    {
        texture.second.destroy();
    }
}

Chronos::Engine::Texture Chronos::Engine::TextureManager::getTexture(int textureNo)
{
    return textures[textureNo];
}