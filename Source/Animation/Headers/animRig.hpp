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
        class Rig{
        public:
            void setTime(float time);
            int addBone(Chronos::Animation::AnimParams initalParams, int parentBoneNo);
            void removeBone(int boneNo);
            void addShape(int shapeNo);
            void removeShape(int shapeNo);
            void bindShapeToBone(int shapeNo, int boneNo, float boneLocation, float shapeLocation);
            std::vector<int> getCurrentShapes();
            void setAnimation(int animNo);
            int getCurrentAnimation();
            void changeBoneParams(int boneNo, Chronos::Animation::AnimParams animParams);
            std::map<int, Chronos::Animation::AnimParams> getCurrentBoneSettings();            
            void deleteAnimation(int animNo);
            void destroy();
            int setKeyframe(int boneNo);
            void deleteKeyframe(int boneNo, int keyframeNo);
            std::map<int, int> getCurrentShapeToBoneBindings();
            void update();

        private:
            int nextFreeBoneNo = 0;
            std::map<int, Chronos::Animation::Bone> bones;
            std::map<int, Chronos::Animation::AnimShape> animShapes;    
            Chronos::Animation::Bone* root = nullptr;
            Chronos::Manager::ShapeParams baseParams;
            int currentAnimation;
            int totalAnimation;
            int currentTime;
        };
    };
};