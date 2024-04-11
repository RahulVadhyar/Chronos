/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "vulkanHeaders.hpp"
#include "stlheader.hpp"
#include "logging.hpp"
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
    LOG(3, "Engine", "Framebuffer resized");
}
Chronos::Engine::Engine::Engine()
{
#ifdef ENABLE_EDITOR
    gui = Chronos::Editor::EditorRenderer();
#endif
    // initialize the window and vulkan
    initWindow();
    LOG(3, "Engine", "GLFW initialized");
    initVulkan();
    LOG(3, "Engine", "Vulkan initialized");
}

Chronos::Engine::Engine::~Engine()
{
    vkDeviceWaitIdle(device.device);
    cleanup();
    LOG(3, "Engine", "Engine cleaned up");
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

    window = glfwCreateWindow(width, height, GAME_NAME, nullptr, nullptr);
    if (window == nullptr) {
        LOG(1, "Engine", "Failed to create GLFW window");
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
    LOG(3, "Engine", "Device initialized");
    swapChain.init(&device, surface, window);
    LOG(3, "Engine", "Swapchain initialized");
    commandPool = createCommandPool(device, swapChain.surface);
    LOG(3, "Engine", "Command pool initialized");

    //initalize all the managers
    textureManager.init(&device, commandPool);
    LOG(3, "Engine", "Texture manager initialized");
    shapeManager.init(&device, &swapChain, commandPool);
    LOG(3, "Engine", "Shape manager initialized");
    colorShapeManager.init(&device, &swapChain, commandPool);
    LOG(3, "Engine", "Color shape manager initialized");
    polygonManager.init(&device, &swapChain, commandPool);
    LOG(3, "Engine", "Polygon manager initialized");
    textManager.init(&device, &swapChain, commandPool);
    LOG(3, "Engine", "Text manager initialized");

    createSyncObjects();

#ifdef ENABLE_EDITOR
    gui.init(&device, window, &swapChain, instance, surface);
    LOG(3, "Engine", "Editor initialized");
#endif
}

void Chronos::Engine::Engine::cleanup()
{
    // after we are done, we need to cleanup all the resources we created
    swapChain.cleanup();
    LOG(3, "Engine", "Swapchain cleaned up");
    shapeManager.destroy();
    LOG(3, "Engine", "Shape manager cleaned up");
    colorShapeManager.destroy();
    LOG(3, "Engine", "Color shape manager cleaned up");
    textManager.destroy();
    LOG(3, "Engine", "Text manager cleaned up");
    polygonManager.destroy();
    LOG(3, "Engine", "Polygon manager cleaned up");
    textureManager.destroy();
    LOG(3, "Engine", "Texture manager cleaned up");
#ifdef ENABLE_EDITOR
    gui.destroy();
    LOG(3, "Engine", "Editor cleaned up");
#endif
    for (size_t i = 0; i < MAX_FRAMES_IN_FLIGHT; i++) {
        vkDestroySemaphore(device.device, renderFinishedSemaphores[i], nullptr);
        vkDestroySemaphore(device.device, imageAvailableSemaphores[i], nullptr);
        vkDestroyFence(device.device, inFlightFences[i], nullptr);
    }
    vkDestroyCommandPool(device.device, commandPool, nullptr);
    LOG(3, "Engine", "Command pool cleaned up");
#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
    DestroyDebugUtilsMessengerEXT(instance, debugMessenger, nullptr);
    LOG(3, "Engine", "Debug messenger cleaned up");
#endif
    device.destroy(); // destroy the logical device
    LOG(3, "Engine", "Device cleaned up");
    vkDestroySurfaceKHR(instance, surface, nullptr);
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
    LOG(3, "Engine", "GLFW cleaned up");
}

void Chronos::Engine::Engine::drawFrame()
{   
    if(swapChain.changePresentMode){
        changePresentMode();
        swapChain.changePresentMode = false;
        LOG(3, "Engine", "Present mode changed");
    }
    if(this->changeMSAAFlag){
        vkDeviceWaitIdle(device.device);
        changeMSAASettings();
        this->changeMSAAFlag = false;
        LOG(3, "Engine", "MSAA changed");
    }
    // wait for the previous frame to finish
    glfwPollEvents();

#ifdef CHRONOS_PROFILING
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
#endif

    vkWaitForFences(device.device, 1, &inFlightFences[currentFrame], VK_TRUE,
        UINT64_MAX);

#ifdef CHRONOS_PROFILING
    this->waitTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count();
#endif

    // get the index of the next image to render to
    uint32_t imageIndex;
    VkResult result = vkAcquireNextImageKHR(
        device.device, swapChain.swapChain, UINT64_MAX,
        imageAvailableSemaphores[currentFrame], VK_NULL_HANDLE, &imageIndex);

    // if window has been minimized, then recreate the swap chain and other things
    if (result == VK_ERROR_OUT_OF_DATE_KHR) {
        swapChain.recreate();
        LOG(3, "Engine", "Swapchain recreated");
        shapeManager.recreate();
        LOG(3, "Engine", "Shape manager recreated");
        colorShapeManager.recreate();
        LOG(3, "Engine", "Color shape manager recreated");
        textManager.recreate();
        LOG(3, "Engine", "Text manager recreated");
        polygonManager.recreate();
        LOG(3, "Engine", "Polygon manager recreated");
#ifdef ENABLE_EDITOR
        gui.recreate();
        LOG(3, "Engine", "Editor recreated");
#endif
        return;
    } else if (result != VK_SUCCESS && result != VK_SUBOPTIMAL_KHR) {
        LOG(1, "Engine", "Failed to acquire swap chain image");
        throw std::runtime_error("Failed to acquire swap chain image");
    }
#ifdef CHRONOS_PROFILING
    auto startUpdate = std::chrono::steady_clock::now();
#endif
    // update the shapes and text
    shapeManager.update(currentFrame);
    colorShapeManager.update(currentFrame);
    textManager.update(currentFrame);
    polygonManager.update(currentFrame);
    
#ifdef ENABLE_EDITOR
    gui.update();
#endif
#ifdef CHRONOS_PROFILING
    this->updateTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - startUpdate).count();
#endif
    LOG(4, "Engine", "Managers updated");

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
    LOG(4, "Engine", "Managers command buffers recorded")


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
        LOG(1, "Engine", "Failed to submit draw command buffer");
        throw std::runtime_error("failed to submit draw command buffer!");
    }
    LOG(4, "Engine", "Command buffers submitted");
    
