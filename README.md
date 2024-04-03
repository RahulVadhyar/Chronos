# Chronos(v0.0)
[TOC]

[![Build](https://github.com/RahulVadhyar/Chronos/actions/workflows/buildAndTest.yml/badge.svg?branch=master)](https://github.com/RahulVadhyar/Chronos/actions/workflows/buildAndTest.yml)
[![Documentation](https://github.com/RahulVadhyar/Chronos/actions/workflows/pages/pages-build-deployment/badge.svg)](https://github.com/RahulVadhyar/Chronos/actions/workflows/pages/pages-build-deployment)

An advanced 2D rendering and animation engine written in C++ and using the Vulkan graphics rendering API.
Supports many advanced features and is performant, hackable and flexbile that can cater to a wide range of needs,
including simple 2D game development. It comes with an editor for fast prototyping and easy use.

**Please Note** : This project is currently under development and is not stable yet. All features are not final.

## Cloning:
### Make sure to clone this repo recursively. ###

There are other submodule dependencies that need to be cloned to compile this.
```bash
git clone --recursive https://github.com/RahulVadhyar/Chronos.git
```

## Table of Contents
+ [What is Chronos?](#what-is-chronos)
+ [Building Chronos](#building-chronos)
+ [How To Use](#how-to-use)
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
  + [Does the editor have the same feature set across Linux and Windows?](#does-the-editor-have-the-same-feature-set-across-linux-and-windows)

## What is Chronos? ##

Chronos is a advanced 2D rendering and animation engine written in C++ and designed around Vulkan API.

It is

  + High Performance
  + Relatively small in size and footprint
  + Cross platform(Windows and Linux)
  + Easy to use
  + Supports Animations
  + Has a simple, powerful and easy to use editor
  + Open source(ofc ;) )
  
It is not
  + A game
  + GUI library
  + 3D engine
  + Physics Engine
  + Sound Engine
  + Texture Creator etc... I think you get the point by now. 

Chronos is designed for use with 2D games that want a small footprint.
Chronos accomplishes this by providing a small yet complete API that can be used in projects for use.
No game logic, input handling or the many other things needed for a game is provided. Chronos is focused and has only one purpose.

## Building Chronos ##

Detailed build instructions can be found [here](docs/build.md)

## How To Use ##
  Detailed documentation and usage guides of both API and Editor along with tutorials and examples can be found [here](https://rahulvadhyar.github.io/Chronos/)

## How to file an issue ##
See [FilingIssues.md](docs/FilingIssues.md) for more information on how to collect and file issues.

## Libraries used ##
See [LibrariesUsed.md](docs/LibrariesUsed.md) for more information on third party dependencies of this project.

## Contributing ##
See [Contributing.md](docs/Contributing.md) for more information on how to contribute to this project.

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
    been slower than using vulkan.

  These are just some of the highlights of the limitations and issues with OpenGL. While OpenGL is a remarkably simple
  API for rendering compared to Vulkan, it was just not the right fit for this project. Hence Vulkan is the graphics API of choice.
  
* ### Why did I choose Vulkan over other alternatives? ###
  One of the goals of this project is that I wanted support for as many platforms as possible, with at a minimum Windows and Linux.
  My other options include metal(only for Apple platforms), DirectX(only for windows.. well sort of..(proton) but not cross platform natively)
  and SDL. After evaluating all the options it was clear that Vulkan was the way to go.

* ### Is Wayland and/or X11 supported? ###
  Yes. Since this project uses GLFW that is compiled from scratch, it supports both Wayland and X11 platforms. The flags are set such that they are built for both by default. Note that some features of the editor on linux is disabled due to limitations of X11 and Wayland(see [below](#does-the-editor-have-the-same-feature-set-across-linux-and-windows))

* ### Which platforms are supported? ###
  As of right now, Windows and Linux(includes unix-like OSes) are supported. MacOS is not supported. See below for reason.

* ### Why is MacOS not supported? ###
  While Vulkan applications can be run on a mac via moltenVK, I have not tested it, and there might be certain things broken. If you really want, you can try it yourself, this is open source and free after all. ;)
  
* ### Why just not use Unreal Engine or Unity or similar engine? ###
  Well there are mainly two reasons for this. One is that when I started this project I wanted to learn to write C++ and learn software development
  and all its quirks. The second reason is that the other libraries or engines target 3D rendering with 2D added as an afterthought. I wanted a custom dedicated
  2D renderer along with a small performant animation engine for the game that I am developing that I can add custom features to as and when needed. Hence I went ahead and created Chronos

* ### Can I use this for my project? ###
  Regarding licensing, this is fully open souce, and in the public domain. There are no restrictions, do as you please. However please note that until v1.0, API stability is
  not guaranteed and will break. Also due to the fact that this is in not stable, there will be bugs and issues. Please keep this in mind while using this.

* ### Are there any projects that use this library as an example? ###
  Currently my [game](https://github.com/RahulVadhyar/StreetChase.git) is used as a test bed and is developed simultaenously. As of now, no other project uses this to the best of my knowledge.

* ### Does the editor have the same feature set across Linux and Windows? ###
  No. However the only thing that is missing is the multi viewports(windows) feature. This is due to lack of support from ImGui(the GUI library I am using for this) due to no easy way to do this in X11 and wayland. While X11 is supported to an extent by ImGui for this, its extremely buggy and I cannot support it. However, this is the only feature missing and all other features are fully supported. This limitation will not affect 90% of use cases
