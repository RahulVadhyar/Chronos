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
#include "animParams.hpp"
#include "animBone.hpp"

Chronos::Animation::Bone::Bone(){
    keyframes = &animations[0];
}
Chronos::Animation::Bone::Bone(Bone* parent, AnimParams initialParams){
    this->parent = parent;
    keyframes = &animations[0];
    (*keyframes)[0] = initialParams;
    (*keyframes)[1] = initialParams;
}

void Chronos::Animation::Bone::setKeyframe(Chronos::Animation::AnimParams params, float time){
    (*keyframes)[time] = params;
}

void Chronos::Animation::Bone::removeKeyframe(float time){
    keyframes->erase(keyframes->find(time));
}

void Chronos::Animation::Bone::addChildren(Bone* childBone){
    children.insert(childBone);
}

void Chronos::Animation::Bone::removeChildren(Bone* childBone){
    children.erase(childBone);
}

Chronos::Animation::AnimParams Chronos::Animation::Bone::getParams(){
    return currentParams;
}

void Chronos::Animation::Bone::setAnimation(int animNo){
    keyframes = &animations[animNo];
}

void Chronos::Animation::Bone::updateCurrentPararms(Chronos::Animation::AnimParams params){
    currentParams = params;
}

void Chronos::Animation::Bone::deleteAnimation(int animNo){
    animations.erase(animations.find(animNo));
}