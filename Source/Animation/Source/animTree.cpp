#include "animTree.hpp"
#include "animFileParser.hpp"

Chronos::Animation::AnimTree::AnimTree(std::string path)
{
    this->root = loadAnimTree(path);
}

Chronos::Animation::AnimNode Chronos::Animation::AnimTree::getAnimNodes()
{
    return this->root;
}

std::vector<int> Chronos::Animation::AnimTree::getShapeNos()
{
    if (root.children.size() == 0) {
        return std::vector<int> { root.shapeNo };
    }
    std::vector<int> shapeNos;
    for (auto child : root.children) {
        shapeNos.push_back(-1);
    }
    throw std::runtime_error("This function is not implemented yet");

    return shapeNos;
}

int Chronos::Animation::AnimTree::addAnimation(std::string path)
{
    // animations[currentAnimNo]= loadAnimFile(path);
    throw std::runtime_error("This function is not implemented yet");

    currentAnimNo++;
    return currentAnimNo - 1;
}

void Chronos::Animation::AnimTree::saveTree(std::string path)
{
    saveAnimTree(this->root, path);
}

void Chronos::Animation::AnimTree::saveAnimation(int animNo, std::string path)
{
    // saveAnimFile(animations[animNo], path);
    throw std::runtime_error("This function is not implemented yet");
}