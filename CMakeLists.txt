cmake_minimum_required(VERSION 3.13)
project(Chronos)

set(CMAKE_CXX_STANDARD 20)



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

#again windows vulkan stuf....git 
if(WIN32)
    target_link_directories(${CMAKE_PROJECT_NAME} PUBLIC ${VULKAN_SDK_LIB})
    # link_directories(${VULKAN_SDK_LIB})     
endif(WIN32)

# linking
add_library(Chronos ${MAIN} ${API} ${IMGUI} ${EDITOR} ${ANIMATION}
            ${IMGUI_BACKENDS}/imgui_impl_glfw.cpp 
            ${IMGUI_BACKENDS}/imgui_impl_vulkan.cpp
            ${IM_GUIZMO_CPP}
            ${IMGUI_NODE_EDITOR_CPP}
            )

#vulkan sdk if using windows
if(WIN32)
    target_include_directories(${PROJECT_NAME} PUBLIC ${VULKAN_SDK_INCLUDE})     
endif(WIN32) 

#header files
target_include_directories(${PROJECT_NAME} PUBLIC Source/Engine/Headers)
target_include_directories(${PROJECT_NAME} PUBLIC Source/API/Headers)
target_include_directories(${PROJECT_NAME} PUBLIC Source/Editor/Headers)
target_include_directories(${PROJECT_NAME} PUBLIC Source/Animation/Headers)
target_include_directories(${PROJECT_NAME} PUBLIC Source/Common)
target_include_directories(${PROJECT_NAME} PUBLIC ThirdParty/stb)
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PUBLIC ${GLFW_DIR})  
target_include_directories(${PROJECT_NAME} PUBLIC ${IMGUI_DIR})               
target_include_directories(${PROJECT_NAME} PUBLIC ${IMGUI_BACKENDS})
target_include_directories(${PROJECT_NAME} PUBLIC ${FONTS_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${IMGUI_GUIZMO})    
target_include_directories(${PROJECT_NAME} PUBLIC ${IMGUI_NODE_EDITOR_DIR})


#linking vulkan is a pain....
if(WIN32)
target_link_libraries(${PROJECT_NAME} vulkan-1) 
endif(WIN32)
if(UNIX)
target_link_libraries(${PROJECT_NAME} vulkan)   
endif(UNIX)
target_link_libraries(${PROJECT_NAME} glfw)



#testing time...

#fetch the test files
file(GLOB ENGINE_TESTS Source/Engine/Tests/*.cpp)

#add google tests
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(
  ChronosTests
    ${ENGINE_TESTS}
    ${MAIN} ${API} ${IMGUI} ${EDITOR} ${ANIMATION}
            ${IMGUI_BACKENDS}/imgui_impl_glfw.cpp 
            ${IMGUI_BACKENDS}/imgui_impl_vulkan.cpp
            ${IM_GUIZMO_CPP}
            ${IMGUI_NODE_EDITOR_CPP}
)
target_link_libraries(
  ChronosTests
  GTest::gtest_main
)
if(WIN32)
target_link_libraries(ChronosTests vulkan-1) 
endif(WIN32)
if(UNIX)
target_link_libraries(ChronosTests vulkan)   
endif(UNIX)
target_link_libraries(ChronosTests glfw)
target_include_directories(ChronosTests PUBLIC Source/Engine/Headers)
target_include_directories(ChronosTests PUBLIC Source/API/Headers)
target_include_directories(ChronosTests PUBLIC Source/Editor/Headers)
target_include_directories(ChronosTests PUBLIC Source/Animation/Headers)
target_include_directories(ChronosTests PUBLIC Source/Common)
target_include_directories(ChronosTests PUBLIC ThirdParty/stb)
target_include_directories(ChronosTests PUBLIC include)
target_include_directories(ChronosTests PUBLIC ${GLFW_DIR})  
target_include_directories(ChronosTests PUBLIC ${IMGUI_DIR})               
target_include_directories(ChronosTests PUBLIC ${IMGUI_BACKENDS})
target_include_directories(ChronosTests PUBLIC ${FONTS_DIR})
target_include_directories(ChronosTests PUBLIC ${IMGUI_GUIZMO})    
target_include_directories(ChronosTests PUBLIC ${IMGUI_NODE_EDITOR_DIR})


include(GoogleTest)
gtest_discover_tests(ChronosTests)
