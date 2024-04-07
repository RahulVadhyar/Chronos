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

#include "chronos.hpp"

int Chronos::Manager::Manager::addTexture(std::string texturePath, std::string textureName)
{
    bool textureExists = false;
    for (auto& textureDetail : getTextureDetails()) {
        if (textureDetail.textureName == textureName) {
            textureExists = true;
            break;
        }
    }
    return engine.textureManager.addTexture(texturePath, textureName);
}
void Chronos::Manager::Manager::removeTexture(int textureNo)
{
    engine.textureManager.removeTexture(textureNo);
}

std::vector <Chronos::Manager::TextureDetails> Chronos::Manager::Manager::getTextureDetails()
{
    std::vector<Chronos::Manager::TextureDetails> textureDetails;
    for (auto& texture : engine.textureManager.textures)
    {
        Chronos::Manager::TextureDetails details;
        details.textureNo = texture.first;
        details.textureName = texture.second.textureName;
        details.texturePath = texture.second.texturePath;
        details.height = texture.second.height;
        details.width = texture.second.width;
        #ifdef ENABLE_EDITOR
        details.descriptorSet = texture.second.descriptorSet;
        #endif
        textureDetails.push_back(details);
    }
    return textureDetails;

}