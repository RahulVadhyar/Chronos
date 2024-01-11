#pragma once
#include "vulkaninit.hpp"
#include "animTree.hpp"

namespace Chronos{
    namespace Animation{
        std::map<std::string, std::vector<AnimShapeAttributes>> loadAnimFile(std::string path);
        void saveAnimFile(std::map<std::string, std::vector<AnimShapeAttributes>> animation, std::string path);

        AnimNode loadAnimTree(std::string path);
        void saveAnimTree(AnimNode animTree, std::string path);
    };
};
