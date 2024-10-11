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
#include <vector>
#include <map>
#include "animBone.hpp"
namespace Chronos {
namespace Animation {
    class AnimRig {
    public:
	void init(float x, float y);
	int addBone(int parentNo);
	void removeBone(int boneNo);
	void update();
	void addChild(int parentNo, int childNo);
	void removeChild(int parentNo, int childNo);
	void setRelX(int boneNo, float relX);
	void setRelY(int boneNo, float relY);
	void setLength(int boneNo, float length);
	void setAngle(int boneNo, float angle);
	void setParent(int boneNo, int parentNo);
	float getRelX(int boneNo);
	float getRelY(int boneNo);
	float getLength(int boneNo);
	float getAngle(int boneNo);
	float getX(int boneNo);
	float getY(int boneNo);
	int getParent(int boneNo);
	std::vector<int> getChildren(int boneNo);

    private:
	std::map<int, AnimBone> bones;
	int nextBoneNo = 0;
	AnimBone* root;
	float x;
	float y;
    };
};
};
