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

#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "device.hpp"
#include "swapchain.hpp"
#include "helper.hpp"
#include "buffers.hpp"
#include "object.hpp"
#include "engineStructs.hpp"
#include "texture.hpp"
#include "text.hpp"
#include "getFontType.hpp"
#include "fontTypes.hpp"

#define FILL_FONT_STRUCT_NAME(type, size)                                      \
    Chronos::Engine::FontStructs::type##_##size

#define FONT_CASE(size)                                                        \
    case size:                                                                 \
	if (fontType == "arial")                                               \
	    return FILL_FONT_STRUCT_NAME(arial, size);                         \
	else if (fontType == "arial_bold")                                     \
	    return FILL_FONT_STRUCT_NAME(arial_bold, size);                    \
	else if (fontType == "consolas")                                       \
	    return FILL_FONT_STRUCT_NAME(consolas, size);                      \
	else if (fontType == "consolas_bold")                                  \
	    return FILL_FONT_STRUCT_NAME(consolas_bold, size);                 \
	else if (fontType == "courier")                                        \
	    return FILL_FONT_STRUCT_NAME(courier, size);                       \
	else if (fontType == "courier_bold")                                   \
	    return FILL_FONT_STRUCT_NAME(courier_bold, size);                  \
	else if (fontType == "times")                                          \
	    return FILL_FONT_STRUCT_NAME(times, size);                         \
	else if (fontType == "times_bold")                                     \
	    return FILL_FONT_STRUCT_NAME(times_bold, size);                    \
	else                                                                   \
	    throw std::runtime_error("Font type not found");                   \
	break;

Chronos::Engine::FontTypes Chronos::Engine::getFontType(
    std::string fontType, int fontSize)
{
    switch (fontSize) {
	FONT_CASE(6)
	FONT_CASE(7)
	FONT_CASE(8)
	FONT_CASE(9)
	FONT_CASE(10)
	FONT_CASE(11)
	FONT_CASE(12)
	FONT_CASE(13)
	FONT_CASE(14)
	FONT_CASE(15)
	FONT_CASE(16)
	FONT_CASE(17)
	FONT_CASE(18)
	FONT_CASE(19)
	FONT_CASE(20)
	FONT_CASE(21)
	FONT_CASE(22)
	FONT_CASE(23)
	FONT_CASE(24)
	FONT_CASE(25)
	FONT_CASE(26)
	FONT_CASE(27)
	FONT_CASE(28)
	FONT_CASE(29)
	FONT_CASE(30)
	FONT_CASE(31)
	FONT_CASE(32)
	FONT_CASE(33)
	FONT_CASE(34)
	FONT_CASE(35)
	FONT_CASE(36)
	FONT_CASE(37)
	FONT_CASE(38)
	FONT_CASE(39)
	FONT_CASE(40)
	FONT_CASE(41)
	FONT_CASE(42)
	FONT_CASE(43)
	FONT_CASE(44)
	FONT_CASE(45)
	FONT_CASE(46)
	FONT_CASE(47)
	FONT_CASE(48)
	FONT_CASE(49)
	FONT_CASE(50)
    default:
	throw std::runtime_error("Font size not found");
    }
}
