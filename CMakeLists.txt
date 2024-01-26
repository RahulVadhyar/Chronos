cmake_minimum_required(VERSION 3.13)
project(Chronos)
set(CMAKE_CXX_STANDARD 20)
# set(CMAKE_BUILD_TYPE Debug)

set(GLFW_USE_WAYLAND ON)
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

#imgui
set(IMGUI_DIR ThirdParty/imgui) 
set(IMGUI_BACKENDS ${IMGUI_DIR}/backends)

#imGuizmo
set(IMGUI_GUIZMO ThirdParty/ImGuizmo)

#imgui-node-editor
set(IMGUI_NODE_EDITOR_DIR ThirdParty/imgui-node-editor)

#fonts
set(FONTS_DIR ThirdParty/fonts/usascii/arial)
set(FONTS_DIR ThirdParty/fonts/latin1/consolas)

#source files
set(SOURCE_DIR Source/Engine/Source)
set(API_DIR Source/API/Source)
set(EDITOR_DIR Source/Editor/Source)
set(ANIMATION_DIR Source/Animation/Source)
file(GLOB MAIN ${SOURCE_DIR}/*.cpp)
file(GLOB API ${API_DIR}/*.cpp)
file(GLOB EDITOR ${EDITOR_DIR}/*.cpp)
file(GLOB ANIMATION ${ANIMATION_DIR}/*.cpp)
file(GLOB IMGUI ${IMGUI_DIR}/*.cpp)
file(GLOB IM_GUIZMO_CPP ${IMGUI_GUIZMO}/*.cpp)
file(GLOB IMGUI_NODE_EDITOR_CPP ${IMGUI_NODE_EDITOR_DIR}/*.cpp)

#get all the cpp files
file(GLOB CHRONOS_CPP ${MAIN} ${API} ${IMGUI} ${EDITOR} ${ANIMATION}
${IMGUI_BACKENDS}/imgui_impl_glfw.cpp 
${IMGUI_BACKENDS}/imgui_impl_vulkan.cpp
${IM_GUIZMO_CPP}
${IMGUI_NODE_EDITOR_CPP})

#create a fucntion to include all the directories, also link vulkan and glfw
function(IncludeDirectories projectName)
    target_include_directories(${projectName} PUBLIC Source/Engine/Headers)
    target_include_directories(${projectName} PUBLIC Source/API/Headers)
    target_include_directories(${projectName} PUBLIC Source/Editor/Headers)
    target_include_directories(${projectName} PUBLIC Source/Animation/Headers)
    target_include_directories(${projectName} PUBLIC Source/Common)
    target_include_directories(${projectName} PUBLIC ThirdParty/stb)
    target_include_directories(${projectName} PUBLIC include)
    target_include_directories(${projectName} PUBLIC ${GLFW_DIR})  
    target_include_directories(${projectName} PUBLIC ${IMGUI_DIR})               
    target_include_directories(${projectName} PUBLIC ${IMGUI_BACKENDS})
    target_include_directories(${projectName} PUBLIC ${FONTS_DIR})
    target_include_directories(${projectName} PUBLIC ${IMGUI_GUIZMO})    
    target_include_directories(${projectName} PUBLIC ${IMGUI_NODE_EDITOR_DIR})
    
    if(WIN32)
        target_link_libraries(${projectName} vulkan-1) 
    endif(WIN32)
    if(UNIX)
        target_link_libraries(${projectName} vulkan)   
    endif(UNIX)
    target_link_libraries(${projectName} glfw)

    
endfunction()



#build the executable
#again windows vulkan stuf....git 
if(WIN32)
    target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${VULKAN_SDK_LIB})
endif(WIN32)

# linking
add_library(Chronos STATIC ${CHRONOS_CPP})

#vulkan sdk if using windows
if(WIN32)
    target_include_directories(${PROJECT_NAME} PUBLIC ${VULKAN_SDK_INCLUDE})     
endif(WIN32) 

target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_EDITOR)
target_compile_definitions(${PROJECT_NAME} PUBLIC ENABLE_VULKAN_VALIDATION_LAYERS)
#header files
IncludeDirectories(${PROJECT_NAME})

#testing time...
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

include(GoogleTest)
gtest_discover_tests(ChronosTests)
