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
#include "animBezierFunctions.hpp"
#include <chrono>
#include "animBone.hpp"

void Chronos::Animation::AnimBone::update(){
    if(updateWithTimeFlag){
        static auto startTimer = std::chrono::steady_clock::now();
        int time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - startTimer).count();
        time %= xKeyframes[animNo].totalTime;
        this->x = Chronos::Animation::getAnimationValue(time, xKeyframes[animNo]);
        this->y = Chronos::Animation::getAnimationValue(time, yKeyframes[animNo]);
    }
    if(parent){
        auto rotation = std::atan(this->y/this->x);
        this->x = (parent->x + this->length*std::cos(rotation)) + this->x;
        this->y = (parent->y + this->length*std::sin(rotation)) + this->y;
    }   
    for(auto child: children){
        child->update();
    }
}

void Chronos::Animation::AnimBone::addChild(AnimBone* child){
    this->children.push_back(child);
}

void Chronos::Animation::AnimBone::removeChild(AnimBone* child){
    this->children.erase(std::remove(this->children.begin(), this->children.end(), child), this->children.end());
}

void Chronos::Animation::AnimBone::init(int shapeNo, AnimBone* parent, float length){
    this->shapeNo = shapeNo;
    this->parent = parent;
    this->length = length;
    this->x = 0;
    this->y = 0;
    this->offsetX = 0;
    this->offsetY = 0;
    this->offsetRotation = 0;
    this->animNo = 0;
    this->prevTime = std::chrono::steady_clock::now();
}

void Chronos::Animation::AnimBone::setOffsetX(float offsetX){
    this->offsetX = offsetX;
}

void Chronos::Animation::AnimBone::setOffsetY(float offsetY){
    this->offsetY = offsetY;
}

void Chronos::Animation::AnimBone::setOffsetRotation(float offsetRotation){
    this->offsetRotation = offsetRotation;
}

void Chronos::Animation::AnimBone::setAnimNo(int animNo){
    this->animNo = animNo;
}

void Chronos::Animation::AnimBone::setLength(float length){
    this->length = length;
}

float Chronos::Animation::AnimBone::getLength(){
    return this->length;
}

float Chronos::Animation::AnimBone::getAnimNo(){
    return this->animNo;
}

float Chronos::Animation::AnimBone::getOffsetX(){
    return this->offsetX;
}

float Chronos::Animation::AnimBone::getOffsetY(){
    return this->offsetY;
}

float Chronos::Animation::AnimBone::getOffsetRotation(){
    return this->offsetRotation;
}

void Chronos::Animation::AnimBone::addKeyframe(Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe){
    this->xKeyframes[this->animNo] = xKeyframe;
    this->yKeyframes[this->animNo] = yKeyframe;
}

void Chronos::Animation::AnimBone::replaceKeyframe(int keyframeNo, Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe){
    this->xKeyframes[keyframeNo] = xKeyframe;
    this->yKeyframes[keyframeNo] = yKeyframe;
}

std::pair<Chronos::Animation::BezierParams, Chronos::Animation::BezierParams> Chronos::Animation::AnimBone::getKeyframe(int keyframeNo){
    return std::make_pair(this->xKeyframes[keyframeNo], this->yKeyframes[keyframeNo]);
}

void Chronos::Animation::AnimBone::setCurrentTime(int time){

    // this->prevTime = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::duration_since_epoch(time));
}

float Chronos::Animation::AnimBone::getCurrentTime(){
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - this->prevTime).count();
}

void Chronos::Animation::AnimBone::updateWithTime(bool flat){
    this->updateWithTimeFlag = flat;
}