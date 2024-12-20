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

#include <set>
#include "logging.hpp"
#include "helper.hpp"
#include "swapchain.hpp"

void Chronos::Engine::Device::init(VkInstance instance, VkSurfaceKHR surface)
{
    pickPhysicalDevice(instance, surface);
    LOG(3, "Device", "Physical device picked")
    createLogicalDevice(surface);
    LOG(3, "Device", "Logical device created")
}

void Chronos::Engine::Device::destroy() { vkDestroyDevice(device, nullptr); }


/**
    \brief Checks if the physical device that we provide it supports the
    extestions we need. This is used to check if the physical device that we
    provide it supports the extensions that we need.

    @param device The physical device to check.

    @return Whether the physical device supports the extensions that we need.
*/
static inline bool checkDeviceExtensionSupport(VkPhysicalDevice device)
{
    uint32_t extensionCount;
    vkEnumerateDeviceExtensionProperties(
	device, nullptr, &extensionCount, nullptr);

    std::vector<VkExtensionProperties> availableExtensions(extensionCount);
    vkEnumerateDeviceExtensionProperties(
	device, nullptr, &extensionCount, availableExtensions.data());

    std::set<std::string> requiredExtensions(
	Chronos::Engine::deviceExtensions.begin(), Chronos::Engine::deviceExtensions.end());

    for (const auto& extension : availableExtensions) {
	requiredExtensions.erase(extension.extensionName);
    }

    return requiredExtensions.empty();
}

/**
    \brief Checks if the physical device that we provide it is suitable for our
    needs.

    For a physical device to be suitable, it must support the extensions that we
    need, and it must be capable of rendering to the surface that we provide it
    along with rendering the frames.

    @param physicalDevice The physical device to check.
    @param surface The surface to which we are rendering.

    @return Whether the physical device is suitable for our needs.
*/
static inline bool isDeviceSuitable(
    VkPhysicalDevice device, VkSurfaceKHR surface)
{
    // check if the device has the required queue families
    Chronos::Engine::QueueFamilyIndices indices
	= Chronos::Engine::findQueueFamilies(device, surface);
    bool extensionsSupported
	= checkDeviceExtensionSupport(device);

    bool swapChainAdequate = false;
    if (extensionsSupported) {
	Chronos::Engine::SwapChainSupportDetails swapChainSupport
	    = Chronos::Engine::querySwapChainSupport(device, surface);
	swapChainAdequate = !swapChainSupport.formats.empty()
	    && !swapChainSupport.presentModes.empty();
    }

    VkPhysicalDeviceFeatures supportedFeatures;
    vkGetPhysicalDeviceFeatures(device, &supportedFeatures);
    return indices.isComplete() && extensionsSupported && swapChainAdequate
	&& supportedFeatures.samplerAnisotropy;
}

/**
    \brief Gets the maxmimum supported MSAA sample count

    This gets the maximum supported MSAA sample count for the physical device
    that we provide it.

    @param physicalDevice The physical device to get the maxium supported MSAA
    sample count for.
    @return The maxium supported MSAA sample count.
*/
    VkSampleCountFlagBits getMaxUsableSampleCount(
	VkPhysicalDevice physicalDevice)
{
    // used to get max MSAA count
    VkPhysicalDeviceProperties physicalDeviceProperties;
    vkGetPhysicalDeviceProperties(physicalDevice, &physicalDeviceProperties);

    VkSampleCountFlags counts
	= physicalDeviceProperties.limits.framebufferColorSampleCounts;
    if (counts & VK_SAMPLE_COUNT_64_BIT) {
	return VK_SAMPLE_COUNT_64_BIT;
    }
    if (counts & VK_SAMPLE_COUNT_32_BIT) {
	return VK_SAMPLE_COUNT_32_BIT;
    }
    if (counts & VK_SAMPLE_COUNT_16_BIT) {
	return VK_SAMPLE_COUNT_16_BIT;
    }
    if (counts & VK_SAMPLE_COUNT_8_BIT) {
	return VK_SAMPLE_COUNT_8_BIT;
    }
    if (counts & VK_SAMPLE_COUNT_4_BIT) {
	return VK_SAMPLE_COUNT_4_BIT;
    }
    if (counts & VK_SAMPLE_COUNT_2_BIT) {
	return VK_SAMPLE_COUNT_2_BIT;
    }
    return VK_SAMPLE_COUNT_1_BIT;
}

