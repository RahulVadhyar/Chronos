#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "device.hpp"
#include "swapchain.hpp"

#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
#include "validation.hpp"
#endif

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

static void framebuffer_size_callback(GLFWwindow* window, int width,
    int height)
{
    auto app = reinterpret_cast<Chronos::Engine::Engine*>(glfwGetWindowUserPointer(window));
    app->resizeFrameBuffer();
}
Chronos::Engine::Engine::Engine()
{
#ifdef ENABLE_EDITOR
    gui = Chronos::Editor::EditorRenderer();
#endif
    // initialize the window and vulkan
    initWindow();
    initVulkan();
}

Chronos::Engine::Engine::~Engine()
{
    vkDeviceWaitIdle(device.device);
    cleanup();
}

void Chronos::Engine::Engine::resizeFrameBuffer()
{
    framebufferResized = true;
}

void Chronos::Engine::Engine::initWindow()
{
    // initialize glfw with a resizeable window
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

    window = glfwCreateWindow(width, height, "Chronos", nullptr, nullptr);
    if (window == nullptr) {
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, this);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void Chronos::Engine::Engine::initVulkan()
{
    //create the basic objects
    createInstance();

    #ifdef ENABLE_VULKAN_VALIDATION_LAYERS
    setupDebugMessenger();
    #endif
    createSurface();
    device.init(instance, surface);
    swapChain.init(&device, surface, window);
    commandPool = createCommandPool(device, swapChain.surface);

    //initalize all the managers
    textureManager.init(&device, commandPool);
    shapeManager.init(&device, &swapChain, commandPool);
    colorShapeManager.init(&device, &swapChain, commandPool);
    polygonManager.init(&device, &swapChain, commandPool);
    textManager.init(&device, &swapChain, commandPool);


    createSyncObjects();

#ifdef ENABLE_EDITOR
    gui.init(&device, window, &swapChain, instance, surface);
#endif
}

void Chronos::Engine::Engine::cleanup()
{
    // after we are done, we need to cleanup all the resources we created
    swapChain.cleanup();
    shapeManager.destroy();
    colorShapeManager.destroy();
    textManager.destroy();
    polygonManager.destroy();
    textureManager.destroy();
#ifdef ENABLE_EDITOR
    gui.destroy();
#endif
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        vkDestroySemaphore(device.device, renderFinishedSemaphores[i], nullptr);
        vkDestroySemaphore(device.device, imageAvailableSemaphores[i], nullptr);
        vkDestroyFence(device.device, inFlightFences[i], nullptr);
    }
    vkDestroyCommandPool(device.device, commandPool, nullptr);
#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
    DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
#endif
    device.destroy(); // destroy the logical device
    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Chronos::Engine::Engine::drawFrame()
{
    // wait for the previous frame to finish
    glfwPollEvents();
    vkWaitForFences(device.device, 1, &inFlightFences[currentFrame], VK_TRUE,
        UINT64_MAX);

    // get the index of the next image to render to
    uint32_t imageIndex;
    VkResult result = vkAcquireNextImageKHR(
        device.device, swapChain.swapChain, UINT64_MAX,
        imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);

    // if window has been minimized, then recreate the swap chain and other things
    if (result == VK_ERROR_OUT_OF_DATE_KHR) {
        swapChain.recreate();
        shapeManager.recreate();
        colorShapeManager.recreate();
        textManager.recreate();
        polygonManager.recreate();
#ifdef ENABLE_EDITOR
        gui.recreate();
#endif
        return;
    } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        throw std::runtime_error("Failed to acquire swap chain image");
    }
    // update the shapes and text
    shapeManager.update(currentFrame);
    colorShapeManager.update(currentFrame);
    textManager.update(currentFrame);
    polygonManager.update(currentFrame);
#ifdef ENABLE_EDITOR
    gui.update();
#endif

    // reset the fences
    vkResetFences(device.device, 1, &inFlightFences[currentFrame]);

    // record the command buffers
    shapeManager.render(currentFrame, imageIndex, bgColor);
    colorShapeManager.render(currentFrame, imageIndex, bgColor);
    textManager.render(currentFrame, imageIndex, bgColor);
    polygonManager.render(currentFrame, imageIndex, bgColor);
#ifdef ENABLE_EDITOR
    gui.render(currentFrame, imageIndex, bgColor);
#endif

    // configure the semaphores
    VkSemaphore waitSemaphores[] = { imageAvailableSemaphores[currentFrame] };
    VkPipelineStageFlags waitStages[] = {
        VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT
    };
    VkSemaphore signalSemaphores[] = { renderFinishedSemaphores[currentFrame] };

    // submit the command buffers
    std::vector<VkCommandBuffer> submitCommandBuffers;
    submitCommandBuffers.push_back(shapeManager.commandBuffers[currentFrame]);
    submitCommandBuffers.push_back(colorShapeManager.commandBuffers[currentFrame]);
    submitCommandBuffers.push_back(polygonManager.commandBuffers[currentFrame]);
    submitCommandBuffers.push_back(textManager.commandBuffers[currentFrame]);

#ifdef ENABLE_EDITOR
    submitCommandBuffers.push_back(gui.commandBuffers[currentFrame]);
#endif
    VkSubmitInfo submitInfo {};
    submitInfo.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    submitInfo.waitSemaphoreCount = 1;
    submitInfo.pWaitSemaphores = waitSemaphores;
    submitInfo.pWaitDstStageMask = waitStages;
    submitInfo.commandBufferCount = static_cast<uint32_t>(submitCommandBuffers.size());
    submitInfo.pCommandBuffers = submitCommandBuffers.data();
    submitInfo.signalSemaphoreCount = 1;
    submitInfo.pSignalSemaphores = signalSemaphores;

    if (vkQueueSubmit(device.graphicsQueue, 1, &submitInfo,
            inFlightFences[currentFrame])
        != VK_SUCCESS) {
        throw std::runtime_error("failed to submit draw command buffer!");
    }

#ifdef ENABLE_EDITOR
    gui.renderAdditionalViewports();
#endif
    // present the image
    VkPresentInfoKHR presentInfo {};
    presentInfo.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    presentInfo.waitSemaphoreCount = 1;
    presentInfo.pWaitSemaphores = signalSemaphores;
    VkSwapchainKHR swapChains[] = { swapChain.swapChain };
    presentInfo.swapchainCount = 1;
    presentInfo.pSwapchains = swapChains;
    presentInfo.pImageIndices = &imageIndex;
    presentInfo.pResults = nullptr;
    result = vkQueuePresentKHR(device.presentQueue, &presentInfo);
    if (result == VK_ERROR_OUT_OF_DATE_KHR || result == VK_SUBOPTIMAL_KHR || framebufferResized) {
        framebufferResized = false;
        swapChain.recreate();
        shapeManager.recreate();
        colorShapeManager.recreate();
        textManager.recreate();
        polygonManager.recreate();
#ifdef ENABLE_EDITOR
        gui.recreate();
#endif
    } else if (result != VK_SUCCESS) {
        throw std::runtime_error("Failed to present swap chain image");
    }

    // update the current frame
    currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
}

