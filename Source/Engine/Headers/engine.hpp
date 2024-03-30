/** \file engine.hpp

 \brief Contains the [Engine](#Chronos::Engine::Engine) class.

 This is the heart of the renderer. It is responsible for managing the window, the vulkan API and the objects that are used by the API.
*/
#pragma once


#ifdef ENABLE_EDITOR
//if the editor is enabled, then include the editorRenderer to get the rendering functions and classes of the editor.
#include "editorRenderer.hpp"
#endif

namespace Chronos {
namespace Engine {

    /**
    \brief This is the main vulkan backend for Chronos.
    This is for use by the API only and should not be used for any other purpose.

    This is resposible for managing the object and shapes that related to vulkan.
    It is also in charge of drawing frames and managing the window.
    It automatically handles window resizing, creation and destruction of necessary objects.
    Any shapes or text to be created is to be done throught the shapeManager and textManager respectively.

    In order to draw a frame, create a loop and call the drawFrame.

    ##Important
    drawFrame will not handle inputs.
    It will also draw only one frame per call.
    Hence the inputs must be managed by the main loop.
    This is done to allow flexibility in inputs and management of the frame drawing.

    ## drawFrame() example
    Suppose Engine class is initialized as engine
    The following code snippet is an example of a basic rendering loop.
    It also includes functionaility to close the window either when the escape key is pressed or when the window is closed.
    For more on handling inputs, please see the GLFW documentation.

    ~~~~~~~~~~~~~~~{.cpp}
                while (!glfwWindowShouldClose(engine.window)) {
                    //if esc is pressed, then ask GLFW to close the window
                    if (glfwGetKey(engine.window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
                        glfwSetWindowShouldClose(engine.window, true);
                    }
                    //draw the frame
                    engine.drawFrame();
                }
    ~~~~~~~~~~~~~~~
    */
    class Engine {
    public:
        /**
        \brief Initlizes the engine

        During initialization of the engine, all the processes and calls needed to intialize vulkan and GLFW are done.
        No other function needs to be called to initialize the engine.
        During initialization the following occurs:

        * If the editor is enabled, then the editor(EditorRenderer) settings are initialized
        * The window is created
        * The vulkan API is initialized along with all the necessary objects.

        */
        Engine();

        /**
        \brief Main function that is used to add, update and remove text to the engine.

        To render text to the window, one may call the necessary methods in this class.
        */
        Chronos::Engine::TextManager textManager;

        /**
        \brief This is the main function that is used to add, remove and modify textured shapes(rectangles or triangles) to the engine.

        To render shapes to the window, one may call the necessary methods in this class.
        */
        Chronos::Engine::ShapeManager<TexturedVertex> shapeManager;

        /**
        \brief This is the main function that is used to add, remove and modify colored shapes(rectangles or triangles) to the engine.

        To render shapes to the window, one may call the necessary methods in this class.
        */
        Chronos::Engine::ShapeManager<ColorVertex> colorShapeManager;

        /**
        \brief Used to create and manage textures.

        To add or remove textures, one may call the necessary methods in this class.
        */
        Chronos::Engine::TextureManager textureManager;
        
        /**
        \brief Used to create and manage aribatry polygons.

        To add or remove polygons, one may call the necessary methods in this class.
        */
        Chronos::Engine::PolygonManager polygonManager;

        /**
        \brief This is the initial width of the window. It can be changed later just by changing this directly.
        */
        int width = 800;

        /**
        \brief This is the initial width of the window. It can be changed later just by changing this directly.
        */
        int height = 600;

        /**
        \brief This is the GLFW window reference that is used by the engine.
        */
        GLFWwindow* window;

        /**
        \brief This is the background color of the window.

        It can be changed by changing the values inside this float.
        The values should be in the range of 0 to 1.
        */
        float bgColor[3] = { 0.0f, 0.0f, 0.0f };

        /**
        \brief Main draw call. Its responsible for drawing frames and resizing the window.
        To be added to the main game loop.

        During this function the following occurs:

        - It waits for the previous frame to be drawn and presented
        - It acquires the next image from the swapchain
        - If the window is resized, then the swapchain and any framebuffers and renderpasses are recreated
        - It updates the values of the shapes and text
        - Resets the sync objects
        - It records the command buffers
        - Configures the sync objects
        - Submits the command buffers. Note: Only after ```vkQueueSubmit``` is called, the command buffers are executed and the frame is rendered.
        - Presents the image to the screen
        */
        void drawFrame();

        /**
        \brief Tells the engine that the window has to be resized. This is called by GLFW.

        It sets the [flag](#Chronos::Engine::Engine::framebufferResized) that window has to be resized.
        Later during the drawFrame function, the swapchain is recreated and resets the flag.
        This tells Vulkan that the swapChain has to be recreated.
        */
        void resizeFrameBuffer();


#ifdef ENABLE_EDITOR
        /**
        \brief Sets the callback function for the editor to add elements.

        This is used to set the callback function for the editor to add elements.
        This is used by ImGui to add elements to the editor.
        Since that fucntions are not part of the engine, the user has to set the callback function.
        */
        void setEditorAddElementsCallback(void(*)());
#endif
        /**
        \brief This is the destructor of the engine.

        It basically stops the device, and runs the cleanup function.
        This is so that it is guranteed that Vulkan objects will be cleaned up correctly.
        */
        ~Engine();

