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
#pragma once

/**
\file commonStructs.hpp
\brief Header file that contains common structs used in Chronos.
*/
namespace Chronos {
namespace Manager {
    /**
    \brief Parameters for creating a shape(any)

    This is the struct for the parameters of a Shape.
    This is needed to create and modify a Shape.

    ## Note:
    In Vulkan y axis is inverted. So the y axis of the shape is inverted.
    This means that -1 is the top of the screen and 1 is the bottom of the screen.

    @param x x coordinate of the shape(Range : 0 and 1).
    @param y y coordinate of the shape(Range : 0 and 1).
    @param rotation Rotation of the shape in degrees(Range: any float).
    @param xSize x scale of the shape(Range : 0 and 1).
    @param ySize y scale of the shape(Range : 0 and 1).
    @param show Show or hide the shape.
    @param color Color of the shape(Range : 0 and 1).
    @param shapeName Name of the shape(must be unique).
    */
    struct ShapeParams {
        float x = 0;
        float y = 0;
        float rotation = 0;
        float xSize = 1;
        float ySize = 1;
        bool show = true;
        std::array<float, 3> color = { 1.0f, 0.0f, 0.0f };
        char shapeName[200] = "Shape";
    };

}
}