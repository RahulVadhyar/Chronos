# Chronos(v0.0)
A advanced 2D rendering and animation engine written in C++ and using the Vulkan graphics rendering API.
Supports many advanced features and is performant, hackable and flexbile that can cater to a wide range of needs,
including simple 2D game development.

## Table of Contents
+ [How To Use](#how-to-use)
+ [API Documentation](#api-documentation)
+ [How to file an issue](#how-to-file-an-issue)
+ [Contributing](#contributing)
+ [FAQs](#faqs)
## How To Use
## API Documentation
## How to file an issue
## Contributing
## FAQs
* ### Why did I choose Vulkan over OpenGL?
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
  API for rendering compared to Vulkan, it was just not the right fit for this project. Hence Vulkan is the renderer
* ### Why did I choose Vulkan over (insert alternative graphics API here)?
  One of the goals of this project is that I wanted support for as many platforms as possible, with at a minimum Windows and Linux.
  My other options include metal(only for Apple platforms), DirectX(only for windows.. well sort of..(proton) but not cross platform natively)
  and SDL. After evaluating all the options it was clear that Vulkan was the way to go.

* ### Which platforms are supported?
  As of right now, Windows and Linux are supported.

* ### Why is MacOS not supported?
  There is nothing about this project that makes it incompatible with macs. You can get vulkan to run on MacOS via MoltenVK.
  However I currently do not have access to a mac that I can test on, as due to the CI/CD system, I need to be able to compile this project on a
  regular basis. Hence for now, there is no macOS support. However if there is anything missing that prevents macOS support, please let me know and
  I will incorporte those changes.
* ### Why just not use Unreal Engine or Unity or similar library?
  
