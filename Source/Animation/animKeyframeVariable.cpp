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

#include "animKeyframeVariable.hpp"

inline float getBezierValue(float time, float previousValue, float nextValue,
    float startPoint, float endPoint)
{
    float bezierValue = (1 - time) * (1 - time) * startPoint
	+ 2 * (1 - time) * time * endPoint + time * time;
    return previousValue + (nextValue - previousValue) * bezierValue;
}

void Chronos::Animation::KeyframeVariable::update(float dt)
{
    this->currentTime += dt;
    if (this->currentTime >= this->keyframes.back().first) {
	this->currentKeyframe = 0;
	this->currentTime = this->currentTime
	    - this->keyframes.back().first
		* (int(this->currentTime) / int(this->keyframes.back().first));
    }
    int nextKeyframe = (this->currentKeyframe + 1) % this->keyframes.size();
    while (this->keyframes[nextKeyframe].first < this->currentTime) {
	this->currentKeyframe = nextKeyframe;
	nextKeyframe = (this->currentKeyframe + 1) % this->keyframes.size();
    }
    float normalizedTime
	= (this->currentTime - this->keyframes[this->currentKeyframe].first)
	/ (this->keyframes[nextKeyframe].first
	    - this->keyframes[this->currentKeyframe].first);
    this->variable = getBezierValue(normalizedTime,
	this->keyframes[this->currentKeyframe].second,
	this->keyframes[nextKeyframe].second, 0, 1);
}

void Chronos::Animation::KeyframeVariable::updateKeyframes(
    std::vector<std::pair<float, float>> keyframes)
{
    this->keyframes = keyframes;
}

std::vector<std::pair<float, float>>
Chronos::Animation::KeyframeVariable::getKeyframes()
{
    return this->keyframes;
}

void Chronos::Animation::KeyframeVariable::setTime(float time)
{
    this->currentTime = time;
}

void Chronos::Animation::KeyframeVariable::setKeyframe(int keyframe)
{
    this->currentKeyframe = keyframe;
}

int Chronos::Animation::KeyframeVariable::getKeyframe()
{
    return this->currentKeyframe;
}

float Chronos::Animation::KeyframeVariable::getVariable()
{
    return this->variable;
}