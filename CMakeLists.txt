cmake_minimum_required(VERSION 3.13)
project(Chronos VERSION 0.0.0)
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_BUILD_TYPE Debug)

if(UNIX)
option(CHRONOS_SUPPORT_WAYLAND "Build with Wayland support" ON)
endif()
option(CHRONOS_BUILD_TESTS "Build the tests" OFF)
option(CHRONOS_BUILD_EDITOR "Build the editor" ON)
option(CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS "Enable Vulkan validation layers" ON)
option(CHRONOS_ENABLE_ERROR_LOGGING "Enable Error logging(level 1)" OFF)
option(CHRONOS_ENABLE_BASIC_LOGGING "Enable Basic logging(level 2)" OFF)
option(CHRONOS_ENABLE_VERBOSE_LOGGING "Enable Verbose logging(level 3)" OFF)
option(CHRONOS_ENABLE_EXTREME_LOGGING "Enable Extreme logging(level 4)" OFF)

if(CHRONOS_SUPPORT_WAYLAND)
set(GLFW_BUILD_WAYLAND ON)
message("Building with Wayland support")
else()
set(GLFW_BUILD_WAYLAND OFF)
message("Building without Wayland support")
endif()
set(X11_X11_LIB who_cares)
set(GLFW_BUILD_EXAMPLES OFF)
set(GLFW_BUILD_TESTS OFF)
set(GLFW_BUILD_DOCS OFF)
set(GLFW_INSTALL OFF)
set(GLFW_VULKAN_STATIC ON)

#GLFW
add_subdirectory(ThirdParty/glfw)
set(GLFW_DIR ThirdParty/glfw/include)

#vulkan sdk if using windows
if (WIN32)
    set(VULKAN_SDK_DIR $ENV{VULKAN_SDK})        
    set(VULKAN_SDK_LIB ${VULKAN_SDK_DIR}/Lib/)                  
    set(VULKAN_SDK_INCLUDE ${VULKAN_SDK_DIR}/Include) 
endif (WIN32)

