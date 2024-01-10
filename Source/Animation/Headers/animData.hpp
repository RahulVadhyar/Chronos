#pragma once
#include "vulkaninit.hpp"
namespace Chronos{
    namespace Animation{
        struct AnimationShapeAttributes{
            float x;
            float y;
            float rotation;
            float xSize;
            float ySize;
            float show;
        };

        struct AnimationData{
            std::string name;
            std::vector<AnimationData> children;
            std::vector<AnimationShapeAttributes> shapeAttributes;
        };
        AnimationData loadAnimationData(std::string path);
    };
};