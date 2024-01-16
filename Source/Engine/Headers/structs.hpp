#pragma once
#include "vulkanHeaders.hpp"
/** \file structs.hpp

 \brief Contains ShapeParams and UniformBufferObject structs.
*/
namespace Chronos {
namespace Engine {

    /**
    \brief Parameters for creating a shape

    This is the struct for the parameters of a ```Shape```.
    This is needed to create and modify a ```Shape```.

    ## Note:
    In Vulkan y axis is inverted. So the y axis of the shape is inverted.
    This means that -1 is the top of the screen and 1 is the bottom of the screen.

    @param x x coordinate of the shape(Range : 0 and 1).
    @param y y coordinate of the shape(Range : 0 and 1).
    @param rotation Rotation of the shape in radians(Range: any float).
    @param xSize x scale of the shape(Range : 0 and 1).
    @param ySize y scale of the shape(Range : 0 and 1).
    @param show Show or hide the shape.
    */
    struct ShapeParams {
        float x = 0;
        float y = 0;
        float rotation = 0;
        float xSize = 1;
        float ySize = 1;
        bool show = true;
    };

    /**
    \brief Uniform struct passed to shader

    This is the uniform of the shape. This is passed to the shaders for generating the vertices in the correct positons.
    */
    struct UniformBufferObject {
        glm::mat4 model;
        glm::mat4 view;
        glm::mat4 proj;
    };
};
};