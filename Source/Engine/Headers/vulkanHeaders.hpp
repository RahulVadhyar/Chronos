/** \file vulkanHeaders.hpp

 \brief Contains the common headers for the vulkan API.

More specifically it includes the following packages:
- GLFW
- GLM
- Vulkan(included by GLFW)
*/
#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>
#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#include "glm/ext.hpp"
#include "glm/gtx/string_cast.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>