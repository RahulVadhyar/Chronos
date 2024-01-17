#ifdef ENABLE_EDITOR
#include "guiHeaders.hpp"
#include "gui.hpp"
#include "engine.hpp"


void Chronos::Editor::GUI::init(Chronos::Engine::Device* device, GLFWwindow* window, Chronos::Engine::SwapChain* swapChain,
    VkInstance instance, VkSurfaceKHR surface)
{
    this->device = device;
    this->swapChain = swapChain;
    this->surface = surface;
    this->window = window;

    renderPass = Chronos::Engine::createRenderPass(
        *device, *swapChain, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        VK_IMAGE_LAYOUT_PRESENT_SRC_KHR, VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL,
        false, false, true);
    framebuffers = Chronos::Engine::createFramebuffer(*device, *swapChain, renderPass, false);
    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;

    ImGui::StyleColorsDark();

    std::array<VkDescriptorPoolSize, 2> poolSizes {};
    poolSizes[0].type = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
    poolSizes[0].descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);
    poolSizes[1].type = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
    poolSizes[1].descriptorCount = static_cast<uint32_t>(MAX_FRAMES_IN_FLIGHT);

    VkDescriptorPoolSize pool_sizes[] = {
        { VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1 }
    };
    VkDescriptorPoolCreateInfo pool_info = {};
    pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
    pool_info.flags = VK_DESCRIPTOR_POOL_CREATE_FREE_DESCRIPTOR_SET_BIT;
    pool_info.maxSets = 1;
    pool_info.poolSizeCount = (uint32_t)IM_ARRAYSIZE(pool_sizes);
    pool_info.pPoolSizes = pool_sizes;
    vkCreateDescriptorPool(device->device, &pool_info, nullptr, &descriptorPool);

    ImGui_ImplGlfw_InitForVulkan(window, true);
    ImGui_ImplVulkan_InitInfo init_info = {};
    init_info.Instance = instance;
    init_info.PhysicalDevice = device->physicalDevice;
    init_info.Device = device->device;
    init_info.QueueFamily = Chronos::Engine::findQueueFamilies(device->physicalDevice, surface).graphicsFamily.value();
    init_info.Queue = device->graphicsQueue;
    init_info.PipelineCache = VK_NULL_HANDLE;
    init_info.DescriptorPool = descriptorPool;
    init_info.Allocator = nullptr;
    init_info.MinImageCount = MAX_FRAMES_IN_FLIGHT;
    init_info.ImageCount = MAX_FRAMES_IN_FLIGHT;
    init_info.CheckVkResultFn = nullptr; // add a fucntion to this
    ImGui_ImplVulkan_Init(&init_info, renderPass);

    VkCommandPoolCreateInfo commandPoolCreateInfo = {};
    commandPoolCreateInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    commandPoolCreateInfo.queueFamilyIndex = Chronos::Engine::findQueueFamilies(device->physicalDevice, surface).graphicsFamily.value();
    commandPoolCreateInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

    if (vkCreateCommandPool(device->device, &commandPoolCreateInfo, nullptr,
            &commandPool)
        != VK_SUCCESS) {
        throw std::runtime_error("Could not create graphics command pool");
    }

    VkCommandBuffer command_buffer = Chronos::Engine::beginSingleTimeCommands(commandPool, device->device);
    ImGui_ImplVulkan_CreateFontsTexture();
    Chronos::Engine::endSingleTimeCommands(&command_buffer, *device, commandPool);

    commandBuffers.resize(swapChain->swapChainImageViews.size());
    VkCommandBufferAllocateInfo allocInfo {};
    allocInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    allocInfo.commandPool = commandPool;
    allocInfo.level = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    allocInfo.commandBufferCount = static_cast<uint32_t>(commandBuffers.size());
    if (vkAllocateCommandBuffers(device->device, &allocInfo,
            commandBuffers.data())
        != VK_SUCCESS) {
        throw std::runtime_error("failed to allocate command buffers!");
    }
}

void Chronos::Editor::GUI::destroy()
{
    ImGui_ImplVulkan_Shutdown();
    vkDestroyRenderPass(device->device, renderPass, nullptr);
    for (auto framebuffer : framebuffers)
        vkDestroyFramebuffer(device->device, framebuffer, nullptr);
    vkDestroyCommandPool(device->device, commandPool, nullptr);
    vkDestroyDescriptorPool(device->device, descriptorPool, nullptr);
}

void Chronos::Editor::GUI::update()
{
    ImGui_ImplVulkan_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Render();
}

void Chronos::Editor::GUI::render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3])
{
    vkResetCommandBuffer(commandBuffers[currentFrame], 0);
    VkCommandBufferBeginInfo beginInfo {};
    beginInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;
    VkClearValue clearColor = { bgColor[0], bgColor[1], bgColor[2], 1.0f };
    vkBeginCommandBuffer(commandBuffers[currentFrame], &beginInfo);
    VkRenderPassBeginInfo info = {};
    info.sType = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    info.renderPass = renderPass;
    info.framebuffer = framebuffers[imageIndex];
    info.renderArea.extent = swapChain->swapChainExtent;
    info.clearValueCount = 1;
    info.pClearValues = &clearColor;
    vkCmdBeginRenderPass(commandBuffers[currentFrame], &info,
        VK_SUBPASS_CONTENTS_INLINE);
    ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(),
        commandBuffers[currentFrame]);
    vkCmdEndRenderPass(commandBuffers[currentFrame]);
    vkEndCommandBuffer(commandBuffers[currentFrame]);
}

void Chronos::Editor::GUI::cleanup()
{
    for (auto framebuffer : framebuffers)
        vkDestroyFramebuffer(device->device, framebuffer, nullptr);
}

void Chronos::Editor::GUI::recreate()
{
    cleanup();
    framebuffers = Chronos::Engine::createFramebuffer(*device, *swapChain, renderPass, false);
}

#endif