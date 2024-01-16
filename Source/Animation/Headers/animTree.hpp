#pragma once
/** \file animTree.hpp

 \brief Contains the structs and classes for creating and managing animation trees.
*/
#include "chronos.hpp"
namespace Chronos {
namespace Animation {
    /**
    \brief Node for animation tree

    Animation tree is similar to a normal tree. It contains nodes, each having multiple child nodes.
    Each node has the following attributes:
    - defaultShapeParams
    - polygonType
    - texturePath
    - shapeNo
    - x_rel
    - y_rel
    - name

    If we want to construct an animation tree, we must initialize the root node. Then we can add child nodes.
    Names are referenced by the animations so they must be unique and name correctly.

    The animation tree contains information about how to construct each shape, where to position it relataive to the parent node and what texture to use.
    This way the only requirement needed to construct an animation tree is the knowledge of this tree.

    For animating, animatons can be loaded and applied to this tree via various methods.

    @param defaultShapeParams The default shape parameters for the shape. This is used when constructing the shape.
    @param polygonType The polygon type of the shape. This is used when constructing the shape.
    @param texturePath The path to the texture to be used for the shape. This is used when constructing the shape
    @param shapeNo The shape number of the shape. This will be generated when constructing the shape and will be used for animating(modifying the parameters).
    @param children The children of this node.
    @param x_rel The x position of the shape relative to the parent node.
    @param y_rel The y position of the shape relative to the parent node.
    @param name The name of the shape. This is used for referencing the shape when using animations.
    */
    struct AnimNode {
        Chronos::Engine::ShapeParams defaultShapeParams;
        Chronos::Manager::PolygonType polygonType;
        std::string texturePath;
        int shapeNo;
        std::vector<AnimNode> children;
        int x_rel = 0;
        int y_rel = 0;
        std::string name;
    };

    /**
    \brief The attributes of a shape involved in animation

    The parameters of the shapes that are needed for animation are stored in this struct.

    ### Note:
    The parameters given(x, y, rotation, xSize, ySize) are relative to the parent node.
    They are not absolute positions.

    @param x The x position of the shape.
    @param y The y position of the shape.
    @param rotation The rotation of the shape.
    @param xSize The x size of the shape.
    @param ySize The y size of the shape.
    @param show Whether the shape is to be shown or not.

    */
    struct AnimShapeAttributes {
        float x;
        float y;
        float rotation;
        float xSize;
        float ySize;
        bool show;
    };

    /**
    \brief The animation tree class

    This is a wrapper around the AnimNode struct. It provides methods and attributes managing the animation tree. alogn with any animations that are applied to it.
    It can save and load animations and animation trees.
    */
    class AnimTree {
    public:

        /**
        \brief Initializes the animation tree with the given path to the .anim file.

        @param path The path to the .anim file.
        */
        AnimTree(std::string path);

        /**
        \brief Saves the animation tree to file

        @param path The path to file
        */
        void saveTree(std::string path);


        /**
        \brief Gets the root node to the animTree

        @returns The root node to the animTree
        */
        AnimNode getAnimNodes();

        /**
        \brief Gets the shape numbers of the shapes in the animation tree

        @returns The shape numbers of the shapes in the animation tree
        */
        std::vector<int> getShapeNos();

        /**
        \brief Adds an animation to the animation tree

        @param path The path to the animation file
        @return The animNo of the animation
        */
        int addAnimation(std::string path);

        /**
        \brief saves a animation to file

        @param animNo The animNo of the animation to be saved
        @param path The path to the file
        */
        void saveAnimation(int animNo, std::string path);

    private:
        int currentAnimNo = 0;
        AnimNode root;
        std::map<int, std::vector<AnimShapeAttributes>> animations;
    };
};
};