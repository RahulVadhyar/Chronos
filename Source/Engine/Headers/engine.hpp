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


class Engine {
public:
	void run();
	bool framebufferResized = false;
	Text textManager;
	ShapeManager shapeManager;
	int width = 800;
	int height = 600;
	GLFWwindow* window;
	float bgColor[3] = { 0.0f, 0.0f, 0.0f };
	Device device = Device();
#ifdef DISPLAY_IMGUI
	Chronos::Editor::Settings settings{};
	Chronos::Editor::GUIParams guiParams{};
#endif
	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();
	void drawFrame();
	

private:
	float prev_time = 0.0f;
	
	uint32_t currentFrame = 0;
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR surface;
	VkSampler textureSampler;
	SwapChain swapChain = SwapChain();
	VkCommandPool commandPool;
	
	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;

	void createInstance();
	void setupDebugMessenger();
	void createSurface();
	void createSyncObjects();

#ifdef DISPLAY_IMGUI
	Chronos::Editor::GUI gui;
#endif

	void showfps() {
		float current_time = static_cast<float>(glfwGetTime());
		float fps = 1.0f / (current_time - prev_time);
		prev_time = current_time;
		std::cout << "FPS: " << fps << std::endl;
	}
};