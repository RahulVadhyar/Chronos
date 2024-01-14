/** \file animFileParser.hpp

 \brief Contains the functions for loading and saving animation trees and animations to and from files.
*/
#pragma once
#include "animTree.hpp"

namespace Chronos {
namespace Animation {

    /**
    \brief Loads an animaton file from the given path.

    The animation file is a .anim file that contains the animation data for each shape in an animation tree.
    This function loads the animation file and returns a map from the shape name to the animation data for that shape.
    The animation files will be saved as .anim file. The format shall strictly adhere to such a format

            Head{
            [0, 0, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            }
            Body{
            [0, 0, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            }
            Hand1{
            [0, 0, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            }
            Hand2{
            [0, 0, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            [0.1, -0.32, 0, 0.5, 0.5, true]
            }

    */
    std::map<std::string, std::vector<AnimShapeAttributes>> loadAnimFile(std::string path);

    /**
    \brief Saves an animation to a .anim in given file.

    The animation file is a .anim file that contains the animation data for each shape in an animation tree.
    For more information, see the loadAnimFile function.
    */
    void saveAnimFile(std::map<std::string, std::vector<AnimShapeAttributes>> animation, std::string path);

    /**
    \brief Loads an animation tree from the given path.

    An animation tree defines how the shapes are related to each other. It is a tree of shapes.
    The initial position, relative positions and texture path along with the type of shape(Triangle or Rectangle) is defined in the animation tree.
    Hence given this animation tree, we can create the shape, render and animate them.

    The AnimTree file will be saved as a .skel file. A sample file of such type will be strictly as follows:
            body{
            Type: Triangle
            TexturePath: "Assets/texture.png"
            [0.1, -0.1, 0.4, 0.6, 0.7, true]
            {
            head:[0.3, 0.2],
            leg1:[0.7, 0.6],
            leg2:[0.1, 0.4],
            }
            }

            leg1{
            Type: Rectangle
            TexturePath: "Assets/texture.png"
            [0.2, -0.16, 0.38, 0.12, -0.7, true]
            {
            foot1:[0.3, 0.2],
            foot2:[0.1, 0.4],
            }
            }

            head{
            Type: Rectangle
            TexturePath: "Assets/texture.png"
            [0.2, -0.16, 0.38, 0.12, -0.7, true]
            }

            foot1{
            Type: Rectangle
            TexturePath: "Assets/texture.png"
            [0.2, -0.16, 0.38, 0.12, -0.7, true]
            }

            foot2{
            Type: Rectangle
            TexturePath: "Assets/texture.png"
            [0.2, -0.16, 0.38, 0.12, -0.7, true]
            }

    */
    AnimNode loadAnimTree(std::string path);

    /**
    \brief Saves an animation tree to a .skel file in given file.

    An animation tree defines how the shapes are related to each other. It is a tree of shapes.
    For more information, see the loadAnimTree function.
    */
    void saveAnimTree(AnimNode animTree, std::string path);
};
};
