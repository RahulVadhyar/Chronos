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
    // Chronos::Engine::Text font;
    Chronos::Engine::Text font;
    font.params = params;
    Chronos::Engine::FontTypes fontStyle
	= Chronos::Engine::getFontType(fontType, fontSize);

    return engine.textManager.addFont(font, fontStyle);
}

void Chronos::Manager::Manager::updateText(
    int textNo, Chronos::Engine::TextParams params)
{
    if (params.text == "") {
	throw std::runtime_error("Text cannot be empty");
    }
    if (engine.textManager.objects.count(textNo) == 0) {
	throw std::runtime_error("Text does not exist");
    }
    engine.textManager.objects[textNo].params = params;
}

void Chronos::Manager::Manager::removeText(int textNo)
{

    engine.textManager.remove(textNo);
}

std::vector<std::pair<int, Chronos::Engine::TextParams>>
Chronos::Manager::Manager::getTextDetails()
{
    std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails;
    for (auto& text : engine.textManager.objects) {
	std::pair<int, Chronos::Engine::TextParams> textDetail;
	textDetail.first = text.first;
	textDetail.second = text.second.params;
	textDetails.push_back(textDetail);
    }
    return textDetails;
}
