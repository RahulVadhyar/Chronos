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
#pragma once
namespace Chronos{
    namespace Animation{
        template<typename T>
        struct KeyFrameParams{
            float endTime;
            BezierParams<T> params;
        }
        template<typename T>
        struct AnimatedValue{
            T currentValue;
            T offsetValue;
            std::vector<KeyFrameParams<T>> keyframes;
            void updateCurrentValue(float time, T parentValue){
                float scaledTime = time*keyframes.back().endTime;
                int currentKeyframe = 0;
                for(int i = 0; i < keyframes.size(); i++){
                    if(keyframes[i].endTime > scaledTime){
                        currentKeyframe = i;
                        break;
                    }
                }
                float keyframeTime = scaledTime - keyframes[currentKeyframe - 1].endTime;
                float relativeValue = getAnimationValue(keyframeTime, keyframes[currentKeyframe].params);
                currentValue = relativeValue + offsetValue + parentValue;
            }
        }
    };
};