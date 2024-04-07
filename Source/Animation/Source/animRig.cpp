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
#include "animShape.hpp"
#include "animRig.hpp"

void Chronos::Animation::Rig::setTime(float time){
    this->currentTime = time;
}

int Chronos::Animation::Rig::addBone(Chronos::Animation::AnimParams initalParams, int parentBoneNo){
    this->bones[this->nextFreeBoneNo++] = Chronos::Animation::Bone(&this->bones[parentBoneNo], initalParams);
    return this->nextFreeBoneNo - 1;
}

void Chronos::Animation::Rig::removeBone(int boneNo){
    this->bones.erase(this->bones.find(boneNo));
}

void Chronos::Animation::Rig::addShape(int shapeNo){
    this->animShapes[shapeNo] = Chronos::Animation::AnimShape(shapeNo);
}

void Chronos::Animation::Rig::removeShape(int shapeNo){
    this->animShapes.erase(this->animShapes.find(shapeNo));
}

void Chronos::Animation::Rig::bindShapeToBone(int shapeNo, int boneNo, float boneLocation, float shapeLocation){
    this->animShapes[shapeNo].setBindLocation(&this->bones[boneNo], boneLocation, shapeLocation);
}

std::vector<int> Chronos::Animation::Rig::getCurrentShapes(){
    std::vector<int> currentShapes;
    for(auto& shape : this->animShapes){
        currentShapes.push_back(shape.first);
    }
    return currentShapes;
}

void Chronos::Animation::Rig::setAnimation(int animNo){
    this->currentAnimation = animNo;
    for(auto& bone : this->bones){
        bone.second.setAnimation(animNo);
    }
}

int Chronos::Animation::Rig::getCurrentAnimation(){
    return this->currentAnimation;
}

void Chronos::Animation::Rig::changeBoneParams(int boneNo, Chronos::Animation::AnimParams animParams){
    this->bones[boneNo].updateCurrentPararms(animParams);
}

std::map<int, Chronos::Animation::AnimParams> Chronos::Animation::Rig::getCurrentBoneSettings(){
    std::map<int, Chronos::Animation::AnimParams> boneSettings;
    for(auto& bone : this->bones){
        boneSettings[bone.first] = bone.second.getParams();
    }
    return boneSettings;
}

void Chronos::Animation::Rig::deleteAnimation(int animNo){
    for(auto& bone : this->bones){
        bone.second.deleteAnimation(animNo);
    }
}