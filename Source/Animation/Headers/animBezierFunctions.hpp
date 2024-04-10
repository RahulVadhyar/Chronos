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
        struct BezierParams{
            int totalTime;
            float minParam;
            float maxParam;
            std::vector<float> bezierPoints;
        };

        /*
        https://en.wikipedia.org/wiki/B%C3%A9zier_curve
        We need to compute the bezier curve value for the given time. 
        The points are keyframes(P(i)) and time(t) is the operator.
        We have n keyframes. From the above link, we can see that the formula for the bezier curve is:
        F(n) = SUM(i=0 to n) nCi * (1-t)^(n-i) * t^i * P(i)
        where nCi is the binomial coefficient.
        After that we scale it to the value range.
        */
        float getAnimationValue(int time, BezierParams keyframe);
    };
};
