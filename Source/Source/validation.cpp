#include "vulkaninit.hpp"
#include "validation.hpp"

bool checkValidationLayerSupport() {
  uint32_t layerCount;
  vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

  std::vector<VkLayerProperties> availableLayers(layerCount);
  vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

  for (const char *layerName : validationLayers) {
    bool layerFound = false;

    for (const auto &layerProperties : availableLayers) {
      if (strcmp(layerName, layerProperties.layerName) == 0) {
        layerFound = true;
        break;
      }
    }
    if (!layerFound) {
      return false;
    }
  }
  return true;
}
static VKAPI_ATTR VkBool32 VKAPI_CALL
debugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
              VkDebugUtilsMessageTypeFlagsEXT messageType,
              const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
              void *pUserData) {
  /*
  Quick reference to vulkan error handling:
  messageSeverity: Severity of the message
          VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT: Diagnostic message
          VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT: Informational message
  like the creation of a resource
          VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT: Message about
  behavior that is not necessarily an error, but very likely a bug in your
  application VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT: Message about
  behavior that is invalid and may cause crashes

  messageType: Type of the message
          VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT: Some event has happened
  that is unrelated to the specification or performance
          VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT: Something has happened
  that violates the specification or indicates a possible mistake
          VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT: Potential non-optimal
  use of Vulkan

  pCallbackData: Struct containing details about the message itself
          pMessage: The debug message as a null-terminated string
          pObjects: Array of Vulkan object handles related to the message
          objectCount: Number of objects in array
          pMessageIdName: Unique identifier of the message (only for
  VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT) messageIdNumber: Number
  representation of the message ID pQueueLabels: Array of VkDebugUtilsLabelEXT
  structs related to the objects in pObjects queueLabelCount: Number of elements
  in pQueueLabels pCmdBufLabels: Array of VkDebugUtilsLabelEXT structs related
  to the objects in pObjects cmdBufLabelCount: Number of elements in
  pCmdBufLabels pUserData: The pUserData value that was specified when calling
  vkCreateDebugUtilsMessengerEXT
  */
  std::cerr << "validation layer: " << pCallbackData->pMessage << std::endl;
  return VK_FALSE;
}

// function to create the debug messenger
VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT *pCreateInfo,
    const VkAllocationCallbacks *pAllocator,
    VkDebugUtilsMessengerEXT *pDebugMessenger) {
  auto func = (PFN_vkCreateDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
      instance, "vkCreateDebugUtilsMessengerEXT");
  if (func != nullptr)
    return func(instance, pCreateInfo, pAllocator, pDebugMessenger);
  else
    return VK_ERROR_EXTENSION_NOT_PRESENT;
}

// function to destroy the debug messenger
void DestroyDebugUtilsMessengerEXT(VkInstance instance,
                                   VkDebugUtilsMessengerEXT debugMessenger,
                                   const VkAllocationCallbacks *pAllocator) {
  auto func = (PFN_vkDestroyDebugUtilsMessengerEXT)vkGetInstanceProcAddr(
      instance, "vkDestroyDebugUtilsMessengerEXT");
  if (func != nullptr)
    func(instance, debugMessenger, pAllocator);
}

void populateDebugMessengerCreateInfo(
    VkDebugUtilsMessengerCreateInfoEXT &createInfo) {
  createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;

  // set the severity of the messages to be sent to the callback
  createInfo.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT |
                               VK_DEBUG_UTILS_MESSAGE_SEVERITY_INFO_BIT_EXT;

  // set the type of messages to be sent to the callback
  createInfo.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                           VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                           VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

  // set the callback function
  createInfo.pfnUserCallback = debugCallback;
}