#ifdef ENABLE_EDITOR
    gui.renderAdditionalViewports();
#endif

#ifdef CHRONOS_PROFILING
    this->cpuTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count();
    auto startPresent = std::chrono::steady_clock::now();
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
        LOG(3, "Engine", "Swapchain recreated");
        shapeManager.recreate();
        LOG(3, "Engine", "Shape Manager recreated");
        colorShapeManager.recreate();
        LOG(3, "Engine", "Color Shape Manager recreated");
        textManager.recreate();
        LOG(3, "Engine", "Text Manager recreated");
        polygonManager.recreate();
        LOG(3, "Engine", "polygon Manager recreated");
#ifdef ENABLE_EDITOR
        gui.recreate();
        LOG(3, "Engine", "Editor recreated");
#endif
    } else if (result != VK_SUCCESS) {
        LOG(1, "Engine", "Failed to present swap chain image");
        throw std::runtime_error("Failed to present swap chain image");
    }
#ifdef CHRONOS_PROFILING
    this->presentTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - startPresent).count();
    this->totalTime = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start).count();
#endif
    // update the current frame
    currentFrame = (currentFrame + 1) % MAX_FRAMES_IN_FLIGHT;
    LOG(4, "Engine", "Current frame is " + std::to_string(currentFrame));
}

