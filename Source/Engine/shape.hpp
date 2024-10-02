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

/** \file shape.hpp

 \brief Contains the class for creating a shape.
*/
#pragma once

// empty struct for conditional
struct Empty {
    Empty() = default;
};

namespace Chronos {
namespace Engine {

    /**
    \brief Concept that checks if the given type is a class inheriting from the
    ColorVertex or TexturedVertex class.

    A vertex struct is different depending on whether it is a color vertex or a
    textured vertex. This concept checks if the given type is a class inheriting
    from the ColorVertex or TexturedVertex class. It is used by the shape class
    to render a colored vertex or a textured vertex.

    \tparam T The type to check for the VertexLike concept.
    */
    template <typename T>
    concept VertexLike = std::is_base_of<Chronos::Engine::ColorVertex, T>::value
	|| std::is_base_of<Chronos::Engine::TexturedVertex, T>::value;

    /**
    \brief Class for creating a shape(triangle, rectangle, etc.).

    This class is used to create a textured or colored shape(triangle,
    rectangle, etc.). It is a child of the Object class. It handles all the
    vulkan objects needed for rendering the shape.

    \tparam VertexStruct The type of vertex to use for rendering the shape. It
    can be a colored vertex or a textured vertex. This determines whether the
    shape is colored or textured.
    */
    template <VertexLike VertexStruct> class Shape : public Object {

    public:
	/**
	\brief The parameters that are associated with the shape.
	*/
	Chronos::Manager::ShapeParams params;

	/**
	\brief Initializes a textured shape object and creates the necessary
	objects.

	Used to create the shape object and create the necessary vulkan objects
	for rendering the shape. This function is only used when the vertex
	struct is a textured vertex.

	@param device The device to use for creating the objects.
	@param commandPool The command pool to create the command buffer on
	@param swapChain The swapchain that is used
	@param textureSampler The texture sampler to use for the shape
	@param texture The texture to use for the shape
	@param renderPass The renderpass to use for rendering

	*/
	void init(Chronos::Engine::Device* device, VkCommandPool commandPool,
	    Chronos::Engine::SwapChain* swapChain, VkSampler textureSampler,
	    Chronos::Engine::Texture texture, VkRenderPass* renderPass)
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);

	/**
	\brief Initializes a colored shape object and creates the necessary
	objects.

	Used to create the shape object and create the necessary vulkan objects
	for rendering the shape. This function is only used when the vertex
	struct is a colored vertex.

	@param device The device to use for creating the objects.
	@param commandPool The command pool to create the command buffer on
	@param swapChain The swapchain that is used
	@param renderPass The renderpass to use for rendering
	@param textureSampler The texture sampler to use for the shape
	*/
	void init(Chronos::Engine::Device* device, VkCommandPool commandPool,
	    Chronos::Engine::SwapChain* swapChain, VkRenderPass* renderPass,
	    VkSampler textureSampler)
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;

	/**
	\brief Updates the shape object for the current frame.

	This function is used to update the shape object for the current frame.
	It is called by the ```ObjectManager``` class. It does this by updating
	the uniform buffer.

	Note the actual logic is in tempUpdate(), this is because the logic
	differs depends on whether Shape is a colored object or a textured
	object. We cannot have specialized template fucntions for a overriden
	function, hence we have to have a wrapper function that calls the
	specialized function.

	@param currentFrame The current frame number to render to.
	*/
	void update(uint32_t currentFrame) override
	{
	    tempUpdate(currentFrame);
	}

	/**
	\brief Implements the update function for a textured shape object.

	See update function for more details.
	*/
	void tempUpdate(uint32_t currentFrame)
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);

	/**
	\brief Implements the update function for a colored shape object.

	See update function for more details.
	*/
	void tempUpdate(uint32_t currentFrame)
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;

	/**
	\brief Destroys the shape object and frees the memory.

	This destroys all the vulkan related objects related to this class and
	frees memory.

	Since the logic for destroying the objects is different for a colored
	object and a textured object, we have to have a wrapper function that
	calls the specialized function. We cannot have specialized template
	functions for a overriden function, hence we have to have a wrapper
	function that calls the specialized function.
	*/
	void destroy() override { return tempDestroy(); }

