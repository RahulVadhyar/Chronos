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

/**
\file fontTypes.hpp

\brief Defines all thes structs for all the font types and their sizes.

Using macros, this includes the structs for all the font types and their sizes.
This is so that the user can use any font type and size they want.

Font sizes range from 6 to 50.

The font types are:
- arial
- arial_bold
- consolas
- consolas_bold
- courier
- courier_bold
- times
- times_bold
*/
#pragma once
#include "multiFontInclude.hpp"

#define FONT_STRUCT(type, size) \
FontTypes type ## _ ## size { \
    STB_FONT_ ## type ## _ ## size ## _latin1_BITMAP_WIDTH, \
    STB_FONT_ ## type ## _ ## size ## _latin1_BITMAP_HEIGHT, \
    stb_font_ ## type ## _ ## size ## _latin1, \
    STB_FONT_ ## type ## _ ## size ## _latin1_FIRST_CHAR, \
    STB_FONT_ ## type ## _ ## size ## _latin1_NUM_CHARS, \
}

#define GEN_FONT_STRUCTS(type) \
    FONT_STRUCT(type, 6); \
    FONT_STRUCT(type, 7); \
    FONT_STRUCT(type, 8); \
    FONT_STRUCT(type, 9); \
    FONT_STRUCT(type, 10); \
    FONT_STRUCT(type, 11); \
    FONT_STRUCT(type, 12); \
    FONT_STRUCT(type, 13); \
    FONT_STRUCT(type, 14); \
    FONT_STRUCT(type, 15); \
    FONT_STRUCT(type, 16); \
    FONT_STRUCT(type, 17); \
    FONT_STRUCT(type, 18); \
    FONT_STRUCT(type, 19); \
    FONT_STRUCT(type, 20); \
    FONT_STRUCT(type, 21); \
    FONT_STRUCT(type, 22); \
    FONT_STRUCT(type, 23); \
    FONT_STRUCT(type, 24); \
    FONT_STRUCT(type, 25); \
    FONT_STRUCT(type, 26); \
    FONT_STRUCT(type, 27); \
    FONT_STRUCT(type, 28); \
    FONT_STRUCT(type, 29); \
    FONT_STRUCT(type, 30); \
    FONT_STRUCT(type, 31); \
    FONT_STRUCT(type, 32); \
    FONT_STRUCT(type, 33); \
    FONT_STRUCT(type, 34); \
    FONT_STRUCT(type, 35); \
    FONT_STRUCT(type, 36); \
    FONT_STRUCT(type, 37); \
    FONT_STRUCT(type, 38); \
    FONT_STRUCT(type, 39); \
    FONT_STRUCT(type, 40); \
    FONT_STRUCT(type, 41); \
    FONT_STRUCT(type, 42); \
    FONT_STRUCT(type, 43); \
    FONT_STRUCT(type, 44); \
    FONT_STRUCT(type, 45); \
    FONT_STRUCT(type, 46); \
    FONT_STRUCT(type, 47); \
    FONT_STRUCT(type, 48); \
    FONT_STRUCT(type, 49); \
    FONT_STRUCT(type, 50); 

namespace Chronos{
    namespace Engine{

namespace FontStructs{
GEN_FONT_STRUCTS(arial)
GEN_FONT_STRUCTS(arial_bold)
GEN_FONT_STRUCTS(consolas)
GEN_FONT_STRUCTS(consolas_bold)
GEN_FONT_STRUCTS(courier)
GEN_FONT_STRUCTS(courier_bold)
GEN_FONT_STRUCTS(times)
GEN_FONT_STRUCTS(times_bold)
};
    };
};
