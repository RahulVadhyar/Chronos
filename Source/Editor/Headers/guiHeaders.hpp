/** \file guiHeaders.hpp

 \brief Contains all the editor headers.

 The Editor uses ImGui for the GUI. This file contains all the ImGui headers.
 It also contains various other plugins for ImGUI.
*/
#pragma once

#ifdef ENABLE_EDITOR
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_vulkan.h"
#include "imstb_rectpack.h"
#include "imstb_textedit.h"
#include "imstb_truetype.h"
#include "ImSequencer.h"
#endif