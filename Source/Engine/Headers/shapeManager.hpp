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

    Generally in order to manage shapes the methods to be used are:
    - ```addTriangle```
    - ```addRectangle```
    - ```remove``
    
    Inherits from Object Manager. All the public methods defined in that class is also available. 
    It includes the following functions for internal use
    -init
    -destroy
    -update
    -render
    -changeMsaa
    -recreate

    For more details on these functions, please reference the [ObjectManger](Chronos::Engine::ObjectManager) class

    */
    class ShapeManager : 
    public Chronos::Engine::ObjectManager<Chronos::Engine::Shape>{
    public:

        /**
        \brief Adds a triangle to the shape manager. 
        
        Necessary shapeParams and texture path must be provided. 
        Supported textures are .jpg and .png
        Returns a shapeNo that references the shape for modifying and destroying t.
        */
        int addTriangle(Chronos::Engine::ShapeParams shapeParams, std::string texturePath);
        int addRectangle(Chronos::Engine::ShapeParams shapeParams, std::string texturePath);
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
    };
};
};