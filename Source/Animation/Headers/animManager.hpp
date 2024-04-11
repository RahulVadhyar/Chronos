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
            std::pair<int, int> addRig(int baseShapeNo, float length);
            int addBone(int rigNo, int parentBoneNo, int shapeNo, float length);
            void setBoneOffsetX(int rigNo, int boneNo, float offsetX);
            void setBoneOffsetY(int rigNo, int boneNo, float offsetY);
            void setBoneOffsetRotation(int animNo, int boneNo, float offsetRotation);
            void setBoneAnimNo(int rigNo, int boneNo, int animNo);
            void setBoneLength(int rigNo, int boneNo, float length);
            float getBoneLength(int rigNo, int boneNo);
            float getBoneAnimNo(int rigNo, int boneNo);
            float getBoneOffsetX(int rigNo, int boneNo);
            float getBoneOffsetY(int rigNo, int boneNo);
            float getBoneOffsetRotation(int rigNo, int boneNo);
            void addBoneKeyframe(int rigNo, int boneNo, Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe);
            void replaceBoneKeyframe(int rigNo, int boneNo, int keyframeNo, Chronos::Animation::BezierParams xKeyframe, Chronos::Animation::BezierParams yKeyframe);
            std::pair<Chronos::Animation::BezierParams, Chronos::Animation::BezierParams> getBoneKeyframe(int rigNo, int boneNo, int keyframeNo);
            void setBoneCurrentTime(int rigNo, int boneNo, float time);
            void updateBoneWithTime(int rigNo, int boneNo, bool flat);
            float getBoneCurrentTime(int rigNo, int boneNo);
            void removeBone(int rigNo, int boneNo);
            void removeRig(int rigNo);
        private:
            void* manager;
            std::map<int, std::map<int, Chronos::Animation::AnimBone>> bones;
            std::map<int, Chronos::Animation::AnimBone> rootBones;
            std::map<int, int> nextFreeBoneNos;
            int nextFreeRigNo = 0;
        };
    };
};