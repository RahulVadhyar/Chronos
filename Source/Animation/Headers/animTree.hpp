#pragma once
#include "chronos.hpp"
#include "stlheader.hpp"
#include "structs.hpp"
namespace Chronos {
namespace Animation {
    struct AnimNode {
        ShapeParams defaultShapeParams;
        Chronos::Manager::PolygonType polygonType;
        std::string texturePath;
        int shapeNo;
        std::vector<AnimNode> children;
        int x_rel = 0;
        int y_rel = 0;
        std::string name;
    };

    struct AnimShapeAttributes {
        float x;
        float y;
        float rotation;
        float xSize;
        float ySize;
        bool show;
    };

    class AnimTree {
    public:
        AnimTree(std::string path);
        void saveTree(std::string path);

        AnimNode getAnimNodes();
        std::vector<int> getShapeNos();
        int addAnimation(std::string path);
        void saveAnimation(int animNo, std::string path);

    private:
        int currentAnimNo = 0;
        AnimNode root;
        std::map<int, std::vector<AnimShapeAttributes>> animations;
    };
};
};