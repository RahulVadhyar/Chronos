# Chronos(v0.0)
[TOC]

A advanced 2D rendering and animation engine written in C++ and using the Vulkan graphics rendering API.
Supports many advanced features and is performant, hackable and flexbile that can cater to a wide range of needs,
including simple 2D game development.

**Please Note** : This project is currently under development and is not stable yet. All features are not final.

## Cloning:
***Make sure to clone this repo recursively.***

There are other submodule dependencies that need to be cloned to compile this.
```bash
git clone --recursive https://github.com/RahulVadhyar/Chronos.git
```

## Table of Contents
+ [Dependencies](#dependencies)
+ [How To Use](#how-to-use)
+ [API Documentation](#api-documentation)
+ [How to file an issue](#how-to-file-an-issue)
+ [Libraries used](#libraries-used)
+ [Contributing](#contributing)
+ [FAQs](#faqs)
  + [Why did I choose Vulkan over OpenGL?](#why-did-i-choose-vulkan-over-opengl)
  + [Why did I choose Vulkan over other alternatives?](#why-did-i-choose-vulkan-over-other-alternatives)
  + [Which platforms are supported?](#which-platforms-are-supported)
  + [Is Wayland and/or X11 supported?](#is-wayland-and/or-x11-supported)
  + [Why is MacOS not supported?](#why-is-macos-not-supported)
  + [Why just not use Unreal Engine or Unity or similar engine](#why-not-just-use-unreal-engine-or-unity-or-similar-engine)
  + [Can I use this for my project?](#can-i-use-this-for-my-project)
  + [Are there any projects that use this library as an example?](#are-there-any-projects-that-use-this-library-as-an-example)

## Dependencies
### For Windows:
Download and install the Vulkan SDK from this [link](https://sdk.lunarg.com/sdk/download/latest/windows/vulkan-sdk.exe). Everything needed is in that package.

### For Linux and Unix like systems ###
This project uses GLM, GLFW, Vulkan Validation Layers. It also compiles GLFW from source(it is included as submodule) so we need its dependencies
+ #### For Fedora Linux: ####
  Run the following terminal commands:
  ```bash
  sudo dnf install glm-devel vulkan-validation-layers glfw glfw-devel
  sudo dnf builddep glfw glfw-devel
  ```
+ #### For Other Linux and Unix-Like platforms: ####
  Due to the fact that this project is still in early development, I haven't tested this on anything other than Fedora Linux.
However the needed dependencies are given above and can be installed using your package manager.
  

## How To Use ##
  In order to use this library with your project, you will need to use cmake. Install the dependencies. Then clone this(recursively) to your project and add it. Then in CMakeLists.txt, write it as follows
  ```cmake
  cmake_minimum_required(VERSION 3.13)
  project(YourProject)
  set(CMAKE_CXX_STANDARD 20)
  set(CHRONOS_INCLUDE_DIR path/to/Chronos/include)
  include_directories(BEFORE ${CHRONOS_INCLUDE_DIR})
  
  #add your stuff here
  
  add_subdirectory(path/to/Chronos)
  target_link_libraries(YourProject Chronos)
  ```
## API Documentation ##
The documentation for this library is under the docs section.

## How to file an issue ##
As this is early stages of development, issues are not taken right now. However they will be soon open.

## Libraries used ##
All the libraries and third party code is inside the ThirdParty folder.
The dependencies along with the usage is given as shown:
+ GLFW: This is a cross platform window system. It converts the different protocols of
  different display managers such as Windows DVM, X11 and Wayland into a common protocol
  that can be used.

+ ImGui: This is a immediate GUI system. This is not intended to be used for final use. Instead it is used in the editor provided. 

+ ImGui Node Editor: As described by its name, its a Node editor that is used in the editor.
+ ImGuizmo: This provided guizmo tools for the editor for dragging shapes and other objects.
+ STB: This includes all the stb headers(stb_image.h) and ini font files that are used by this project. It is used for image loading and font loading.

## Contributing ##
As this project is still under development and does not have a stable release, I do not accept any contributions for now. However they will soon be open.

## FAQs ##
* ### Why did I choose Vulkan over OpenGL? ###
  My first attempt at this to use OpenGL. However during development, I realized that
  OpenGL has some issues due to the fact that it was an old API not made for modern software.
  Some of the issues that OpenGL had that did not work for this project was:
  * No support for multithreading and parallelism
  * Not much control over the internal working, vulkan does this better
  * Some manufacturers are deprecating support for OpenGL and/or have issues in their drivers
  * Limited debugging and validation support
  * OpenGL has a considerable amount of overhead compared to modern rendering APIs. Since
    the intended use was 2D rendering, which is inherently going to be CPU limited, this would have
    been a problem

  These are just some of the highlights of the limitations and issues with OpenGL. While OpenGL is a remarkably simple
  API for rendering compared to Vulkan, it was just not the right fit for this project. Hence Vulkan is the graphics API of choice.
  
* ### Why did I choose Vulkan over other alternatives? ###
  One of the goals of this project is that I wanted support for as many platforms as possible, with at a minimum Windows and Linux.
  My other options include metal(only for Apple platforms), DirectX(only for windows.. well sort of..(proton) but not cross platform natively)
  and SDL. After evaluating all the options it was clear that Vulkan was the way to go.

* ### Is Wayland and/or X11 supported? ###
  Yes. Since this project uses GLFW that is compiled from scratch, it supports both Wayland and X11 platforms. However this is built for X11 by default. This can be changed by setting the GLFW flag. For more information on this, see [compiling GLFW].(https://www.glfw.org/docs/3.3/compile.html)

* ### Which platforms are supported? ###
  As of right now, Windows and Linux(includes unix-like OSes) are supported. MacOS is not supported. See below for reason.

* ### Why is MacOS not supported? ###
  There is nothing about this project that makes it incompatible with macs. You can get vulkan to run on MacOS via MoltenVK.
  However I currently do not have access to a mac that I can test on, as due to the CI/CD system, I need to be able to compile this project on a
  regular basis. Hence for now, there is no macOS support. However if there is anything missing that prevents macOS support, please let me know and
  I will incorporte those changes.
  
* ### Why just not use Unreal Engine or Unity or similar engine? ###
  Well there are mainly two reasons for this. One is that when I started this project I wanted to learn to write C++ and learn software development
  and all its quirks. The second reason is that the other libraries or engines target 3D rendering with 2D added as an afterthought. I wanted a custom dedicated
  2D renderer for the game that I am developing that I can add custom features to as and when needed. Hence I went ahead and created Chronos

* ### Can I use this for my project? ###
  Regarding licensing, this is fully open souce, and in the public domain. There are no restrictions, do as you please. However please note that until v1.0, API stability is
  not guaranteed and will break. Also due to the fact that this is in not stable, there will be bugs and issues. Please keep this in mind while using this.

* ### Are there any projects that use this library as an example? ###
  Currently my [game](https://github.com/RahulVadhyar/StreetChase.git) is used as a test bed and is developed simultaenously. As of now, no other project uses this to the best of my knowledge.
