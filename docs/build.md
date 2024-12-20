# Build Instructions

[TOC]

## Table of Contents

+ [Cloning](#cloning)
+ [Dependencies](#dependencies)
    + [For Windows](#for-windows)
    + [For Linux and Unix-Like Systems](#for-linux-and-unix-like-systems)
+ [Configuring Flags](#configuring-flags)
+ [Build Commands](#build-commands)
+ [Compiling Shaders](#compiling-shaders)
+ [Building Documentation](#building-documentation)

## Cloning ##
### Make sure to clone this repo recursively. ###

```bash
git clone --recursive https://github.com/RahulVadhyar/Chronos.git
```

There are other submodule dependencies that need to be cloned to compile this.

## Dependencies ##

### For Windows ###

Install a compiler (visual studio or GCC or clang) and install [cmake](https://github.com/Kitware/CMake/releases/download/v3.29.0/cmake-3.29.0-windows-x86_64.msi). 

Make sure that the environment variables are set correctly and make sure that you can compile C/C++ projects.

For the other files download and install the Vulkan SDK(suggestion to use version 1.3.211.0) from this [link](https://sdk.lunarg.com/sdk/download/1.3.211.0/windows/VulkanSDK-1.3.211.0-Installer.exe). Select all the options. We are mainly interested in vulkan headers, vulkan validation layers, and GLM for now.

### For Linux and Unix Like Systems ###
This project uses GLM, GLFW, Vulkan Validation Layers. However we compile GLFW from source(its one of the submodules ;) )It also compiles GLFW from source(it is included as submodule) so we need its dependencies

+ **For Fedora, RHEL, CentOS and similar distributions:**

  Run the following terminal commands:
  ```bash
  sudo dnf install glm-devel vulkan-validation-layers cmake gcc
  sudo dnf builddep glfw glfw-devel
  ```

  We install all the dependencies that are needed by GLFW using the builddep command above.

  Optional: Install ninja-build and configure using ninja for faster build times.

+ **For Ubuntu, Debian and similar distributions:**

  The following commands will install the dependencies needed to build this project

  ```bash
  sudo apt install libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev libxext-dev libwayland-dev libxkbcommon-dev libvulkan-dev libglm-dev gcc-multilib g++-multilib libfreetype6-dev libglu1-mesa-dev freeglut3-dev mesa-common-dev cmake
  ```
  Optional: Install ninja-build and generate using ninja for faster build times(if you know how to do this).

+ **For Other Linux and Unix-Like platforms:**
  Due to the fact that this project is still in early development, I haven't tested this on anything other than Fedora Linux and Ubuntu Linux. However it should work on other systems. File an issue if you have any issues.

  We need the following packages or set of packages for compiling:
    - GLFW build dependencies(this includes the headers for X11 and Wayland)
    - Compiler of choice(GCC or Clang)
    - CMake
    - Vulkan headers
    - Vulkan validation layers
    - GLM headers

These can be installed using your package manager and you can continue the steps as normal.

## Configuring Chronos ##
To configure Chronos, just run the below command with cmake

```bash
ccmake -S . -B build
```

This will present a menu. Press c to configure and select the flags. The details of these flags are given below. Make sure to read them to set these correctly. After configuring these flags, press g to generate and exit this window. If you see any errors, file an issue and I will be happy to help you.

## Configuring Flags ##

There are multiple flags to configure to enable or disable certain features.
Please read the following section atleast once to understand the various options available and how they work.

**Note: Only set the flags that begin with ```CHRONOS_```. Other flags are for dependencies and these are set automatically. Do not touch them.**

If you get any errors, make sure that the necessary dependencies are installed. If you still have errors, file an issue.

### Available Flags ###

+ [CHRONOS_BUILD_EDITOR](#chronos_build_editor)
+ [CHRONOS_BUILD_TESTS](#chronos_build_tests)
+ [CHRONOS_ENABLE_PROFILING](#chronos_enable_profiling)
+ [CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS](#chronos_enable_vulkan_validation_layers)
+ [Logging](#logging)
    + [CHRONOS_ENABLE_ERROR_LOGGING](#chronos_enable_error_logging)
    + [CHRONOS_ENABLE_BASIC_LOGGING](#chronos_enable_basic_logging)
    + [CHRONOS_ENABLE_VERBOSE_LOGGING](#chronos_enable_verbose_logging)
    + [CHRONOS_ENABLE_EXTREME_LOGGING](#chronos_enable_extreme_logging)

### CHRONOS_BUILD_EDITOR ### 
Set this to ON to build the editor. If the editor is not needed for some reason, turn this off to not build editor.

### CHRONOS_BUILD_TESTS ### 
Set this to ON to build tests for this projects. This project uses the google testing framework and cmake will automatically get them when this flag is enabled. In most cases tests are not needed and this should be set to OFF

### CHRONOS_ENABLE_PROFILING ### 
If profiling APIs are needed or profiling metrics are to be shown in the editor, then this flag should be set to ON. Some of the metrics that are accessible are CPU time, frame time, update time etc. 

**Note: Frame time and FPS are shown in the editor under the debug metrics window. This can be shown by setting the checkbox under settings. Only if you want more detailed metrics or function calls to the profiling API, enable this. Should only be used for developement purpose.**

### CHRONOS_ENABLE_VULKAN_VALIDATION_LAYERS ### 
This will turn ON or OFF vulkan validation layer. Since this project is still experiemental and under development, it is reccommended to keep this on. This does cause a performance penalty. So if performance if needed, this can be turned off.

#### What is Vulkan Validation layer: ####

Vulkan validation layers provide a set of runtime checks and diagnostics to ensure that Chronos is using the Vulkan API correctly and efficiently. Without this, any bugs in the code may cause unexpected behaviour with Chronos, drivers and the overall system, since runtime checks are not present in the base vulkan driver. It can detect common mistakes and bugs, such as invalid API usage, memory leaks, and performance bottlenecks along with  providing detailed error messages and warnings, helping us identify and fix issues that may not be immediately apparant.

### Logging ### 
In order to provide warnings, errors, and timeline of function calls, Chronos outputs basic logs in the terminal. This is not collected in anyway, nor stored in any file(unless you output the terminal output to a file(of course XD )

If you have any issue, before filing an issue, make sure to enable a suitable level of logging(level 3 is recommended). Else logging is not needed. If all the logging flags are set to OFF, then no logging occurs.

For logging, there are 4 levels:

 + Error Logging(CHRONOS_ENABLE_ERROR_LOGGING)
 + Basic Logging(CHRONOS_ENABLE_BASIC_LOGGING)
 + Verbose Logging(CHRONOS_ENABLE_VERBOSE_LOGGING)
 + Extreme Logging(CHRONOS_ENABLE_EXTREME_LOGGING)

What is outputted in each of these levels is given below.

#### CHRONOS_ENABLE_ERROR_LOGGING ####

This is also level 1 logging. This outputs only error messages. Nothing else is returned. Can be used for debugging purposes.

#### CHRONOS_ENABLE_BASIC_LOGGING ####

This is also level 2 logging. This outputs everything in level 1 along with basic system information and some events.

#### CHRONOS_ENABLE_VERBOSE_LOGGING ####

This is level 3 logging. This outputs everything in level 2 logging along with information about changes that do not occur frequently(every frame). Things like buffer creation and destruction, shape creation and destruction etc are logged.

#### CHRONOS_ENABLE_EXTREME_LOGGING ####

This is level 4 logging. This is the most extreme version of logging. Information about every frame is logged. Every minute detail is logged and a lot of information is outputted.

**Note: Do not use this level unless instructed. It has performance penalties and a lot of extreme verbose is outputted. Most of it is useless anyways unless we need a specific thing. Just note that this exists. Do not use it.**

## Build Commands ##

To compile Chronos, its editor, and tests or a subset it depending on the flags set, run the following command.

```bash
cmake --build build --parallel
```

The parallel argument tells cmake to utilize all the CPU cores in your system to compile Chronos. This is recommended. However if you not wish to compile in parallel, this argument can be ommited.

After compiling, you will find the output in the build folder.

If you get any errors, make sure that the necessary dependencies are installed. If you still have errors, file an issue.

## Compiling Shaders ##

Shaders are generally precompiled and this step is not neccessary. You may skip this step.

If you do want to compile the shaders, install ```glslc```. On Windows this is bundled with Vulkan SDK . On Linux this is available from the package manager.
Then just run ```compile.bat``` for windows or ```compile.sh``` for linux in the terminal.

## Building Documentation ##

Documentation can be found online at this [link](https://rahulvadhyar.github.io/Chronos/). However if you wish to build the documentation yourself, then install doxygen and run the below command from inside Chronos. The documentation can be viewed by opening doxygen/index.html

```bash
doxygen ChronosDoc
```

