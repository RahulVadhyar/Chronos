#pragma once
#include "shape.hpp"
#include "objectManager.hpp"

/** \file shapeManager.hpp

 \brief Contains the class for managing shapes.
*/
namespace Chronos {
namespace Engine {

    /**
    \brief This is the shape manager for Chronos. It handles creation, modification, updating and desrtuction of shapes.

    This is for use by ```Engine``` only and should not be used for any other purpose.
    Code using Chronos should not use this class directly.
    Along with managing the shapes, its uniforms(shader variables) and its textures,
    it also providies the commandPools, commandBuffers, renderPasses, framebuffers and textureSamplers needed for rendering this as a seperate pass.

    Generally in order to manage shapes the methods to be used are:
    - ```addTriangle```
    - ```addRectangle```
    - ```removeShape```

    The rest of the methods are to be used for rendering with the ```Engine``` class and should not be used directly.
    This class creates its own renderPass for rendering the shapes.
    */
    class ShapeManager : 
    public Chronos::Engine::ObjectManager<Chronos::Engine::Shape>{
    public:
        int addTriangle(Chronos::Engine::ShapeParams shapeParams, std::string texturePath);
        int addRectangle(Chronos::Engine::ShapeParams shapeParams, std::string texturePath);
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
    };
};
};