void Chronos::Engine::Engine::createInstance()
{
    VkApplicationInfo appInfo {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = GAME_NAME;
    appInfo.applicationVersion = VK_MAKE_VERSION(GAME_VERSION_MAJOR, GAME_VERSION_MINOR, GAME_VERSION_PATCH);
    appInfo.pEngineName = "Chronos";
    appInfo.engineVersion = VK_MAKE_VERSION(CHRONOS_VERSION_MAJOR, CHRONOS_VERSION_MINOR, CHRONOS_VERSION_PATCH);
    // using vulkan 1.3 as we need shader printf support
    appInfo.apiVersion = VK_API_VERSION_1_0;
    LOG(3, "Engine", "engine version: " + std::to_string(CHRONOS_VERSION_MAJOR) + "." + std::to_string(CHRONOS_VERSION_MINOR) + "." + std::to_string(CHRONOS_VERSION_PATCH));
    LOG(3, "Engine", "game version: " + std::to_string(GAME_VERSION_MAJOR) + "." + std::to_string(GAME_VERSION_MINOR) + "." + std::to_string(GAME_VERSION_PATCH));
    LOG(3, "Engine", "game name: " + std::string(GAME_NAME));

    VkInstanceCreateInfo createInfo {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // uint32_t glfwExtensionCount = 0;
    // const char** glfwExtensions;
    // glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    auto extensions = getRequiredExtensions();
    createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
    createInfo.ppEnabledExtensionNames = extensions.data();

#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
    if (!checkValidationLayerSupport()) {
        LOG(1, "Engine", "Validation layers requested, but not available");
        throw std::runtime_error("Validation layers requested, but not available");
    }
#endif

    createInfo.enabledLayerCount = 0;
    createInfo.pNext = nullptr;

#ifdef ENABLE_VULKAN_VALIDATION_LAYERS
        createInfo.enabledLayerCount = static_cast<uint32_t>(validationLayers.size());
        createInfo.ppEnabledLayerNames = validationLayers.data();
        // uncomment below if u need fine details. It just creates extra verbose
        // generally not needed
        // VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo {};
        //  populateDebugMessengerCreateInfo(debugCreateInfo);
        //  createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*)&debugCreateInfo;
#endif
    if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
        LOG(1, "Engine", "Failed to create instance");
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
            LOG(1, "Engine", "Failed to set up debug messenger");
        throw std::runtime_error("Failed to set up debug messenger");
    }
}
#endif

void Chronos::Engine::Engine::createSurface()
{
    if (glfwCreateWindowSurface(instance, window, nullptr, &surface) != VK_SUCCESS) {
        LOG(1, "Engine", "Failed to create window surface");
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
            LOG(1, "Engine", "Failed to create synchronization objects for a frame");
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

void Chronos::Engine::Engine::changePresentMode(){
    vkDeviceWaitIdle(device.device);
    swapChain.recreate();
    shapeManager.recreate();
    colorShapeManager.recreate();
    textManager.recreate();
    polygonManager.recreate();
    #ifdef ENABLE_EDITOR
    gui.recreate();
    #endif
}

void Chronos::Engine::Engine::setPresentMode(std::string mode){
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
    this->swapChain.changePresentMode = true;
    LOG(3, "Engine", "Present mode set to " + mode);
}

std::vector<std::string> Chronos::Engine::Engine::getAvailableMSAAModes(){
    VkSampleCountFlagBits maxSample = device.maxMsaaSamples;
    std::vector<std::string> modes;
    if(VK_SAMPLE_COUNT_64_BIT <= maxSample){
        modes.push_back("64");
    }
    if(VK_SAMPLE_COUNT_32_BIT <= maxSample){
        modes.push_back("32");
}
    if(VK_SAMPLE_COUNT_16_BIT <= maxSample){
        modes.push_back("16");
    }
    if(VK_SAMPLE_COUNT_8_BIT <= maxSample){
        modes.push_back("8");
    }
    if(VK_SAMPLE_COUNT_4_BIT <= maxSample){
        modes.push_back("4");
    }
    if(VK_SAMPLE_COUNT_2_BIT <= maxSample){
        modes.push_back("2");
    }
    modes.push_back("1");
    return modes;
}

void Chronos::Engine::Engine::changeMSAA(std::string mode){
    if(mode == "64"){
        this->newMSAAMode = VK_SAMPLE_COUNT_64_BIT;
    } else if(mode == "32"){
        this->newMSAAMode = VK_SAMPLE_COUNT_32_BIT;
    } else if(mode == "16"){
        this->newMSAAMode = VK_SAMPLE_COUNT_16_BIT;
    } else if(mode == "8"){
        this->newMSAAMode = VK_SAMPLE_COUNT_8_BIT;
    } else if(mode == "4"){
        this->newMSAAMode = VK_SAMPLE_COUNT_4_BIT;
    } else if(mode == "2"){
        this->newMSAAMode = VK_SAMPLE_COUNT_2_BIT;
    } else if(mode == "1"){
        this->newMSAAMode = VK_SAMPLE_COUNT_1_BIT;
    } else {
        throw std::runtime_error("Invalid MSAA mode");
    }
    if(this->newMSAAMode > device.maxMsaaSamples){
        throw std::runtime_error("Invalid MSAA mode");
    }
    this->changeMSAAFlag = true;
    LOG(3, "Engine", "MSAA to be changed to " + mode);
}

void Chronos::Engine::Engine::changeMSAASettings(){
    device.msaaSamples = this->newMSAAMode;
    this->swapChain.changeMsaa();
    this->textManager.changeMsaa();
    this->shapeManager.changeMsaa();
    this->colorShapeManager.changeMsaa();
    this->polygonManager.changeMsaa();
#ifdef ENABLE_EDITOR
    this->gui.changeMsaa();
#endif
    LOG(3, "Engine", "MSAA changed to " + std::to_string(device.msaaSamples));
}