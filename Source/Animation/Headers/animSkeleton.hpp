#include "vulkaninit.hpp"
#include "shape.hpp"

struct AnimSkeletonNode{
    float xPos;
    float yPos;
    Shape* shape;
};
struct AnimSkeleton{
    Shape* shape;
    std::vector<AnimSkeletonNode> childrenNodes;
    std::map<AnimSkeletonNode, AnimSkeleton> childrenSkeleton;
};

AnimSkeleton loadSkeletonData(std::string path);
void writeSkeletonData(AnimSkeleton skeleton, std::string path);