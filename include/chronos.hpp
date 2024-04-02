#pragma once
/** \file chronos.hpp

 \brief Main API for chronos. Any applications should include this file.
*/
#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "logging.hpp"
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

namespace Chronos {
namespace Manager {
    /**
    \brief This struct contains the details for initialing the manager.

    @param WindowWidth The initial window width. This can be later resized by the user.
    @param WindowHeight The initial window height. This can be later resized by the user.
    @param BackgroundColor The background color of the window.(range 0-255) by default it is black(0, 0, 0)
    */
    struct Initializer {
        int WindowWidth = 800;
        int WindowHeight = 600;
        int BackgroundColor[3] = { 0, 0, 0 };
#ifdef ENABLE_EDITOR
        //function pointer for calling the function that will render the editor elements on the screen
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
        std::string text = "";
    };
    /**
    \brief Selects the polygon type to be used.

    ### Note:

    Only one one of these parameters are to be set to true, leave the others to false

    @param triangle Triangle shape
    @param rectangle Rectangle shape
    @param npolygon Custom polygon shape using user defined vertices. This can be defined during creation of the polygon.
    */
    struct PolygonType {
        bool triangle = false;
        bool rectangle = false;
    };

    /**
    \brief Holds some details about the texture. 

    When the details of texture is requested, this struct is returned.
    
    ##Note:
    The textureName must be unique. If the textureName is already present, then the texture will not be added.

    @param textureName The name of the texture referenced by the editor and can be used for identifying the texture.
    @param texturePath The path of the texture
    @param textureNo The reference number of the texture. This is used for referencing the texture in other functions.
    */
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
        One may select the fontType and fontSize from the available options. The fontType and fontSize must be selected from the available options.
        Font size may be from 6 to 50. The fontType may be one of the following:
        - arial
        - arial_bold
        - consolas
        - consolas_bold
        - courier
        - courier_bold
        - times
        - times_bold