	/**
	\brief Destroys the shape object and frees the memory for a textured
	object.

	See destroy function for more details.
	*/
	void tempDestroy()
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);

	/**
	\brief Destroys the shape object and frees the memory for a colored
	object.

	See destroy function for more details.
	*/
	void tempDestroy()
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;

	/**
	\brief The indices that is used to specify the order of vertices to
	render.
	*/
	std::vector<uint16_t> indices;

	/**
	\brief The texture that is to be used

	This is only used when we have textured shaoe. Else this does not exist
	when using colored shape. It is an empty struct instead
	*/
	[[no_unique_address]] std::conditional_t<
	    std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value,
	    Chronos::Engine::Texture, Empty> texture;

	/**
	\brief The vertices that is used to render the shape.
	*/
	std::vector<VertexStruct> vertices;

	/**
	\brief The vertex buffer that is used to store the vertices.
	*/
	Chronos::Engine::Buffer vertexBuffer;

	/**
	\brief The index buffer that is used to store the indices.
	*/
	Chronos::Engine::Buffer indexBuffer;

	void createDescriptorSets() override
	{
	    return tempCreateDescriptorSets();
	}
	std::vector<VkDescriptorType> getDescriptorTypes() override
	{
	    return tempGetDescriptorTypes();
	}
	std::vector<VkShaderStageFlagBits> getDescriptorStages() override
	{
	    return tempGetDescriptorStages();
	}
	void tempCreateDescriptorSets()
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);
	std::vector<VkDescriptorType> tempGetDescriptorTypes()
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);
	std::vector<VkShaderStageFlagBits> tempGetDescriptorStages()
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);

	void tempCreateDescriptorSets()
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;
	std::vector<VkDescriptorType> tempGetDescriptorTypes()
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;
	std::vector<VkShaderStageFlagBits> tempGetDescriptorStages()
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;
	std::vector<VkShaderStageFlagBits> getShaderStages();

    private:
	/**
	\brief The color buffers used to store the color information of the
	shape.

	This is only used when we have colored shape. Else this does not exist
	when using textured shape. It is an empty struct instead
	*/
	[[no_unique_address]] std::conditional_t<
	    std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value,
	    std::vector<Chronos::Engine::ColorBuffer>, Empty> colorBuffers;
	PipelineAttributes getPipelineAttributes() override;
    };
#include "shapeDefs.tpp"

    /**
    \brief Class for creating a rectangle.

    This class is used to create a rectangle. It is a child of the Shape class.
    For more details about the functions, see the Shape class.

    It can be a colored rectangle or a textured rectangle. The type of rectangle
    is determined by the type of vertex struct.

    \tparam VertexStruct The type of vertex to use for rendering the shape. It
    can be a colored vertex or a textured vertex. This determines whether the
    shape is colored or textured.
    */
    template <VertexLike VertexStruct>
    class Rectangle : public Shape<VertexStruct> {
    public:
	Rectangle()
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	{
	    Rectangle<VertexStruct>::indices
		= std::vector<uint16_t> { 0, 1, 2, 2, 3, 0 };
	    Rectangle<VertexStruct>::vertices
		= std::vector<VertexStruct> { { { -0.5f, -0.5f } },
		      { { 0.5f, -0.5f } }, { { 0.5f, 0.5f } },
		      { { -0.5f, 0.5f } } };
	}

	Rectangle()
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value)
	{
	    Rectangle<VertexStruct>::indices
		= std::vector<uint16_t> { 0, 1, 2, 2, 3, 0 };
	    Rectangle<VertexStruct>::vertices = std::vector<VertexStruct> {
		{ { -0.5f, -0.5f }, { 1.0f, 0.0f } },
		{ { 0.5f, -0.5f }, { 0.0f, 0.0f } },
		{ { 0.5f, 0.5f }, { 0.0f, 1.0f } },
		{ { -0.5f, 0.5f }, { 1.0f, 1.0f } }
	    };
	}
    };

    /**
    \brief Class for creating a triangle.

    This class is used to create a triangle. It is a child of the Shape class.
    For more details about the functions, see the Shape class.

    It can be a colored triangle or a textured triangle. The type of triangle is
    determined by the type of vertex struct.

    \tparam VertexStruct The type of vertex to use for rendering the shape. It
    can be a colored vertex or a textured vertex. This determines whether the
    shape is colored or textured.
    */
    template <VertexLike VertexStruct>
    class Triangle : public Shape<VertexStruct> {
    public:
	Triangle()
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value)
	{
	    Triangle<VertexStruct>::indices = std::vector<uint16_t> { 0, 1, 2 };
	    Triangle<VertexStruct>::vertices = std::vector<VertexStruct> {
		{ { 0.0f, -0.5f }, { 1.0f, 0.0f } },
		{ { 0.5f, 0.5f }, { 0.0f, 0.0f } },
		{ { -0.5f, 0.5f }, { 0.0f, 1.0f } }
	    };
	}

	Triangle()
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	{
	    Triangle<VertexStruct>::indices = std::vector<uint16_t> { 0, 1, 2 };
	    Triangle<VertexStruct>::vertices
		= std::vector<VertexStruct> { { { 0.0f, -0.5f } },
		      { { 0.5f, 0.5f } }, { { -0.5f, 0.5f } } };
	}
    };
};
};
