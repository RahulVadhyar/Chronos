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

namespace Chronos {
namespace Animation {

    /**
     \brief Abstract class for animation objects.

    It contains the basic functions and variables needed for animation objects.
    */
    class AnimObject {
    public:
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void destroy() = 0;
        virtual void loadFromFile() = 0;
        virtual void saveToFile() = 0;
        virtual void nextFrame() = 0;
        virtual void prevFrame() = 0;
        virtual void setFrame() = 0;
        virtual void createFrame() = 0;
        virtual void changeAnimation() = 0;
    };
}
}