    private:
        /**
        \brief This is the object that manages the device.

        This is due to the fact that device initialization and management is a complicated process.
        Also there are multiple variables that are needed for this. Hence for simplicity, a class was created for this purpose.
        */
        Chronos::Engine::Device device = Chronos::Engine::Device();

        /**
        \brief This is the object that manages the swapchain.

        All the swapchain related functions are handled by this object.
        This is due to the fact that swapChain needs to be constantly mananged and recreated due to various conditions.
        */
        Chronos::Engine::SwapChain swapChain = Chronos::Engine::SwapChain();

        /**
        \brief This is used to store the absolute previous time by the showFPS function.

        The showFPS function is used to print the FPS to the console.
        This needs the previous time to calculate the FPS.
        */
        float prev_time = 0.0f;

        /**
        \brief Does the framebuffer need to be resized?

        When the window is resized, or minimized, the swapchain needs to be recreated.
        GLFW will tell us that this needs to happen, and when it does, this flag is set to true.
        The next time the drawFrame function is called, the swapchain will be recreated.
        During that time, this flag will be set to false.
        */
        bool framebufferResized = false;

        /**
        \brief The current frame to be rendered to.

        Since there will be multiple frames in flight, we need to keep track of which frame is currently being rendered.
        */
        uint32_t currentFrame = 0;

        /**
        \brief The Vulkan instance.

        When initializing Vulkan, the first thing we create is an instance.
        This is where is it stored. We need this during cleanup
        */
        VkInstance instance;

        /**
        \brief The debug messenger.

        For using the vulkan validation layers, we need to create a debug messenger.
        this gives us the ability to print debug messages to the console given to use by the validation layers.
        That wat we can debug our application and ensure that it conforms to the Vulkan standards.
        */
        VkDebugUtilsMessengerEXT debugMessenger;

        /**
        \brief The surface to render to.

        For rendering to the window from the Vulkan framebuffer, we need a surface.
        */
        VkSurfaceKHR surface;

        /**
        \brief The command Pool

        All command buffers are allocated from a command pool.
        This is where the command pool is stored.
        */
        VkCommandPool commandPool;

        std::vector<VkSemaphore> imageAvailableSemaphores;
        std::vector<VkSemaphore> renderFinishedSemaphores;
        std::vector<VkFence> inFlightFences;
        /**
        \brief This function initializes the GLFW window.

        It creates a ```GLFWwindow*``` and stores it in the ```window``` variable.
        It also sets the window hints sets the framebuffer callback.
        */
        void initWindow();

        /**
        \brief The complicated process of initalizing the vulkan API is done here.

        The following occurs during this function:
        - The vulkan instance is created
        - The validation layers are setup
        - The surface is created
        - The device is initialized
        - The swapchain is initialized
        - The command pool is created
        - The shape and text managers are initialized

        Also the objects needed for the editor are also created here
        */
        void initVulkan();

        /**
        \brief Cleans up vulkan objects.

        When the engine is exited, we need to clean up the vulkan objects.
        If we do not do this, vulkan validation layers will throw errors.
        The following occurs during this function:
        - The device is stopped
        - The swapchain is cleaned up
        - The shape and text manager along with their objects are cleaned up
        - The sync objects are cleaned up
        - The command Pool is destroyed
        - The device, surface and instance are destroyed
        - Window is destroyed and GLFW is terminated
        */
        void cleanup();

        /**
        \brief Creates a vulkan instance

        This function sets some of the information about our app. It enables all the extensions and validation layers.
        */
        void createInstance();

        /**
        \brief Sets up the vulkan validation layers

        This is the function during initVulkan() that setups the vulkan validation layers
        */
        void setupDebugMessenger();

        /**
        \brief Creates the surface to render to.
        */
        void createSurface();

        /**
        \brief Creates sync objects for rendering

        Since Vulkan uses explict sync, we need sync objects such as fences and semaphores to maintain synchronization.

        Since there are multiple frames in flight, we need multiple copies for each sync object.
        In particular, we need:
            - A semaphore to signal that an image is available for rendering
            - A semaphore to signal that rendering has finished for a frame
            - In Flight fences to ensure that the renderer is synchronized with the GPU
        */
        void createSyncObjects();

#ifdef ENABLE_EDITOR
        Chronos::Editor::EditorRenderer gui = Chronos::Editor::EditorRenderer();
#endif

        /**
        \brief Displays the FPS to the console.

        This is a helper function that prints the FPS to the console.
        This is useful to monitor the performance of the application.
        */
        void showfps()
        {
            float current_time = static_cast<float>(glfwGetTime());
            float fps = 1.0f / (current_time - prev_time);
            prev_time = current_time;
            std::cout << "FPS: " << fps << std::endl;
        }
    };

};
};