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
#include "getFontType.hpp"

int Chronos::Manager::Manager::addText(
    Chronos::Engine::TextParams params, std::string fontType, int fontSize)
{
    if (params.text == "") {
	throw std::runtime_error("Text cannot be empty");
    }
    Chronos::Engine::Text* text = new Chronos::Engine::Text();
    text->params = params;
    Chronos::Engine::FontTypes fontStyle
	= Chronos::Engine::getFontType(fontType, fontSize);
    text->init(&this->engine.device, this->engine.commandPool,
	&(this->engine.swapChain), this->engine.objectManager.textureSampler,
	&this->engine.objectManager.renderPass, fontStyle);

    return engine.objectManager.addObject(text);
}

void Chronos::Manager::Manager::updateText(
    int objectNo, Chronos::Engine::TextParams params)
{
    if (params.text == "") {
	throw std::runtime_error("Text cannot be empty");
    }
    if (engine.objectManager.objects.count(objectNo) == 0) {
	throw std::runtime_error("Text does not exist");
    }
    if (engine.objectManager.objects[objectNo]->objectType
	!= Chronos::Engine::ObjectType::TypeText) {
	throw std::runtime_error("Object is not a text object");
    }
    ((Chronos::Engine::Text*)engine.objectManager.objects[objectNo])->params
	= params;
}

std::vector<std::pair<int, Chronos::Engine::TextParams>>
Chronos::Manager::Manager::getTextDetails()
{
    std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails;
    for (auto& text : engine.objectManager.objects) {
	if (text.second->objectType != Chronos::Engine::ObjectType::TypeText) {
	    continue;
	}
	std::pair<int, Chronos::Engine::TextParams> textDetail;
	textDetail.first = text.first;
	textDetail.second = ((Chronos::Engine::Text*)text.second)->params;
	textDetails.push_back(textDetail);
    }
    return textDetails;
}
