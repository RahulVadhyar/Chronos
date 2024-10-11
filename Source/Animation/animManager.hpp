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
#include <map>
#include "animKeyframeVariable.hpp"
#include "animRig.hpp"
namespace Chronos {
namespace Animation {
    class AnimationManager {
    public:
	// applicable to all
	void update();

	// applicable to rig
	int addRig(int x, int y);
	void removeRig(int rigNo);
	void rigAddBone(int rigNo, int parentNo);
	void rigRemoveBone(int rigNo, int boneNo);
	void rigAddChild(int rigNo, int parentNo, int childNo);
	void rigRemoveChild(int rigNo, int parentNo, int childNo);
	void rigSetRelX(int rigNo, int boneNo, float relX);
	void rigSetRelY(int rigNo, int boneNo, float relY);
	void rigSetLength(int rigNo, int boneNo, float length);
	void rigSetAngle(int rigNo, int boneNo, float angle);
	void rigSetParent(int rigNo, int boneNo, int parentNo);
	float rigGetRelX(int rigNo, int boneNo);
	float rigGetRelY(int rigNo, int boneNo);
	float rigGetLength(int rigNo, int boneNo);
	float rigGetAngle(int rigNo, int boneNo);
	float rigGetX(int rigNo, int boneNo);
	float rigGetY(int rigNo, int boneNo);
	int rigGetParent(int rigNo, int boneNo);
	std::vector<int> rigGetChildren(int rigNo, int boneNo);

	// applicable to keyframe
	int addKeyframeVariable(std::vector<std::pair<float, float>> keyframes);
	void removeKeyframeVariable(int keyframeNo);
	void keyframeSetTime(int keyframeNo, float time);
	void keyframeSetKeyframe(int keyframeNo, int keyframe);
	int keyframeGetKeyframe(int keyframeNo);
	std::vector<std::pair<float, float>> getKeyframes(int keyframeNo);
	float keyframeGetVariable(int keyframeNo);

    private:
	std::map<int, Chronos::Animation::AnimRig> rigs;
	int nextRigNo = 0;

	std::map<int, Chronos::Animation::KeyframeVariable> keyframeVariables;
	int nextKeyframeNo = 0;
    };
};
};
