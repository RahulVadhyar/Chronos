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
            void init();
            int addRig(int x, int y);
            void removeRig(int rigNo);
            void update();
            void addBone(int rigNo, int parentNo);
            void removeBone(int rigNo, int boneNo);
            void addChild(int rigNo, int parentNo, int childNo);
            void removeChild(int rigNo, int parentNo, int childNo);
            void setRelX(int rigNo, int boneNo, float relX);
            void setRelY(int rigNo, int boneNo, float relY);
            void setLength(int rigNo, int boneNo, float length);
            void setAngle(int rigNo, int boneNo, float angle);
            void setParent(int rigNo, int boneNo, int parentNo);
            float getRelX(int rigNo, int boneNo);
            float getRelY(int rigNo, int boneNo);
            float getLength(int rigNo, int boneNo);
            float getAngle(int rigNo, int boneNo);
            float getX(int rigNo, int boneNo);
            float getY(int rigNo, int boneNo);
            int getParent(int rigNo, int boneNo);
            std::vector<int> getChildren(int rigNo, int boneNo);
        private:
            std::map<int, AnimRig> rigs;
            int nextRigNo = 0;
        
        };
    };
};
