#pragma once
#include "shape.hpp"

/** \file shapeManager.hpp

 \brief Contains the class for managing shapes.
*/
namespace Chronos {
namespace Engine {

    /**
    \brief This is the shape manager for Chronos. It handles creation, modification, updating and desrtuction of shapes.

    This is for use by ```Engine``` only and should not be used for any other purpose.
    Code using Chronos should not use this class directly.
    Along with managing the shapes, its uniforms(shader variables) and its textures,
    it also providies the commandPools, commandBuffers, renderPasses, framebuffers and textureSamplers needed for rendering this as a seperate pass.

    Generally in order to manage shapes the methods to be used are:
    - ```addTriangle```
    - ```addRectangle```
    - ```removeShape```

    The rest of the methods are to be used for rendering with the ```Engine``` class and should not be used directly.
    This class creates its own renderPass for rendering the shapes.
    */
    class ShapeManager {
    public:
        /**
        \brief The next free index for storing shapes in shapes.
        */
        int nextFreeShapeNo = 0;

        /**
        \brief Map of shape numbers to shapes.
        */
        std::map<int, Shape> shapes;

        /**
        \brief Set of command buffers for rendering the shapes.

        This is the command Buffers to which the rendering commands needed to render the shapes are recorded .
        This gets updated on calling ```render``` method.
        */
        std::vector<VkCommandBuffer> commandBuffers;

        /**
        \brief Initalizer for this class

        Creates all the necessary Vulkan objects and variables needed for rendering shapes.
        This includes creating
        - render pass
        - framebuffers
        - command buffers

        @param device The device to render the shapes on.
        @param swapChain The swapchain to render the shapes on.
        @param commandPool The command pool to create the command buffers on.
        */
        void init(Chronos::Engine::Device* device, Chronos::Engine::SwapChain* swapChain, VkCommandPool commandPool);

        /**
        \brief Used to add a triangle to the screen.

        Returns the shape no of the triangle added. This is used to modify and reference the triangle later.
        This corresponds to the index of the triangle in the shapes map.

        @param shapeParams This is the parameters of the triangle to be added.
        @param texturePath This is the path to the texture to be used for the triangle. Only png and jpg are supported.

        @return This returns the shape number of the triangle added. This is used to modify and reference the triangle later.
        */
        int addTriangle(Chronos::Engine::ShapeParams shapeParams, std::string texturePath);

        /**
        \brief Used to add a rectangle to the screen.

        Returns the shape no of the rectangle added. This is used to modify and reference the rectangle later.
        This corresponds to the index of the rectangle in the shapes map.

        @param shapeParams This is the parameters of the rectangle to be added.
        @param texturePath This is the path to the texture to be used for the rectangle. Only png and jpg are supported.

        @return This returns the shape number of the rectangle added. This is used to modify and reference the triangle later.
        */
        int addRectangle(Chronos::Engine::ShapeParams shapeParams, std::string texturePath);

        /**
        \brief Remove a shape from the manager.

        When we no longer want a shape to be displayed, we can remove it using this method.

        @param shapeNo This is the shape number of the shape to be removed.
        This is the number that was returned when the shape was added when calling ```addTriangle``` or ```addRectangle```.
        */
        void removeShape(int shapeNo);

        /**
        \brief Destroy the Vulkan objects and variables created by this class.

        This is not done using a destructor(```~ShapeManager```) as the destruction of objects in Vulkan has to be in a specific order and will
        not be guaranteed if such methods are used. Hence explicit methods are used for destruction.
        */
        void destroy();

        /**
        \brief Update the uniforms of the shapes for the current frame.

        This is to be called before render to ensure that the shapes are updated.
        @param currentFrame This is the current frame number that is to be queued for rendering. This is used to update the shapes.
        */
        void update(uint32_t currentFrame);

        /**
        \brief Record the commands needed to render the shapes to the command buffers.

        This is to be called after ```update``` to ensure that the shapes are updated.

        @param currentFrame This is the current frame number that is to be queued for rendering.
        @param imageIndex This is the index of the image in the swapchain that is to be rendered to.
        @param bgColor This is the background color of the window. This is used to clear the screen before rendering the shapes if this is the first or standalone renderPass.
        */
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

        /**

        \brief If MSAA is updated, this method must be called.

        If the MSAA is changed, this method has to be called to recreate the renderPass and framebuffers, along with associated objects
        */
        void changeMsaa();

        /**
        /brief If the swapChain has to be recreated, this method must be called.

        If the swapChain is invalid or has to be recreated, this method has to be called to recreate the renderPass and framebuffers, along with associated objects
        */
        void recreate();

    private:
        /**
        \brief Cleanup the rendering objects.

        This is used to desroy the renderPass and framebuffers, along with associated objects during recreation of such objects.
        This is not equal to ```destroy``` as this does not destroy the shapes, their uniforms or their textures.
        This is just used to destroy the objects that are needed for rendering the shapes.
        */
        void cleanup();

        /**
        \brief The device to render the shapes on.
        */
        Chronos::Engine::Device* device;

        /**
        \brief The swapchain to render the shapes on.
        */
        Chronos::Engine::SwapChain* swapChain;

        /**
        \brief The command pool to create the command buffers on.
        */
        VkCommandPool commandPool;

        /**
        \brief RenderPass used for rendering the shapes
        */
        VkRenderPass renderPass;

        /**
        \brief The texture sampler used for the shapes.
        */
        VkSampler textureSampler;

        /**
        \brief This is the framebuffers to which the output of the associated renderPass is written to.
        */
        std::vector<VkFramebuffer> framebuffers;
    };
};
};