void Chronos::Engine::Device::pickPhysicalDevice(
    VkInstance instance, VkSurfaceKHR surface)
{
    // get the number of devices
    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);
    if (deviceCount == 0) {
	LOG(1, "Device", "Failed to find GPUs with Vulkan support")
	throw std::runtime_error("Failed to find GPUs with Vulkan support");
    }
    LOG(3, "Device", "Number of devices found: " + std::to_string(deviceCount))
    std::vector<VkPhysicalDevice> devices(deviceCount);
    vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

    // check if the device is suitable
    for (const auto& device : devices) {
	if (isDeviceSuitable(device, surface)) {
	    physicalDevice = device;
	    maxMsaaSamples = getMaxUsableSampleCount(device);
	    break;
	}
    }
    if (physicalDevice == VK_NULL_HANDLE) {
	LOG(1, "Device", "Failed to find a suitable GPU")
	throw std::runtime_error("Failed to find a suitable GPU");
    }
#ifdef CHRONOS_ENABLE_LOGGING
    VkPhysicalDeviceProperties deviceProperties;
    vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);
    LOG(3, "Device", "****PHYSICAL DEVICE INFORMATION*****")
    LOG(3, "Device",
	"Physical device picked: " + std::string(deviceProperties.deviceName))
    LOG(3, "Device",
	"Driver version: " + std::to_string(deviceProperties.driverVersion))
    LOG(3, "Device",
	"API version: " + std::to_string(deviceProperties.apiVersion))
    LOG(3, "Device", "Device ID: " + std::to_string(deviceProperties.deviceID))
    LOG(3, "Device", "Vendor ID: " + std::to_string(deviceProperties.vendorID))
    LOG(3, "Device", "MSAA samples: " + std::to_string(msaaSamples))
#endif
}

void Chronos::Engine::Device::createLogicalDevice(VkSurfaceKHR surface)
{
    QueueFamilyIndices indices = findQueueFamilies(physicalDevice, surface);

    std::vector<VkDeviceQueueCreateInfo> queueCreateInfos;
    std::set<uint32_t> uniqueQueueFamilies
	= { indices.graphicsFamily.value(), indices.presentFamily.value() };

    float queuePriority = 1.0f;
    for (uint32_t queueFamily : uniqueQueueFamilies) {
	VkDeviceQueueCreateInfo queueCreateInfo {};
	queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
	queueCreateInfo.queueFamilyIndex = queueFamily;
	queueCreateInfo.queueCount = 1;
	queueCreateInfo.pQueuePriorities = &queuePriority;
	queueCreateInfos.push_back(queueCreateInfo);
    }

    VkPhysicalDeviceFeatures deviceFeatures {};
    deviceFeatures.samplerAnisotropy = VK_TRUE;
    deviceFeatures.sampleRateShading = VK_TRUE;

    VkDeviceCreateInfo createInfo {};
    createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    createInfo.pQueueCreateInfos = queueCreateInfos.data();
    createInfo.queueCreateInfoCount
	= static_cast<uint32_t>(queueCreateInfos.size());
    createInfo.pEnabledFeatures = &deviceFeatures;
    createInfo.enabledExtensionCount
	= static_cast<uint32_t>(deviceExtensions.size());
    createInfo.ppEnabledExtensionNames = deviceExtensions.data();
    createInfo.enabledLayerCount = 0;
#ifdef ENABLE_VALIDATION_LAYERS
    createInfo.enabledLayerCount
	= static_cast<uint32_t>(validationLayers.size());
    createInfo.ppEnabledLayerNames = validationLayers.data();
#endif

    if (vkCreateDevice(physicalDevice, &createInfo, nullptr, &device)
	!= VK_SUCCESS) {
	LOG(1, "Device", "Failed to create logical device")
	throw std::runtime_error("Failed to create logical device");
    }

    LOG(3, "Device", "Logical device created")
    // get the queue handle
    vkGetDeviceQueue(device, indices.graphicsFamily.value(), 0, &graphicsQueue);
    vkGetDeviceQueue(device, indices.presentFamily.value(), 0, &presentQueue);
}
