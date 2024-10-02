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
namespace Chronos {
namespace Animation {
    class AnimBone {
    public:
	void init(float relX, float relY, float length, float angle,
	    AnimBone* parent);
	void addChild(AnimBone* child);
	void removeChild(AnimBone* child);
	void setRelX(float relX);
	void setRelY(float relY);
	void setLength(float length);
	void setAngle(float angle);
	void setParent(AnimBone* parent);
	float getRelX();
	float getRelY();
	float getLength();
	float getAngle();
	float getX();
	float getY();
	AnimBone* getParent();
	std::vector<AnimBone*> getChildren();
	void update();

    private:
	float relX;
	float relY;
	float x;
	float y;
	float length;
	float angle;
	std::vector<AnimBone*> children;
	AnimBone* parent = nullptr;
    };
};
};
