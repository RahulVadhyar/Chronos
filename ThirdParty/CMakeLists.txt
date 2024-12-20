#GLFW
include(FetchContent)

if(UNIX)
    if(CHRONOS_SUPPORT_WAYLAND)
        set(GLFW_BUILD_WAYLAND ON)
        message(STATUS "Building with Wayland support")
    else()
        set(GLFW_BUILD_WAYLAND OFF)
        message(STATUS "Building without Wayland support")
    endif()
endif()
    
set(X11_X11_LIB who_cares)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
set(GLFW_VULKAN_STATIC ON)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(glfw)

# target_include_directories(Chronos PUBLIC glfw/include) 
target_link_libraries(Chronos glfw)
if(CHRONOS_BUILD_EDITOR)
    # target_include_directories(ChronosEditor PUBLIC glfw/include) 
    target_link_libraries(ChronosEditor glfw)
endif()

#GLM
FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/icaven/glm.git
    GIT_TAG master
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(glm)
target_link_directories(Chronos PUBLIC glm/glm)
if(CHRONOS_BUILD_EDITOR)
    target_link_directories(ChronosEditor PUBLIC glm/glm)
endif()

#Vulkan
if (WIN32)
    set(VULKAN_SDK_DIR $ENV{VULKAN_SDK})        
    message(STATUS "Vulkan SDK found: ${VULKAN_SDK_DIR}")
    
    target_include_directories(Chronos PUBLIC ${VULKAN_SDK_DIR}/Include)    
    target_link_directories(Chronos PUBLIC ${VULKAN_SDK_DIR}/Lib/) 
    target_link_libraries(Chronos vulkan-1) 
    if(CHRONOS_BUILD_EDITOR)
        target_include_directories(ChronosEditor PUBLIC ${VULKAN_SDK_DIR}/Include)    
        target_link_directories(ChronosEditor PUBLIC ${VULKAN_SDK_DIR}/Lib/) 
        target_link_libraries(ChronosEditor vulkan-1) 
    endif()
    
endif(WIN32) 

if(UNIX)
    target_link_libraries(Chronos vulkan)
    if(CHRONOS_BUILD_EDITOR)
        target_link_libraries(ChronosEditor vulkan)
    endif()   
endif(UNIX)

if(CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS)
    target_compile_definitions(Chronos PUBLIC ENABLE_VULKAN_VALIDATION_LAYERS)
    if(CHRONOS_BUILD_EDITOR)
        target_compile_definitions(ChronosEditor PUBLIC ENABLE_VULKAN_VALIDATION_LAYERS)
    endif()
        message(STATUS "Vulkan validation layers enabled")
endif()

#imgui(only editor)
if(CHRONOS_BUILD_EDITOR)
    FetchContent_Declare(
        imgui
        GIT_REPOSITORY https://github.com/ocornut/imgui.git
        GIT_TAG docking
    )
    FetchContent_MakeAvailable(imgui)
    file(GLOB IMGUI_FILES ${imgui_SOURCE_DIR}/*.cpp)
    target_include_directories(ChronosEditor PUBLIC ${imgui_SOURCE_DIR})               
    target_include_directories(ChronosEditor PUBLIC ${imgui_SOURCE_DIR}/backends)
    target_sources(ChronosEditor PRIVATE ${imgui_SOURCE_DIR}/backends/imgui_impl_glfw.cpp ${imgui_SOURCE_DIR}/backends/imgui_impl_vulkan.cpp ${IMGUI_FILES})
endif()

#fonts
file(GLOB FONTS_DIR fonts/latin1/*)
target_include_directories(Chronos PUBLIC ${FONTS_DIR})

if(CHRONOS_BUILD_EDITOR)
    target_include_directories(ChronosEditor PUBLIC ${FONTS_DIR})
endif()

#stb
target_include_directories(Chronos PUBLIC stb)

if(CHRONOS_BUILD_EDITOR)
    target_include_directories(ChronosEditor PUBLIC stb)
endif()