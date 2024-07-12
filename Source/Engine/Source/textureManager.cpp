/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "stlheader.hpp"
#include "vulkanHeaders.hpp"
#include "device.hpp"
#include "texture.hpp"
#include "textureManager.hpp"

void Chronos::Engine::TextureManager::init(
    Chronos::Engine::Device* device, VkCommandPool commandPool)
{
    this->device = device;
    this->commandPool = commandPool;
}

int Chronos::Engine::TextureManager::addTexture(
    std::string texturePath, std::string textureName)
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
    for (auto& texture : textures) {
	texture.second.destroy();
    }
}

Chronos::Engine::Texture Chronos::Engine::TextureManager::getTexture(
    int textureNo)
{
    return textures[textureNo];
}