        An example of how this function is called is:
        ```
        addText(params, "arial", 12);
        ```
        In the above, params refer to the text parameters that are assumed to be defined and filled.
        The necessary functions must be defined in the struct. For the options, please refer to the [Text](#Chronos::Manager::Text) struct

        @param params The necessary parameters needed for rendering text
        @return The textNo, for the text instance.
        */
        int addText(Chronos::Engine::TextParams params, std::string fontType, int fontSize);

        /**
        \brief Adds a textured shape(triangle or rectangle) to the window

        Use this to add a shape(triangle or rectangle) to the window.
        Please note that this function only supports textured shapes. 

        Options for the shape are defined in the [ShapeParams](#Chronos::Manager::ShapeParams) struct.
        The color field in the struct is not used, It can be skipped. The texture field must be set to the textureNo of the texture to be used.
        For options related to the shape, please refer the struct.
        In order to choose between triangle and rectangle, the option must be set in ```polygonType```.
        Do not select npolygon, as it is not supported in this function.
        A texture path must be selected.
        To add other types of shapes, such as colored or npolygon, use the other overrides available.

        It returns a shapeNo that can be used for modifying the shape in other functions in this class

        @param shapeParams The parameters(x, y, rotation... etc) for the shape
        @param polygonType The type of shape(triangle or rectangle)
        @param texture The textureNo of the texture to be used

        @return Returns the shapeNo that can be used for referencing this shape later.
        */
        int addPolygon(Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType, int texture);

        /**
        \brief Adds a soild color shape(triangle or rectangle) to the window

        Use this to add a shape(triangle or rectangle) to the window.
        Please note that this function only supports solid color shapes. 

        Options for the shape are defined in the [ShapeParams](#Chronos::Manager::ShapeParams) struct.
        The color field in the struct must be filled.
        For options related to the shape, please refer the struct.
        In order to choose between triangle and rectangle, the option must be set in ```polygonType```.
        Do not select npolygon, as it is not supported in this function.
        To add other types of shapes, such as textured or npolygon, use the other overrides available.

        It returns a shapeNo that can be used for modifying the shape in other functions in this class

        @param shapeParams The parameters(x, y, rotation... etc) for the shape
        @param polygonType The type of shape(triangle or rectangle)

        @return Returns the shapeNo that can be used for referencing this shape later.
        */
        int addPolygon(Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType);

        /**
        \brief Adds a custom textured polygon with arbitary vertices to the window

        Use this to add a custom polygon to the window.
        Please note that this function only supports textured shapes. 

        Options for the shape are defined in the [ShapeParams](#Chronos::Manager::ShapeParams) struct.
        The color field in the struct is not used, It can be skipped. The texture field must be set to the textureNo of the texture to be used.
        For options related to the shape, please refer the struct.
        A texture path must be selected.
        To add other types of shapes, such as colored or npolygon, use the other overrides available.
        The vertices must be defined in the vertices vector. The vertices must be defined in the order of the polygon. The first vertex is the starting point of the polygon.
        The number of vertices shall be fixed. However their values may be changed using the updatePolygon function.

        It returns a shapeNo that can be used for modifying the shape in other functions in this class

        @param shapeParams The parameters(x, y, rotation... etc) for the shape
        @param texture The textureNo of the texture to be used

        @return Returns the shapeNo that can be used for referencing this shape later.
        */
        int addPolygon(Chronos::Manager::ShapeParams shapeParams, int texture, std::vector<std::array<float, 2>> vertices);

        /**
        \brief Updates the polygon(any) with the new parameters.

        After initializing the shape, if you want to change the parameters of the shape to new attributes,
        using the shapeNo and passing the shapeParams, the new parameters can be propogated to the shape.
        The results will be displayed on the next ```drawFrame()``` call.

        ##Note:
        If textured shape is chosen then the color field will have no effect on the shape. The texture will be always be displayed.

        ##Note:
        This function cannot update the vertices of npolygon. To update the vertices of npolygon, use the other override.

        @param shapeNo The shapeNo reference to the shape. Generated during ```addPolygon()`` call.
        @param shapeParams The updated shape parameters to update the shape with.
        */
        void updatePolygon(int shapeNo, Chronos::Manager::ShapeParams shapeParams);

        /**
        \brief Updates the polygon(npolygon) with the new parameters.

        After initializing the shape, if you want to change the parameters of the shape to new attributes,
        using the shapeNo and passing the shapeParams, the new parameters can be propogated to the shape.

        The vertices can also be updated. Please note that the number of vertices must remain the same. However their values may be changed.

        The results will be displayed on the next ```drawFrame()``` call.
        ##Note:
        Yhe color field will have no effect on the shape. The texture will be always be displayed.

        ##Note:
        This function can be only used with npolygon shape. For rectangle or triangle, use the other override.

        ##Note:
        The number of vertices must remain the same. However their values may be changed.

        @param shapeNo The shapeNo reference to the shape. Generated during ```addPolygon()`` call.
        @param shapeParams The updated shape parameters to update the shape with.
        @param vertices The updated vertices of the polygon.
        */
        void updatePolygon(int shapeNo, Chronos::Manager::ShapeParams shapeParams, std::vector<std::array<float, 2>> vertices);

        /**
        \brief Returns the details of all npolygon shapes defined.

        If the details of the npolygon shapes are needed, this function can be used to get the details of all npolygon shapes.
        It returns a vector of pairs, where the first element is the shapeNo and the second element is the shapeParams.

        @return A vector of pairs, where the first element is the shapeNo and the second element is the shapeParams of the corresponding polygon.
        */
        std::vector<std::pair<int, Chronos::Manager::ShapeParams>> getPolygonDetails();

        /**
        \brief Returns the details of all shapes(triangle or rectangle) defined.

        If the details of the shapes(triangle or rectangle) are needed, this function can be used to get the details of all shapes.
        It returns a vector of pairs, where the first element is the shapeNo and the second element is the shapeParams.

        ##Note: This function does not return the details of npolygon shapes. For npolygon shapes, use the other override.
        
        ##Note: This will return both textured and colored shapes.

        @return A vector of pairs, where the first element is the shapeNo and the second element is the shapeParams of the corresponding polygon.
        */
        std::vector<std::pair<int, Chronos::Manager::ShapeParams>> getShapeDetails();

        /**
        \brief Updates the text with the new parameters.

        After initializing the text, if you want to change the parameters of the text to new attributes,
        using the textNo and passing the textParams, the new parameters can be propogated to the text.
        The results will be displayed on the next ```drawFrame()``` call.

        @param textNo The textNo reference to the text. Generated during ```addText()``` call.
        @param params The updated text parameters to update the text with.
        */
        void updateText(int textNo, Chronos::Engine::TextParams params);
        
        /**
        \brief Returns the details of all text defined.

        If the details of the text are needed, this function can be used to get the details of all text.
        It returns a vector of pairs, where the first element is the textNo and the second element is the textParams.

        @return A vector of pairs, where the first element is the textNo and the second element is the textParams of the corresponding text.
        */
        std::vector<std::pair<int, Chronos::Engine::TextParams>> getTextDetails();

        /**
        \brief Removes the polygon from the window

        By referencing the shapeNo, the manager removes and destroys the shape from the screen.
        This applies to all types of shapes.

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

        /**
        \brief Loads a texture from file.

        If a texture is needed to be loaded from a file, then this function can be used.
        The texture is loaded from the file and added to the texture manager.
        The textureNo is returned, which can be used for referencing the texture in other functions.

        ##Note: Only png and jpg files are supported.

        @param texturePath The path of the texture file
        @param textureName The name of the texture. This must be unique.
        */
        int addTexture(std::string texturePath, std::string textureName);

        /**
        \brief Removes the texture from the window

        By referencing the textureNo, the manager removes and destroys the texture from the screen.

        @param textureNo The reference to the texture
        */
        void removeTexture(int textureNo);

        /**
        \brief Returns the details of all textures defined.

        If the details of the textures are needed, this function can be used to get the details of all textures.
        It returns a vector of TextureDetails, where the textureName, texturePath and textureNo are returned.

        @return A vector of TextureDetails, where the textureName, texturePath and textureNo are returned.
        */
        std::vector<TextureDetails> getTextureDetails();

        std::vector<std::array<float, 2>> getPolygonVertices(int polygonNo);

        /**
        \brief Changes the present mode of the swapchain.

        The present mode is the mode in which the images are presented to the screen.
        There are various methods available. this can be used to cap or unlock the framerate, control tearing etc.
        Some of the presentation modes available are:
        - immediate: Images submitted by your application are transferred to the screen right away, which may result in tearing.
        - fifo : The swap chain is a queue where the display takes an image from the front of the queue when the display is refreshed and the program inserts rendered images at the back of the queue.If the queue is full then the program has to wait. This is most similar to vertical sync as found in modern games.The moment that the display is refreshed is known as "vertical blank".
        - fifo_relaxed : This mode only differs from the previous one if the application is late and the queue was empty at the last vertical
        blank. Instead of waiting for the next vertical blank, the image is transferred right away when it 	finally arrives.This may result in visible tearing.
        - mailbox : This is another variation of the
        second mode.Instead of blocking the application when the queue is full, the
        images 	that are already queued are simply replaced with the newer ones.This
        mode can be used to render frames as fast as possible while still avoiding
        tearing, resulting in fewer latency issues than standard vertical sync.This
        is commonly known as "triple buffering", although the existence of three buffers alone does not necessarily mean that the framerate
        
        @param mode The mode to change to. It can be one of the following:
        - immediate
        - fifo
        - fifo_relaxed
        - mailbox
        */
        void changePresentMode(std::string presentMode){
            engine.setPresentMode(presentMode);
        }

    private:
        int nextFreeAnimObjNo = 0;

        /**
        \brief The backend Vulkan engine, used for rendering the desired shapes and text.s
        */
        Chronos::Engine::Engine engine;
    };
};
};