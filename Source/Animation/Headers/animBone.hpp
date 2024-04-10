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
        class AnimBone{
        public:
            void init(int shapeNo, AnimBone* parent, float length);
            void setOffsetX(float offsetX);
            void setOffsetY(float offsetY);
            void setOffsetRotation(float offsetRotation);
            void setAnimNo(int animNo);
            void setLength(float length);
            float getLength();
            float getAnimNo();
            float getOffsetX();
            float getOffsetY();
            float getOffsetRotation();
            void addKeyframe(Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe);
            void replaceKeyframe(int keyframeNo, Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe);
            std::pair<Chronos::Animation::BezierParams, Chronos::Animation::BezierParams> getKeyframe(int keyframeNo);
            void update();
            void addChild(AnimBone* child);
            void removeChild(AnimBone* child);
            void setCurrentTime(int time);
            float getCurrentTime();
            void updateWithTime(bool flat);
        private:
            bool updateWithTimeFlag = true;
            float x;
            float y;
            float length;
            float offsetX;
            float offsetY;
            float offsetRotation;
            int shapeNo;
            int animNo;
            AnimBone* parent;
            std::map<int, Chronos::Animation::BezierParams> xKeyframes, yKeyframes;
            std::chrono::steady_clock::time_point prevTime;
            std::vector<AnimBone*> children;
        };
    };
};