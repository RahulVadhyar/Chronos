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
#include "animBone.hpp"
#include "animManager.hpp"
#include "chronos.hpp"

void Chronos::Animation::AnimationManager::update(){
    for(auto rig : bones){
        for(auto bone : rig.second){
            bone.second.update();
        }
    }
    //TODO:update the shapes
}

std::pair<int, int> Chronos::Animation::AnimationManager::addRig(int baseShapeNo, float length){
    bones[nextFreeRigNo] = std::map<int, Chronos::Animation::AnimBone>();
    bones[nextFreeRigNo][0].init(baseShapeNo, nullptr, length);
    nextFreeBoneNos[nextFreeRigNo] = 1;
    return std::make_pair(nextFreeRigNo++, 0);
}

int Chronos::Animation::AnimationManager::addBone(int rigNo, int parentBoneNo, int shapeNo, float length){
    bones[rigNo][nextFreeBoneNos[rigNo]].init(shapeNo, &bones[rigNo][parentBoneNo], length);
    return nextFreeBoneNos[rigNo]++;
}

void Chronos::Animation::AnimationManager::setBoneOffsetX(int rigNo, int boneNo, float offsetX){
    bones[rigNo][boneNo].setOffsetX(offsetX);
}

void Chronos::Animation::AnimationManager::setBoneOffsetY(int rigNo, int boneNo, float offsetY){
    bones[rigNo][boneNo].setOffsetY(offsetY);
}

void Chronos::Animation::AnimationManager::setBoneOffsetRotation(int rigNo, int boneNo, float offsetRotation){
    bones[rigNo][boneNo].setOffsetRotation(offsetRotation);
}

void Chronos::Animation::AnimationManager::setBoneAnimNo(int rigNo, int boneNo, int animNo){
    bones[rigNo][boneNo].setAnimNo(animNo);
}

void Chronos::Animation::AnimationManager::setBoneLength(int rigNo, int boneNo, float length){
    bones[rigNo][boneNo].setLength(length);
}

float Chronos::Animation::AnimationManager::getBoneLength(int rigNo, int boneNo){
    return bones[rigNo][boneNo].getLength();
}

float Chronos::Animation::AnimationManager::getBoneAnimNo(int rigNo, int boneNo){
    return bones[rigNo][boneNo].getAnimNo();
}

float Chronos::Animation::AnimationManager::getBoneOffsetX(int rigNo, int boneNo){
    return bones[rigNo][boneNo].getOffsetX();
}

float Chronos::Animation::AnimationManager::getBoneOffsetY(int rigNo, int boneNo){
    return bones[rigNo][boneNo].getOffsetY();
}

float Chronos::Animation::AnimationManager::getBoneOffsetRotation(int rigNo, int boneNo){
    return bones[rigNo][boneNo].getOffsetRotation();
}

void Chronos::Animation::AnimationManager::addBoneKeyframe(int rigNo, int boneNo, Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe){
    bones[rigNo][boneNo].addKeyframe(xKeyframe, yKeyframe);
}

void Chronos::Animation::AnimationManager::replaceBoneKeyframe(int rigNo, int boneNo, int keyframeNo, Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe){
    bones[rigNo][boneNo].replaceKeyframe(keyframeNo, xKeyframe, yKeyframe);
}

std::pair<Chronos::Animation::BezierParams, Chronos::Animation::BezierParams> Chronos::Animation::AnimationManager::getBoneKeyframe(int rigNo, int boneNo, int keyframeNo){
    return bones[rigNo][boneNo].getKeyframe(keyframeNo);
}

void Chronos::Animation::AnimationManager::setBoneCurrentTime(int rigNo, int boneNo, float time){
    bones[rigNo][boneNo].setCurrentTime(time);
}

void Chronos::Animation::AnimationManager::updateBoneWithTime(int rigNo, int boneNo, bool flat){
    bones[rigNo][boneNo].updateWithTime(flat);
}

float Chronos::Animation::AnimationManager::getBoneCurrentTime(int rigNo, int boneNo){
    return bones[rigNo][boneNo].getCurrentTime();
}

void Chronos::Animation::AnimationManager::removeBone(int rigNo, int boneNo){
    bones[rigNo].erase(boneNo);
}

void Chronos::Animation::AnimationManager::removeRig(int rigNo){
    bones.erase(rigNo);
    nextFreeBoneNos.erase(rigNo);
}

