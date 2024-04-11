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
#include "animBone.hpp"
#include "animRig.hpp"
#include "animManager.hpp"

void Chronos::Animation::AnimationManager::init(){
    // Initialize the Animation Manager
}

int Chronos::Animation::AnimationManager::addRig(int x, int y){
    rigs[nextRigNo] = AnimRig();
    rigs[nextRigNo].init(x, y);  
    return nextRigNo++;
}

void Chronos::Animation::AnimationManager::removeRig(int rigNo){
    rigs.erase(rigNo);
}

void Chronos::Animation::AnimationManager::update(){
    for(auto& rig : rigs){
        rig.second.update();
    }
}

void Chronos::Animation::AnimationManager::addBone(int rigNo, int parentNo){
    rigs[rigNo].addBone(parentNo);
}

void Chronos::Animation::AnimationManager::removeBone(int rigNo, int boneNo){
    rigs[rigNo].removeBone(boneNo);
}

void Chronos::Animation::AnimationManager::addChild(int rigNo, int parentNo, int childNo){
    rigs[rigNo].addChild(parentNo, childNo);
}

void Chronos::Animation::AnimationManager::removeChild(int rigNo, int parentNo, int childNo){
    rigs[rigNo].removeChild(parentNo, childNo);
}

void Chronos::Animation::AnimationManager::setRelX(int rigNo, int boneNo, float relX){
    rigs[rigNo].setRelX(boneNo, relX);
}

void Chronos::Animation::AnimationManager::setRelY(int rigNo, int boneNo, float relY){
    rigs[rigNo].setRelY(boneNo, relY);
}

void Chronos::Animation::AnimationManager::setLength(int rigNo, int boneNo, float length){
    rigs[rigNo].setLength(boneNo, length);
}

void Chronos::Animation::AnimationManager::setAngle(int rigNo, int boneNo, float angle){
    rigs[rigNo].setAngle(boneNo, angle);
}

void Chronos::Animation::AnimationManager::setParent(int rigNo, int boneNo, int parentNo){
    rigs[rigNo].setParent(boneNo, parentNo);
}

float Chronos::Animation::AnimationManager::getRelX(int rigNo, int boneNo){
    return rigs[rigNo].getRelX(boneNo);
}

float Chronos::Animation::AnimationManager::getRelY(int rigNo, int boneNo){
    return rigs[rigNo].getRelY(boneNo);
}

float Chronos::Animation::AnimationManager::getLength(int rigNo, int boneNo){
    return rigs[rigNo].getLength(boneNo);
}

float Chronos::Animation::AnimationManager::getAngle(int rigNo, int boneNo){
    return rigs[rigNo].getAngle(boneNo);
}

float Chronos::Animation::AnimationManager::getX(int rigNo, int boneNo){
    return rigs[rigNo].getX(boneNo);
}

float Chronos::Animation::AnimationManager::getY(int rigNo, int boneNo){
    return rigs[rigNo].getY(boneNo);
}

int Chronos::Animation::AnimationManager::getParent(int rigNo, int boneNo){
    return rigs[rigNo].getParent(boneNo);
}

std::vector<int> Chronos::Animation::AnimationManager::getChildren(int rigNo, int boneNo){
    return rigs[rigNo].getChildren(boneNo);
}
