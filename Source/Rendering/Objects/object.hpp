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

/** \file object.hpp

 \brief Contains the class for creating a generic object.
*/
#pragma once
#include "swapchain.hpp"
#include "objectTypes.hpp"
#include "buffers.hpp"
namespace Chronos {
namespace Engine {

    /**
     * \struct PipelineAttributes
     * \brief Structure defining attributes required for creating a graphics
     * pipeline.
     *
     * This structure encapsulates various settings necessary for configuring a
     * Vulkan graphics pipeline, including vertex input descriptions, primitive
     * topology, front face winding order, and color blending.
     */
    struct PipelineAttributes {
	std::vector<VkVertexInputBindingDescription>
	    bindingDescriptions; /**< Vertex input binding descriptions. */
	std::vector<VkVertexInputAttributeDescription>
	    attributeDescriptions; /**< Vertex input attribute descriptions. */
	VkPrimitiveTopology
	    topology; /**< Primitive topology of the pipeline. */
	VkFrontFace
	    frontFace; /**< Front face winding order for polygon culling. */
	VkPipelineColorBlendAttachmentState
	    colorBlendAttachment; /**< Color blending attachment state. */
    };

    /**
    * \class Object
    * \brief Abstract class for creating and managing generic graphical objects.
    *
    * The Object class provides an interface for creating and managing generic
    graphical objects.
    * Derived classes are expected to implement specific functionality for
    initialization, updates, and destruction of the object depending on specific
    use case.
    */
    class Object {

    public:
	/**
	 * \brief Initializes the object.
	 *
	 * This method initializes the Object with necessary Vulkan-related
	 * parameters, such as the device, command pool, swap chain, texture
	 * sampler, and render pass. It also allocates uniform buffers and
	 * creates descriptor sets, descriptor pool, descriptor set layout, and
	 * the graphics pipeline for rendering the object.
	 *
	 * \param device The device used by the object.
	 * \param commandPool Vulkan command pool for the object.
	 * \param swapChain Swap chain used by the object.
	 * \param textureSampler Vulkan texture sampler used by the object.
	 * \param renderPass Vulkan render pass that is used for rendering
	 * object in question.
	 */
	void init(Chronos::Engine::Device* device, VkCommandPool commandPool,
	    Chronos::Engine::SwapChain* swapChain, VkSampler textureSampler,
	    VkRenderPass* renderPass, ObjectType objectType);

	/**
	 * \brief Updates the object for the current frame.
	 *
	 * This pure virtual method must be implemented by derived classes to
	 * perform any updates required for the object during each frame. The
	 * `currentFrame` parameter represents the index of the current frame in
	 * the application.
	 *
	 * \param currentFrame Index of the current frame.
	 */
	virtual void update(uint32_t currentFrame) = 0;

	virtual void render(uint32_t currentFrame, uint32_t imageIndex,
	    float bgColor[3], VkViewport& viewport, VkRect2D& scissor,
	    std::vector<VkCommandBuffer>& commandBuffers)
	    = 0;

	/**
	 * \brief Destroys the object and releases associated resources.
	 *
	 * This method is responsible for cleaning up the object's resources,
	 * including uniform buffers, descriptor pool, descriptor set layout,
	 * graphics pipeline, and pipeline layout.
	 */
	virtual void destroy() = 0;

	/**
	 * \brief Recreates the graphics pipeline for the object.
	 *
	 * This method is used to recreate the graphics pipeline when needed,
	 * typically after changes in the rendering configuration such as MSAA
	 * changes. It destroys the existing graphics pipeline and pipeline
	 * layout before creating a new one.
	 */
	void recreateGraphicsPipeline();
	VkPipeline graphicsPipeline; /**< Vulkan graphics pipeline used by the
					object. */
	VkPipelineLayout
	    pipelineLayout; /**< Vulkan pipeline layout used by the object. */
	std::vector<VkDescriptorSet>
	    descriptorSets; /**< Vulkan descriptor sets associated with the
			       object. */
	Chronos::Engine::ObjectType objectType; /**< Type of the object. */

    protected:
	std::string vertexShaderPath; /**< Path to the vertex shader file. */
	std::string
	    fragmentShaderPath; /**< Path to the fragment shader file. */
	Chronos::Engine::Device* device; /**< Device to render to. */
	Chronos::Engine::SwapChain* swapChain; /**< Swapchain to present to. */
	VkCommandPool
	    commandPool; /**< Vulkan command pool associated with the object. */
	VkSampler
	    textureSampler; /**< Vulkan texture sampler used by the object. */
	VkRenderPass*
	    renderPass; /**< Renderpass that the object will render to. */
	VkDescriptorSetLayout
	    descriptorSetLayout; /**< Vulkan descriptor set layout used by the
				    object. */
	VkDescriptorPool
	    descriptorPool; /**< Vulkan descriptor pool used by the object. */
	/**
	 * \brief Creates the graphics pipeline for the object.
	 *
	 * This method is responsible for configuring and creating the Vulkan
	 * graphics pipeline used by the object, including shader modules,
	 * vertex input, input assembly, viewport, rasterization, multisampling,
	 * color blending, and dynamic states.
	 */
	void createGraphicsPipeline();

	/**
	 * \brief Creates the Vulkan descriptor pool for the object.
	 *
	 * This method sets up and creates the Vulkan descriptor pool based on
	 * the descriptor types used by the object.
	 */
	void createDescriptorPool();

	/**
	 * \brief Creates the Vulkan descriptor set layout for the object.
	 *
	 * This method sets up and creates the Vulkan descriptor set layout
	 * based on the descriptor types and stages used by the object.
	 */
	void createDescriptorSetLayout();
	virtual void createDescriptorSets() = 0;
	virtual std::vector<VkDescriptorType> getDescriptorTypes() = 0;
	virtual std::vector<VkShaderStageFlagBits> getDescriptorStages() = 0;
	virtual PipelineAttributes getPipelineAttributes() = 0;
	std::vector<Chronos::Engine::UniformBuffer>
	    uniformBuffers; /**< uniform buffers associated with the object. */
    };
};
};
