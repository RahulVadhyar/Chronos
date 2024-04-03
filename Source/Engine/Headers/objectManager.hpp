/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#pragma once

/** \file objectManager.hpp

 *  \brief Defines the ObjectManager class for managing objects in the Chronos::Engine namespace.
 */

namespace Chronos {
namespace Engine {

    /**
     * \brief Concept that checks if the given type is a class inheriting from the Object class.
     * \tparam T The type to check for the Object-like concept.
     */
    template <class T>
    concept ObjectLike = std::is_base_of<Chronos::Engine::Object, T>::value;

    /**
     * \class ObjectManager
     * \brief Manages objects within the Chronos::Engine namespace.
     *
     * The ObjectManager class is a generic template that manages objects within the Chronos::Engine namespace.
     * It provides functionalities for object initialization, destruction, rendering, and updating.
     * The managed objects must adhere to the ObjectLike concept, i.e., they should be derived from Chronos::Engine::Object.
     *
     * \tparam Object The type of object managed by this ObjectManager.
     */
    template <ObjectLike Object>
    class ObjectManager {
    public:
        int nextFreeObjectNo = 0; /**< The index for the next free object. */
        std::map<int, Object> objects; /**< A map of object indices to their corresponding objects. */
        std::vector<VkCommandBuffer> commandBuffers; /**< Vector of Vulkan command buffers. */

        /**
         * \brief Removes an object with the specified index.
         *
         * This function removes an object from the ObjectManager based on the provided index.
         * The associated Vulkan resources are also cleaned up, and the object is destroyed.
         *
         * \param objectNo The index of the object to remove.
         */
        void remove(int objectNo);

        /**
         * \brief Initializes the ObjectManager.
         *
         * This function initializes the ObjectManager with the given Chronos::Engine::Device, Chronos::Engine::SwapChain, and Vulkan command pool.
         * It creates necessary Vulkan resources like render pass, framebuffers, and command buffers.
         *
         * \param device Pointer to the Chronos::Engine::Device used for initialization.
         * \param swapChain Pointer to the Chronos::Engine::SwapChain used for initialization.
         * \param commandPool Vulkan command pool used for initialization.
         */

        void init(Chronos::Engine::Device* device, Chronos::Engine::SwapChain* swapChain, VkCommandPool commandPool);

        /**
         * \brief Destroys resources associated with the ObjectManager.
         *
         * This function cleans up all Vulkan resources and destroys objects managed by the ObjectManager.
         */
        void destroy();

        /**
         * \brief Updates the objects managed by the ObjectManager.
         *
         * This function updates all objects managed by the ObjectManager for the given frame.
         *
         * \param currentFrame The current frame number.
         */
        void update(uint32_t currentFrame);

        /**
         * \brief Renders the objects managed by the ObjectManager.
         *
         * This virtual function needs to be implemented by derived classes.
         * It initiates the rendering process for the specified frame and image index with a given background color.
         *
         * \param currentFrame The current frame number.
         * \param imageIndex The index of the image being rendered.
         * \param bgColor Array representing the background color.
         */
        virtual void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

        /**
         * \brief Changes the multisampling settings for rendering.
         *
         * This function changes the multisampling settings, recreating the Vulkan render pass accordingly.
         */
        void changeMsaa();

        /**
         * \brief Recreates resources for rendering.
         *
         * This function recreates Vulkan framebuffers after cleaning up the existing ones during swapchain recreation.
         */
        void recreate();

    protected:
        /**
         * \brief Ends the rendering process for the specified frame.
         *
         * This function marks the end of recording of vulkan rendering commands for the specified frame
         when started by the render command
         *
         * \param currentFrame The current frame number.
         */
        void endRender(uint32_t currentFrame);

        /**
         * \brief Adds an object to the ObjectManager.
         *
         * This function adds an object to the ObjectManager and assigns it a unique index.
         *
         * \param object The object to be added.
         * \return The index assigned to the added object.
         */
        int addObject(Object object);

        /**
         * \brief Creates the render pass used for rendering.
         *
         * This pure virtual function needs to be implemented by derived classes to create the Vulkan render pass.
         */
        virtual void createRenderPass() = 0;

        /**
         * \brief Cleans up resources associated with rendering.
         *
         * This function cleans up Vulkan framebuffers.
         This is called when swap chain is recreated.
         */
        void cleanup();
        Chronos::Engine::Device* device; /**< Pointer to the Chronos::Engine::Device used for rendering. */
        Chronos::Engine::SwapChain* swapChain; /**< Pointer to the Chronos::Engine::SwapChain used for rendering. */
        VkCommandPool commandPool; /**< Vulkan command pool used for rendering. */
        VkRenderPass renderPass; /**< Vulkan render pass used for rendering. */
        VkSampler textureSampler; /**< Vulkan sampler for textures. */
        std::vector<VkFramebuffer> framebuffers; /**< Vector of Vulkan framebuffers. */
        std::map<int, std::array<bool, MAX_FRAMES_IN_FLIGHT>> objectsToBeRemoved; /**< Map of objects to be removed. */
    };
};
};

#include "objectManagerDefs.tpp"