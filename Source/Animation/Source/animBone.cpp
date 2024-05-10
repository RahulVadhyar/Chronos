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

void Chronos::Animation::AnimBone::update()
{
    if (parent) {
        this->x = parent->x + cos(parent->angle * std::numbers::pi / 180) * parent->length + this->relX;
        this->y = parent->y + sin(parent->angle * std::numbers::pi / 180) * parent->length + this->relY;
    } else {
        this->x = this->relX;
        this->y = this->relY;
    }
    for (Chronos::Animation::AnimBone* child : children) {
        child->update();
    }
}

void Chronos::Animation::AnimBone::init(float relX, float relY, float length, float angle, Chronos::Animation::AnimBone* parent)
{
    this->relX = relX;
    this->relY = relY;
    this->length = length;
    this->angle = angle;
    this->parent = parent;
}

void Chronos::Animation::AnimBone::addChild(Chronos::Animation::AnimBone* child)
{
    children.push_back(child);
}

void Chronos::Animation::AnimBone::removeChild(Chronos::Animation::AnimBone* child)
{
    children.erase(std::remove(children.begin(), children.end(), child), children.end());
}

void Chronos::Animation::AnimBone::setRelX(float relX)
{
    this->relX = relX;
}

void Chronos::Animation::AnimBone::setRelY(float relY)
{
    this->relY = relY;
}

void Chronos::Animation::AnimBone::setLength(float length)
{
    this->length = length;
}

void Chronos::Animation::AnimBone::setAngle(float angle)
{
    this->angle = angle;
}

void Chronos::Animation::AnimBone::setParent(Chronos::Animation::AnimBone* parent)
{
    this->parent = parent;
}

float Chronos::Animation::AnimBone::getRelX()
{
    return this->relX;
}

float Chronos::Animation::AnimBone::getRelY()
{
    return this->relY;
}

float Chronos::Animation::AnimBone::getLength()
{
    return this->length;
}

float Chronos::Animation::AnimBone::getAngle()
{
    return this->angle;
}

float Chronos::Animation::AnimBone::getX()
{
    return this->x;
}

float Chronos::Animation::AnimBone::getY()
{
    return this->y;
}

Chronos::Animation::AnimBone* Chronos::Animation::AnimBone::getParent()
{
    return this->parent;
}

std::vector<Chronos::Animation::AnimBone*> Chronos::Animation::AnimBone::getChildren()
{
    return this->children;
}
