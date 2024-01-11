#include "animSkeleton.hpp"

/*
The animation skeleton is the set of points correlated with a
animation shape that tells the shape the positon of its childeren shapes
that has along with the hierarchy.

This is saved in a ".skel" file that has the following format

shape1{
    shape1:[0.3, 0.2]
    shape3:[0.1, 0.4]
    shape2:[0.7, 0.6]
}

shape3{
    shape4:[-0.1, 0.3]
    shape5:[0.9, 0.8]
}

As we can see each shape is defined and inside that there is the children along with
their positions relative to the parent shape. 

The data structures that this loads into is:
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

*/

AnimSkeleton loadSkeletonData(std::string path){
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open animation file for reading: " + path);
    }

    AnimSkeleton root;
    AnimSkeleton* currentSkeleton = &root;
    // std::string line;
    // while (std::getline(file, line)) {
    //     if (line.back() == '{') {
    //         // New shape definition
    //         currentSkeleton->shape = new Shape(line.substr(0, line.size() - 1).c_str());
    //     } else if (line.back() == '}') {
    //         // End of current shape definition
    //         currentSkeleton = &root;
    //     } else {
    //         // Child shape definition
    //         std::istringstream iss(line);
    //         std::string childName;
    //         float xPos, yPos;
    //         iss >> childName >> xPos >> yPos;
    //         AnimSkeletonNode node{xPos, yPos, new Shape(childName.c_str())};
    //         currentSkeleton->childrenNodes.push_back(node);
    //         currentSkeleton->childrenSkeleton[node] = AnimSkeleton();
    //         currentSkeleton = &currentSkeleton->childrenSkeleton[node];
    //     }
    // }

    return root;
}

void writeSkeletonData(AnimSkeleton skeleton, std::string path){
    throw std::runtime_error("Not implemented yet. Need to implement writeSkeletonData");
}