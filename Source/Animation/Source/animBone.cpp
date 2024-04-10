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
#include "commonStructs.hpp"
#include "animBezierFunctions.hpp"
#include "animParams.hpp"
#include "animBone.hpp"

void Chronos::Animation::Bone::addChildren(Bone* childBone){
    children.insert(childBone);
}

void Chronos::Animation::Bone::removeChildren(Bone* childBone){
    children.erase(childBone);
}

void Chronos::Animation::Bone::getBoneParams(float* x, float* y, float* rotation, float* length){
    *x = xKeyframes.currentValue;
    *y = yKeyframes.currentValue;
    *rotation = rotationKeyframes.currentValue;
    *length = this->length;
}

void Chronos::Animation::Bone::update(float time, float x, float y, float rotation){
    //time - between 0 and 1
    this->xKeyframes.updateCurrentValue(time, x);
    this->yKeyframes.updateCurrentValue(time, y);
    this->rotationKeyframes.updateCurrentValue(time, rotation);

    for(Bone* child : children){
        child->update(time, x, y, rotation);
    }
}