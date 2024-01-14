#pragma once
#include "featureMacros.hpp"
#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "device.hpp"
#include "shape.hpp"
#include "Vertex.hpp"
#include "buffers.hpp"
#include "swapchain.hpp"
#include "texture.hpp"
#include "text.hpp"
#include "shapeManager.hpp"
#ifdef DISPLAY_IMGUI
#include "gui.hpp"
#endif
const int MAX_FRAMES_IN_FLIGHT = 2;

/**
\brief This is the main vulkan backend for Chronos.
This is for use by the API only and should not be used for any other purpose.
Code using Chronos should not use this class directly.

This is resposible for managing the object and shapes that related to vulkan. 
It is also in charge of drawing frames and managing the window.
It automatically handles window resizing, creation and destruction of necessary objects.
Any shapes or text to be created is to be done throught the shapeManager and textManager respectively.

In order to draw a frame, create a loop and call the drawFrame.
**Note:** Please see that drawFrame will not hanfle inputs.
It will also draw only one frame per call.
Hence the inputs must be managed by the main loop.
This is done to allow flexibility in inputs and management of the frame drawing.


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
namespace Chronos{
    namespace Engine{


class Engine {
public:

    /**
    During initialization of the engine, all the processes and calls needed to intialize vulkan and GLFW are done.
    No other function needs to be called to initialize the engine.
    */
    Engine();

    /**
    This is the main function that is used to add and remove text to the engine.
    To render text to the window, one may call the necessary methods in this class.
    */

    Text textManager;
    
    /**
    This is the main function that is used to add, remove and modify shapes to the engine.
    To render shapes to the window, one may call the necessary methods in this class.
    */
    ShapeManager shapeManager;

    /**
    This is the initial width of the window. It can be changed later just by changing this directly.
    */
    int width = 800;

    /**
    This is the initial width of the window. It can be changed later just by changing this directly.
    */
    int height = 600;

    /**
    This is the GLFW window that is used by the engine.
    */
    GLFWwindow* window;

    /**
    This is the background color of the window. It can be changed later.
    */
    float bgColor[3] = { 0.0f, 0.0f, 0.0f };

    /**
    This is the main draw call of the engine. 
    It is responsible for drawing frames and resizing the window.
    This needs to be added to the main game loop
    */
    void drawFrame();

    /**
    This sets the flag that window has to be resized.
    
    This tells Vulkan that the swapChain has to be recreated.
    */
    void resizeFrameBuffer();

    /**
    This is the destructor of the engine.
    It basically stops the device, and runs the cleanup function.
    This is so that it is guranteed that Vulkan will be cleaned up.
    */
    ~Engine();

private:

    /**
    This is the object that manages the device.

    This is due to the fact that device initialization and management is a complicated process.
    Also there are multiple variables that are needed for this. Hence for simplicity, a class was created for this purpose.
    */
    Chronos::Engine::Device device = Chronos::Engine::Device();

    /**
    This is the object that manages the swapchain.
    
    All the swapchain related functions are handled by this object.
    This is due to the fact that swapChain needs to be constantly mananged and recreated.
    */
    SwapChain swapChain = SwapChain();

    /**
    This is used to store the absolute previous time by the showFPSfunction.

    The showFPS function is used to print the FPS to the console.
    This needs the previous time to calculate the FPS.
    */
    float prev_time = 0.0f;

    /**
    When the window is resized, or minimized, the swapchain needs to be recreated.
    GLFW will tell us that this needs to happen, and when it does, this flag is set to true.
    The next time the drawFrame function is called, the swapchain will be recreated.
    During that time, this flag will be set to false.
    */
    bool framebufferResized = false;

    /**
    Since there will be multiple frames in flight, we need to keep track of which frame is currently being rendered.
    */
    uint32_t currentFrame = 0;

    /**
    When initializing Vulkan, the first thing we create is an instance. 
    This is where is it stored. We need this during cleanup
    */
    VkInstance instance;
    
    /**
    For using the vulkan validation layers, we need to create a debug messenger.
    */
    VkDebugUtilsMessengerEXT debugMessenger;

    /**
    For rendering to the window from the Vulkan framebuffer, we need a surface.
    */
    VkSurfaceKHR surface;

    /**
    This is the main command pool in which we will create the command buffers we will need.
    */
    VkCommandPool commandPool;

    std::vector<VkSemaphore> imageAvailableSemaphores;
    std::vector<VkSemaphore> renderFinishedSemaphores;
    std::vector<VkFence> inFlightFences;
    /**
    This function initializes the GLFW window.
    */
    void initWindow();

    /**
    The complicated process of initalizing the vulkan API is done here.
    */
    void initVulkan();

    /**
    When the engine is exited, we need to clean up the vulkan API.
    */
    void cleanup();

    /**
    This is the function during initVulkan() that creates a vulkan instance
    */
    void createInstance();

    /**
    This is the function during initVulkan() that setups the vulkan validation layers
    */
    void setupDebugMessenger();

    /**
    This is the function during initVulkan() that creates the surface that we can render to.
    */
    void createSurface();

    /**
    Since Vulkan uses explict sync, we need sync objects such as fences and semaphores to maintain synchronization.
    */
    void createSyncObjects();

#ifdef DISPLAY_IMGUI
    Chronos::Editor::Settings settings {};
    Chronos::Editor::GUIParams guiParams {};
    Chronos::Editor::GUI gui = Chronos::Editor::GUI();
#endif

    /**
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