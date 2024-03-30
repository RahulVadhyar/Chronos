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


/**
\brief The number of frames in flight.

During rendering, we can have multiple frames in flight.
This ensures that the GPU and CPU are busy at the same time and not waiting for each other.
Hence we create multiple frames and while one is rendering, the other is being prepared.
This ensures maximum performance.
*/
const int MAX_FRAMES_IN_FLIGHT = 2;
#define SPIV_SHADER_PATH "ThirdParty/Chronos/Shaders/SPIV"