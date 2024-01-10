#include "animObject.hpp"
#include "animData.hpp"
Chronos::Animation::AnimObject::AnimObject(int shapeNo, int animObjNo, Shape* shape){
    this->shapeNo = shapeNo;
    this->animObjNo = animObjNo;
    this->shape = shape;
}

Chronos::Animation::AnimObject::AnimObject(){
    shapeNo = -1;
    animObjNo = -1;
    shape = nullptr;
}

void Chronos::Animation::AnimObject::addChild(AnimObject* child){
    children.push_back(child);
    child->setParent(this);
}

void Chronos::Animation::AnimObject::removeChild(AnimObject* child){
    for(int i = 0; i < children.size(); i++){
        if(children[i] == child){
            children.erase(children.begin() + i);
            break;
        }
    }
    child->setParent(nullptr);
}   

int Chronos::Animation::AnimObject::addAnimation(std::string animationFile){
    int animNo = nextFreeAnimNo;
    nextFreeAnimNo++;
    animations[animNo] = loadAnimationData(animationFile);
    return animNo;
}

void Chronos::Animation::AnimObject::removeAnimation(int animNo){
    if(animations.count(animNo) > 0){
        animations.erase(animNo);
    }
}

void Chronos::Animation::AnimObject::setParent(AnimObject* parent){
    this->parent = parent;
}