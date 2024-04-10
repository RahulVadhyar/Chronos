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

int comb(int n, int r){
    if(r == 0 || r == n)
        return 1;
    return comb(n-1, r-1) + comb(n-1, r);
}

float Chronos::Animation::getAnimationValue(int time, BezierParams keyframe){
    float point = 0;
    for(int i = 0; i < keyframe.bezierPoints.size(); i++){
        point += comb(keyframe.bezierPoints.size() - 1, i) * keyframe.bezierPoints[i] * pow(1 - time, keyframe.bezierPoints.size() - 1 - i) * pow(time, i);
    }
    float value = keyframe.minParam + (keyframe.maxParam - keyframe.minParam) * point;
    return value;
}