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
        class AnimationManager{
        
        public:
        
            void init(void* manager);
            void update();
            int createRig();
            void destroy();
            void destroyRig(int rigNo);
            void setTime(int rigNo, float time);
            void addBone(int rigNo, Chronos::Animation::AnimParams initialParams, int parentBoneNo);
            void removeBone(int rigNo, int boneNo);
            void addShape(int rigNo, int boneNo);
            void removeShape(int rigNo, int shapeNo);
            void bindShapeToBone(int rigNo, int shapeNo, int boneNo, float boneLocation, float shapeLocation);
            std::vector<int> getCurrentShapes(int rigNo);
            void setAnimation(int rigNo, int animNo);
            int getCurrentAnimation(int rigNo);
            void changeBoneParams(int rigNo, int boneNo, Chronos::Animation::AnimParams animParams);
            std::map<int, Chronos::Animation::AnimParams> getCurrentBoneSettings(int rigNo);
            void deleteAnimation(int rigNo, int animNo);   
            int setKeyframe(int rigNo, int boneNo);
            void deleteKeyframe(int rigNo, int boneNo, int keyframeNo);
            std::map<int, int> getCurrentShapeToBoneBindings(int rigNo);
                        
        private:
            void* manager;
            std::vector<Chronos::Animation::Rig> animRigs;
        };
    };
};