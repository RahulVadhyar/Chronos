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

void Chronos::Animation::AnimRig::init(float x, float y)
{
    this->x = x;
    this->y = y;
    bones[nextBoneNo] = AnimBone();
    bones[nextBoneNo].init(x, y, 0, 0, nullptr);
    root = &bones[nextBoneNo];
}

int Chronos::Animation::AnimRig::addBone(int parentNo)
{
    nextBoneNo++;
    bones[nextBoneNo] = AnimBone();
    bones[nextBoneNo].init(0, 0, 0, 0, &bones[parentNo]);
    bones[parentNo].addChild(&bones[nextBoneNo]);
    return nextBoneNo;
}

void Chronos::Animation::AnimRig::removeBone(int boneNo)
{
    bones[boneNo].getParent()->removeChild(&bones[boneNo]);
    bones.erase(boneNo);
}

void Chronos::Animation::AnimRig::update()
{
    root->update();
}

void Chronos::Animation::AnimRig::addChild(int parentNo, int childNo)
{
    bones[parentNo].addChild(&bones[childNo]);
}

void Chronos::Animation::AnimRig::removeChild(int parentNo, int childNo)
{
    bones[parentNo].removeChild(&bones[childNo]);
}

void Chronos::Animation::AnimRig::setRelX(int boneNo, float relX)
{
    bones[boneNo].setRelX(relX);
}

void Chronos::Animation::AnimRig::setRelY(int boneNo, float relY)
{
    bones[boneNo].setRelY(relY);
}

void Chronos::Animation::AnimRig::setLength(int boneNo, float length)
{
    bones[boneNo].setLength(length);
}

void Chronos::Animation::AnimRig::setAngle(int boneNo, float angle)
{
    bones[boneNo].setAngle(angle);
}

void Chronos::Animation::AnimRig::setParent(int boneNo, int parentNo)
{
    bones[boneNo].setParent(&bones[parentNo]);
}

float Chronos::Animation::AnimRig::getRelX(int boneNo)
{
    return bones[boneNo].getRelX();
}

float Chronos::Animation::AnimRig::getRelY(int boneNo)
{
    return bones[boneNo].getRelY();
}

float Chronos::Animation::AnimRig::getLength(int boneNo)
{
    return bones[boneNo].getLength();
}

float Chronos::Animation::AnimRig::getAngle(int boneNo)
{
    return bones[boneNo].getAngle();
}

float Chronos::Animation::AnimRig::getX(int boneNo)
{
    return bones[boneNo].getX();
}

float Chronos::Animation::AnimRig::getY(int boneNo)
{
    return bones[boneNo].getY();
}

int Chronos::Animation::AnimRig::getParent(int boneNo)
{
    AnimBone* parent = bones[boneNo].getParent();
    if (parent == nullptr) {
        return -1;
    }
    for (auto bone : bones) {
        if (&bone.second == parent) {
            return bone.first;
        }
    }
    return -1;
}

std::vector<int> Chronos::Animation::AnimRig::getChildren(int boneNo)
{
    std::vector<int> children;
    for (auto child : bones[boneNo].getChildren()) {
        for (auto bone : bones) {
            if (&bone.second == child) {
                children.push_back(bone.first);
            }
        }
    }
    return children;
}
