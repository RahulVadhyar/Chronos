#pragma once
#include "vulkaninit.hpp"
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


class ChronoApplication {
public:
	void run() {
#ifdef DISPLAY_IMGUI
		gui = GUI();
		guiParams.settings = &settings;
#endif
		initWindow();
		initVulkan();
		mainLoop();
		cleanup();
	}
	bool framebufferResized = false;
	
#ifdef DISPLAY_IMGUI
	Settings settings{};
	GUIParams guiParams{};
#endif
private:
	float prev_time = 0.0f;
	int width = 800;
	int height = 600;
	float bgColor[3] = { 0.0f, 0.0f, 0.0f };
	ShapeManager shapeManager;
	Text textManager;
	GLFWwindow* window;
	uint32_t currentFrame = 0;
	Device device = Device();
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkSurfaceKHR surface;
	VkSampler textureSampler;
	SwapChain swapChain = SwapChain();
	VkCommandPool commandPool;
	
	std::vector<VkSemaphore> imageAvailableSemaphores;
	std::vector<VkSemaphore> renderFinishedSemaphores;
	std::vector<VkFence> inFlightFences;
	

	void initWindow();
	void initVulkan();
	void mainLoop();
	void cleanup();
	void createInstance();
	void setupDebugMessenger();
	void createSurface();
	void drawFrame();
	void createSyncObjects();

#ifdef DISPLAY_IMGUI
	GUI gui;
#endif

	void showfps() {
		float current_time = static_cast<float>(glfwGetTime());
		float fps = 1.0f / (current_time - prev_time);
		prev_time = current_time;
		std::cout << "FPS: " << fps << std::endl;
	}
};