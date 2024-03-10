#pragma once
/** \file engineStructs.hpp

 \brief Contains ShapeParams and UniformBufferObject structs.
*/
namespace Chronos {
namespace Engine {
    /**
    \brief Parameters for rendering text

    This is the struct for the parameters of a ```Font```.
    This is needed to create and modify a ```Font```.

    ## Note:
    In Vulkan y axis is inverted. So the y axis of the shape is inverted.
    This means that -1 is the top of the screen and 1 is the bottom of the screen.

    @param x x coordinate of the text(Range : 0 and 1).
    @param y y coordinate of the text(Range : 0 and 1).
    @param rotation Rotation of the text in degrees(Range: any float).
    @param scale Scale of the text(Range : any float).
    @param text The text to render.
    */
    struct TextParams {
        std::string text;
        float x = 0;
        float y = 0;
        float rotation = 0;
        float scale = 1.0f;
        std::array<float, 3> color = {1.0f, 1.0f, 1.0f};
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

    struct UniformColorBufferObject {
        glm::vec3 color;
    };
};
};