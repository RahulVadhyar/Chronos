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

/** \file objectManager.hpp

 *  \brief Defines the ObjectManager class for managing objects in the
 Chronos::Engine namespace.
 */

#pragma once
#include <map>
#include "object.hpp"

namespace Chronos {
namespace Engine {
    class ObjectManager {
    public:
	std::map<int, Object*> objects; /**< A map of object indices to their
					  corresponding objects. */
	int nextFreeObjectNo = 0; /**< The index for the next free object. */
	std::vector<VkCommandBuffer>
	    commandBuffers; /**< Vector of Vulkan command buffers. */
	void init(Chronos::Engine::Device* device,
	    Chronos::Engine::SwapChain* swapChain, VkCommandPool commandPool);
	void destroy();

	int addObject(Object* object);
	void remove(int objectNo);

	void update(uint32_t currentFrame);
	void render(
	    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

	void changeMsaa();
	void recreate();
	void cleanup();
	VkRenderPass renderPass; /**< Vulkan render pass used for rendering. */
	VkSampler textureSampler; /**< Vulkan sampler for textures. */

    private:
	Chronos::Engine::Device*
	    device; /**< Pointer to the Chronos::Engine::Device used for
		       rendering. */
	Chronos::Engine::SwapChain*
	    swapChain; /**< Pointer to the Chronos::Engine::SwapChain used for
			  rendering. */
	VkCommandPool
	    commandPool; /**< Vulkan command pool used for rendering. */
	std::vector<VkFramebuffer>
	    framebuffers; /**< Vector of Vulkan framebuffers. */
	std::map<int, std::array<bool, MAX_FRAMES_IN_FLIGHT>>
	    objectsToBeRemoved; /**< Map of objects to be removed. */
    };
};
};