#pragma once
/** \file chronos.hpp

 \brief Main API for chronos. Any applications should include this file.
*/
#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "device.hpp"
#include "swapchain.hpp"
#include "validation.hpp"
#include "engineStructs.hpp"
#include "Vertex.hpp"
#include "helper.hpp"
#include "buffers.hpp"
#include "texture.hpp"
#include "textureManager.hpp"
#include "object.hpp"
#include "text.hpp"
#include "objectManager.hpp"
#include "textManager.hpp"
#include "commonStructs.hpp"
#include "shape.hpp"
#include "polygon.hpp"
#include "shapeManager.hpp"
#include "polygonManager.hpp"
#include "engine.hpp"
#include "engineStructs.hpp"
// this is the api for chronos. Any applications will include and link to this file

namespace Chronos {
namespace Manager {
    /**
    \brief This struct contains the details for initialing the engine.

    @param WindowWidth The initial window width. This can be later resized by the user.
    @param WindowHeight The initial window height. This can be later resized by the user.
    @param BackgroundColor The background color of the window.(range 0-255) by default it is black(0, 0, 0)
    */
    struct Initializer {
        int WindowWidth = 800;
        int WindowHeight = 600;
        int BackgroundColor[3] = { 0, 0, 0 };
#ifdef ENABLE_EDITOR
        void (*editorAddElements)();
#endif
    };

    /**
    \brief Text parameters for displaying text

    In order to display text on screen, certain parameters needs to be defined.

    @param x The x coordinate of the text position
    @param y The y coordiante of the text position
    @param rotation The rotation of the text(Degrees)
    @param text The text to be displayed
    */
    struct Text {
        float x = 0.0;
        float y = 0.0;
        float rotation = 0.0;
        float scale = 1.0;
        std::string text;
    };
    /**
    \brief Selects the polygon type to be used.

    ### Note:

    Only one one of these parameters are to be set to true, leave the others to false
    */
    struct PolygonType {
        bool triangle = false;
        bool rectangle = false;
        bool npolygon = false;
    };

    struct TextureDetails{
        std::string textureName;
        std::string texturePath;
        int textureNo;
    };

    /**
    \brief The main manager of chronos.

    Only this class must be used for interfacing with chronos. Do not use the internal classes for this
    Any changes to the window can be done via this object. Please use only the functions and variables in this class.
    For more information, refer to the individual methods and variables and the examples
    */
    class Manager {
    public:
        /**
        \brief Constructor for chronos. The initalizer struct with the necessary options to be passed.

        For options, refer to the Initializer struct
        */
        Manager(Initializer initializer);

        /**
        \brief Gets a reference to the GLFWWindow

        Since Chronos initialzes the window, along with managing it, the window is with chronos.

        However for input handling and advanced window management, chronos will not do this.
        Instead you are expected to directly call the GLFW functions and define the options yourself.

        @return The GLFWWindow instance created and used by Chronos
        */
        GLFWwindow* getWindow();

        /**
        \brief Draws the current frame to the window.

        This must called every frame during the game loop.

        This function updates all the attributes of the objects defined by the user and submitted to chronos.
        It then submits sthe necessary information to the GPU to render the frame.
        */
        void drawFrame();

        /**
        \brief Adds text to the window

        If you want to add text to the window, this function must be used.
        It returns a textNo, that is used for updating, modifyign and removing the text instance

        The necessary functions must be defined in the struct. For the options, please refer to the [Text](#Chronos::Manager::Text) struct

        @param text The necessary parameters needed for rendering text
        @return The textNo, for the text instance.
        */
        int addText(Chronos::Engine::TextParams params);

        /**
        \brief Adds a polygon(triangle or rectangle) to the window

        Use this to add a polyon(triangle or rectangle) to the window.
        Options for the shape are defined in the [ShapeParams](#Chronos::Manager::ShapeParams) struct.
        For options related to the shape, please refer the struct.
        In order to choose between triangle and rectangle, the option must be set in ```polygonType```
        A texture path must be selected

        It returns a shapeNo that can be used for modifying the shape in other functions in this class

        @param shapeParams The parameters(x, y, rotation... etc) for the shape
        @param polygonType The type of shape(triangle or rectangle)

        @return Returns the shapeNo that can be used for referencing this shape later.
        */
        int addPolygon(Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType, int texture);
        int addPolygon(Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType);
        int addPolygon(Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType, int texture, std::vector<std::array<float, 2>> vertices);


        /**
        \brief Updates the polygon with the new parameters.

        After initializing the shape, if you want to change the parameters of the shape to new attributes,
        using the shapeNo and passing the shapeParams, the new parameters can be propogated to the shape.
        The results will be displayed on the next ```drawFrame()``` call.

        @param shapeNo The shapeNo reference to the shape. Generated during ```addPolygon()`` call.
        @param shapeParams The updated shape parameters to update the shape with.
        */
        void updatePolygon(int shapeNo, Chronos::Manager::ShapeParams shapeParams);
        void updatePolygon(int shapeNo, Chronos::Manager::ShapeParams shapeParams, std::vector<std::array<float, 2>> vertices);
        std::vector<std::pair<int, Chronos::Manager::ShapeParams>> getPolygonDetails();
        std::vector<std::pair<int, Chronos::Manager::ShapeParams>> getShapeDetails();
        void updateText(int textNo, Chronos::Engine::TextParams params);

        /**
        \brief Removes the polygon from the window

        By referencing the shapeNo, the manager removes and destroys the shape from the screen.

        @param shapeNo The reference to the shape
        */
        void removePolygon(int shapeNo);

        /**
        \brief Removes the text from the window

        By referencing the textNo, the manager removes and destroys the text from the screen.
        */
        void removeText(int textNo);

        /**
        \brief Changes the background color of the window.

        If changing the background color of the window is desired, then by passing the RGB values to this function, it may be accomplished.

        @param r Red value
        @param g Green value
        @param b Blue value
        */
        int changeBackgroundColor(float r, float g, float b);

        int addTexture(std::string texturePath, std::string textureName);
        void removeTexture(int textureNo);
        std::vector<TextureDetails> getTextureDetails();

    private:
        int nextFreeAnimObjNo = 0;

        /**
        \brief The backend Vulkan engine, used for rendering the desired shapes and text.s
        */
        Chronos::Engine::Engine engine;
    };
};
};