void Chronos::Engine::Engine::createInstance()
{
    VkApplicationInfo appInfo {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Chronos";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "Chronos Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    // using vulkan 1.3 as we need shader printf support
    appInfo.apiVersion = VK_API_VERSION_1_3;

    VkInstanceCreateInfo createInfo {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;
    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    auto extensions = getRequiredExtensions();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
    if (!checkValidationLayerSupport()) {
        throw std::runtime_error("Validation layers requested, but not available");
    }
#endif
    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo {};

    createInfo.enabledLayerCount = 0;
    createInfo.pNext = nullptr;

#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();
        // uncomment below if u need fine details. It just creates extra verbose
        // generally not needed
        //  populateDebugMessengerCreateInfo(debugCreateInfo);
        //  createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
#endif
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create instance");
    }
}

#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
void Chronos::Engine::Engine::setupDebugMessenger()
{
    VkDebugUtilsMessengerCreateInfoEXT createInfo;
    populateDebugMessengerCreateInfo(createInfo);
    if (CreateDebugUtilsMessengerEXT(instance, &createInfo, nullptr,
            &debugMessenger)
        != VK_SUCCESS) {
        throw std::runtime_error("Failed to set up debug messenger");
    }
}
#endif

void Chronos::Engine::Engine::createSurface()
{
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface");
    }
}

void Chronos::Engine::Engine::createSyncObjects()
{
    imageAvailableSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
    renderFinishedSemaphores.resize(MAX_FRAMES_IN_FLIGHT);
    inFlightFences.resize(MAX_FRAMES_IN_FLIGHT);

    VkSemaphoreCreateInfo semaphoreInfo {};
    semaphoreInfo.sType = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;

    VkFenceCreateInfo fenceInfo {};
    fenceInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        if (vkCreateSemaphore(device.device, &semaphoreInfo, nullptr,
                &imageAvailableSemaphores[i])
                != VK_SUCCESS
            || vkCreateSemaphore(device.device, &semaphoreInfo, nullptr,
                   &renderFinishedSemaphores[i])
                != VK_SUCCESS
            || vkCreateFence(device.device, &fenceInfo, nullptr, &inFlightFences[i]) != VK_SUCCESS) {

            throw std::runtime_error(
                "failed to create synchronization objects for a frame!");
        }
    }
}

#ifdef ENABLE_EDITOR
void Chronos::Engine::Engine::setEditorAddElementsCallback(void (*editorAddElements)())
{
    gui.addElements = editorAddElements;
}
#endif

void Chronos::Engine::Engine::changePresentMode(std::string mode){
    if(mode == "immediate"){
        this->swapChain.preferredPresentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
    }  else if(mode == "fifo"){
        this->swapChain.preferredPresentMode = VK_PRESENT_MODE_FIFO_KHR;
    } else if(mode == "fifo_relaxed"){
        this->swapChain.preferredPresentMode = VK_PRESENT_MODE_FIFO_RELAXED_KHR;
    } else if(mode == "mailbox"){
        this->swapChain.preferredPresentMode = VK_PRESENT_MODE_MAILBOX_KHR;
    } else {
        throw std::runtime_error("Invalid present mode");
    }
    swapChain.recreate();
    shapeManager.recreate();
    colorShapeManager.recreate();
    textManager.recreate();
    polygonManager.recreate();
    #ifdef ENABLE_EDITOR
    gui.recreate();
    #endif
}