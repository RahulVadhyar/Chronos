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
#include "animManager.hpp"
#include "chronos.hpp"

void Chronos::Animation::AnimationManager::init(void* manager){
    this->manager = manager;
}

void Chronos::Animation::AnimationManager::update(){

}

void Chronos::Animation::AnimationManager::destroy(){

}

void Chronos::Animation::AnimationManager::destroyRig(int rigNo){

}

void Chronos::Animation::AnimationManager::setTime(int rigNo, float time){

}

void Chronos::Animation::AnimationManager::addBone(int rigNo, Chronos::Animation::AnimParams initialParams, int parentBoneNo){

}

void Chronos::Animation::AnimationManager::removeBone(int rigNo, int boneNo){

}

void Chronos::Animation::AnimationManager::addShape(int rigNo, int boneNo){

}

void Chronos::Animation::AnimationManager::removeShape(int rigNo, int shapeNo){

}

void Chronos::Animation::AnimationManager::bindShapeToBone(int rigNo, int shapeNo, int boneNo, float boneLocation, float shapeLocation){

}

void Chronos::Animation::AnimationManager::deleteKeyframe(int rigNo, int boneNo, int keyframeNo){

}

void Chronos::Animation::AnimationManager::setAnimation(int rigNo, int animNo){

}

void Chronos::Animation::AnimationManager::changeBoneParams(int rigNo, int boneNo, Chronos::Animation::AnimParams animParams){

}

void Chronos::Animation::AnimationManager::deleteAnimation(int rigNo, int animNo){

}

int Chronos::Animation::AnimationManager::getCurrentAnimation(int rigNo){

}

int Chronos::Animation::AnimationManager::setKeyframe(int rigNo, int boneNo){

}

int Chronos::Animation::AnimationManager::createRig(){

}

std::map<int, Chronos::Animation::AnimParams> Chronos::Animation::AnimationManager::getCurrentBoneSettings(int rigNo){

}

std::vector<int> Chronos::Animation::AnimationManager::getCurrentShapes(int rigNo){

}

std::map<int, int> Chronos::Animation::AnimationManager::getCurrentShapeToBoneBindings(int rigNo){
    
}