#source files
set(SOURCE_DIR Source/Engine/Source)
set(API_DIR Source/API/Source)
set(ANIMATION_DIR Source/Animation/Source)
file(GLOB MAIN ${SOURCE_DIR}/*.cpp)
file(GLOB API ${API_DIR}/*.cpp)
file(GLOB ANIMATION ${ANIMATION_DIR}/*.cpp)
file(GLOB FONTS_DIR ThirdParty/fonts/latin1/*)

#get all the cpp files
file(GLOB CHRONOS_CPP ${MAIN} ${API}  ${ANIMATION})

#create a fucntion to include all the directories, also link vulkan and glfw
function(IncludeDirectories projectName)
    target_include_directories(${projectName} PUBLIC Source/Engine/Headers)
    target_include_directories(${projectName} PUBLIC Source/Engine/Templates)
    target_include_directories(${projectName} PUBLIC Source/API/Headers)
    target_include_directories(${projectName} PUBLIC Source/Animation/Headers)
    target_include_directories(${projectName} PUBLIC Source/Common)
    target_include_directories(${projectName} PUBLIC ThirdParty/stb)
    target_include_directories(${projectName} PUBLIC include)
    target_include_directories(${projectName} PUBLIC ${FONTS_DIR})
    target_include_directories(${projectName} PUBLIC ${GLFW_DIR})  
    target_include_directories(${projectName} PUBLIC ThirdParty/earcut.hpp/include/mapbox)
    
    if(WIN32)
        target_link_libraries(${projectName} vulkan-1) 
    endif(WIN32)
    if(UNIX)
        target_link_libraries(${projectName} vulkan)   
    endif(UNIX)
    target_link_libraries(${projectName} glfw)

endfunction()

#build the executable
# linking
add_library(Chronos STATIC ${CHRONOS_CPP})
IncludeDirectories(${PROJECT_NAME})

#vulkan sdk if using windows
if(WIN32)
    target_include_directories(${PROJECT_NAME} PUBLIC ${VULKAN_SDK_INCLUDE})    
    target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${VULKAN_SDK_LIB}) 
    message("Vulkan SDK include found: ${VULKAN_SDK_INCLUDE}")
endif(WIN32) 

if(CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS)
target_compile_definitions(Chronos PUBLIC ENABLE_VULKAN_VALIDATION_LAYERS)
message("Vulkan validation layers enabled")
endif()
target_compile_definitions(Chronos PUBLIC GAME_NAME="${PROJECT_NAME}")
message("Game name: ${PROJECT_NAME}")
target_compile_definitions(Chronos PUBLIC GAME_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(Chronos PUBLIC GAME_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(Chronos PUBLIC GAME_VERSION_PATCH=${PROJECT_VERSION_PATCH})
message("Game version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
target_compile_definitions(Chronos PUBLIC CHRONOS_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(Chronos PUBLIC CHRONOS_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(Chronos PUBLIC CHRONOS_VERSION_PATCH=${PROJECT_VERSION_PATCH})
message("Chronos version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
if(CHRONOS_ENABLE_EXTREME_LOGGING)
target_compile_definitions(Chronos PUBLIC CHRONOS_ENABLE_LOGGING=4)
message("Extreme logging enabled(level 4)")
elseif(CHRONOS_ENABLE_VERBOSE_LOGGING)
target_compile_definitions(Chronos PUBLIC CHRONOS_ENABLE_LOGGING=3)
message("Verbose logging enabled(level 3)")
elseif(CHRONOS_ENABLE_BASIC_LOGGING)
target_compile_definitions(Chronos PUBLIC CHRONOS_ENABLE_LOGGING=2)
message("Basic logging enabled(level 2)")
elseif(CHRONOS_ENABLE_ERROR_LOGGING)
target_compile_definitions(Chronos PUBLIC CHRONOS_ENABLE_LOGGING=1)
message("Error logging enabled(level 1)")
else()
target_compile_definitions(Chronos PUBLIC CHRONOS_ENABLE_LOGGING=0)
message("Logging disabled(level 0)")
endif()


#editor executable
if(CHRONOS_BUILD_EDITOR)
message("Building editor")
set(EDITOR_DIR Source/Editor/Source)
set(IMGUI_DIR ThirdParty/imgui) 
set(IMGUI_BACKENDS ${IMGUI_DIR}/backends)
set(IMGUI_GUIZMO ThirdParty/ImGuizmo)
set(IMGUI_NODE_EDITOR_DIR ThirdParty/imgui-node-editor)

file(GLOB EDITOR ${EDITOR_DIR}/*.cpp)
file(GLOB IMGUI ${IMGUI_DIR}/*.cpp)
file(GLOB IM_GUIZMO_CPP ${IMGUI_GUIZMO}/*.cpp)
file(GLOB IMGUI_NODE_EDITOR_CPP ${IMGUI_NODE_EDITOR_DIR}/*.cpp)
file(GLOB EDITOR_FILES 
${EDITOR} 
${IMGUI} 
${IMGUI_BACKENDS}/imgui_impl_glfw.cpp 
${IMGUI_BACKENDS}/imgui_impl_vulkan.cpp
${IM_GUIZMO_CPP}
${IMGUI_NODE_EDITOR_CPP})

# linking
add_executable(ChronosEditor ${CHRONOS_CPP} ${EDITOR_FILES})

#vulkan sdk if using windows
if(WIN32)
    target_include_directories(ChronosEditor PUBLIC ${VULKAN_SDK_INCLUDE})     
    target_link_directories(ChronosEditor PUBLIC ${VULKAN_SDK_LIB})
    message("Vulkan SDK include found: ${VULKAN_SDK_INCLUDE}")
endif(WIN32) 

target_compile_definitions(ChronosEditor PUBLIC ENABLE_EDITOR)

if(CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS)
target_compile_definitions(ChronosEditor PUBLIC ENABLE_VULKAN_VALIDATION_LAYERS)
message("Vulkan validation layers enabled")
endif()

target_compile_definitions(ChronosEditor PUBLIC GAME_NAME="ChronosEditor")
message("Game name: ChronosEditor")
target_compile_definitions(ChronosEditor PUBLIC GAME_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(ChronosEditor PUBLIC GAME_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(ChronosEditor PUBLIC GAME_VERSION_PATCH=${PROJECT_VERSION_PATCH})
message("Game version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_VERSION_PATCH=${PROJECT_VERSION_PATCH})
message("Chronos version: ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

if(CHRONOS_ENABLE_EXTREME_LOGGING)
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_ENABLE_LOGGING=4)
message("Extreme logging enabled (level 4)")
elseif(CHRONOS_ENABLE_VERBOSE_LOGGING)
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_ENABLE_LOGGING=3)
message("Verbose logging enabled (level 3)")
elseif(CHRONOS_ENABLE_BASIC_LOGGING)
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_ENABLE_LOGGING=2)
message("Basic logging enabled (level 2)")
elseif(CHRONOS_ENABLE_ERROR_LOGGING)
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_ENABLE_LOGGING=1)
message("Error logging enabled (level 1)")
else()
target_compile_definitions(ChronosEditor PUBLIC CHRONOS_ENABLE_LOGGING=0)
message("Logging disabled (level 0)")
endif()
    

#header files
target_include_directories(ChronosEditor PUBLIC Source/Editor/Headers)
target_include_directories(ChronosEditor PUBLIC ${IMGUI_DIR})               
target_include_directories(ChronosEditor PUBLIC ${IMGUI_BACKENDS})
target_include_directories(ChronosEditor PUBLIC ${IMGUI_GUIZMO})    
target_include_directories(ChronosEditor PUBLIC ${IMGUI_NODE_EDITOR_DIR})
IncludeDirectories(ChronosEditor)
endif()

#testing time...
if(CHRONOS_BUILD_TESTS)
message("Building tests")
#fetch the test files
file(GLOB ENGINE_TESTS 
Source/Engine/Tests/*.cpp)
file(GLOB TEST_MAIN Source/Common/Tests/*.cpp)
file(GLOB API_TESTS Source/API/Tests/*.cpp)
#add google tests

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

enable_testing()
add_executable(ChronosTests ${ENGINE_TESTS} ${CHRONOS_CPP} ${TEST_MAIN} ${API_TESTS})

target_link_libraries(
  ChronosTests
  GTest::gtest_main
)
IncludeDirectories(ChronosTests)

if(CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS)
target_compile_definitions(ChronosTests PUBLIC ENABLE_VULKAN_VALIDATION_LAYERS)
message("Vulkan validation layers enabled")
endif()

target_compile_definitions(ChronosTests PUBLIC GAME_NAME="ChronosTests")
target_compile_definitions(ChronosTests PUBLIC GAME_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(ChronosTests PUBLIC GAME_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(ChronosTests PUBLIC GAME_VERSION_PATCH=${PROJECT_VERSION_PATCH})
target_compile_definitions(ChronosTests PUBLIC CHRONOS_VERSION_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(ChronosTests PUBLIC CHRONOS_VERSION_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(ChronosTests PUBLIC CHRONOS_VERSION_PATCH=${PROJECT_VERSION_PATCH})

if(CHRONOS_ENABLE_EXTREME_LOGGING)
target_compile_definitions(ChronosTests PUBLIC CHRONOS_ENABLE_LOGGING=4)
message("Extreme logging enabled (level 4)")
elseif(CHRONOS_ENABLE_VERBOSE_LOGGING)
target_compile_definitions(ChronosTests PUBLIC CHRONOS_ENABLE_LOGGING=3)
message("Verbose logging enabled (level 3)")
elseif(CHRONOS_ENABLE_BASIC_LOGGING)
target_compile_definitions(ChronosTests PUBLIC CHRONOS_ENABLE_LOGGING=2)
message("Basic logging enabled (level 2)")
elseif(CHRONOS_ENABLE_ERROR_LOGGING)
target_compile_definitions(ChronosTests PUBLIC CHRONOS_ENABLE_LOGGING=1)
message("Error logging enabled (level 1)")
else()
target_compile_definitions(ChronosTests PUBLIC CHRONOS_ENABLE_LOGGING=0)
message("Logging disabled (level 0)")
endif()


include(GoogleTest)
gtest_discover_tests(ChronosTests)
endif()