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
/** \file shapeManager.hpp

 \brief Contains the class for managing shapes.
*/
namespace Chronos {
namespace Engine {

    /**
    \brief This is the shape manager for Chronos. It handles creation,
    modification, updating and desrtuction of shapes.

    Since there can be two types of shapes, textured and colored, this class is
    templated. The template parameter is the type of vertex to use for the
    shapes. if the vertex type is TexturedVertex, then the shape will be
    textured. If the vertex type is ColorVertex, then the shape will be colored.

    Generally in order to manage shapes the methods to be used are:
    - ```addTriangle```
    - ```addRectangle```
    - ```remove``

    Inherits from Object Manager. All the public methods defined in that class
    is also available. It includes the following functions for internal use
    -init
    -destroy
    -update
    -render
    -changeMsaa
    -recreate

    For more details on these functions, please reference the
    [ObjectManger](Chronos::Engine::ObjectManager) class

    */
    template <VertexLike VertexStruct>
    class ShapeManager : public Chronos::Engine::ObjectManager<
			     Chronos::Engine::Shape<VertexStruct>> {
    public:
	/**
	\brief Adds a textured triangle to the shape manager.

	Necessary shapeParams and texture path must be provided.
	Supported textures are .jpg and .png
	Returns a shapeNo that references the shape for modifying and destroying
	t.

	@param shapeParams The parameters needed for the shape
	@param texture The texture to use for the shape
	@return The shape number of the shape that was added
	*/
	int addTriangle(Chronos::Manager::ShapeParams shapeParams,
	    Chronos::Engine::Texture texture)
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);

	/**
	\brief Adds a colored triangle to the shape manager.

	Necessary shapeParams must be provided.
	Returns a shapeNo that references the shape for modifying and destroying
	t.

	@param shapeParams The parameters needed for the shape
	@return The shape number of the shape that was added
	*/
	int addTriangle(Chronos::Manager::ShapeParams shapeParams)
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;

	/**
	\brief Adds a textured rectangle to the shape manager.

	Necessary shapeParams and texture path must be provided.
	Supported textures are .jpg and .png
	Returns a shapeNo that references the shape for modifying and destroying
	t.

	@param shapeParams The parameters needed for the shape
	@param texture The texture to use for the shape
	*/
	int addRectangle(Chronos::Manager::ShapeParams shapeParams,
	    Chronos::Engine::Texture texture)
	    requires(std::is_same<Chronos::Engine::TexturedVertex,
		VertexStruct>::value);

	/**
	\brief Adds a colored rectangle to the shape manager.

	Necessary shapeParams must be provided.
	Returns a shapeNo that references the shape for modifying and destroying
	t.

	@param shapeParams The parameters needed for the shape
	@return The shape number of the shape that was added
	*/
	int addRectangle(Chronos::Manager::ShapeParams shapeParams)
	    requires(
		std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
	;

	/**
	\brief Records the commands needed for rendering the shapes.

	When this function is called, it records the commands that are needed
	for rendering all the shapes stored in this class.

	@param currentFrame The current frame to render to.
	@param imageIndex The index of the framebuffer associated with the
	current frame
	@param bgColor The background color to set during rendering
	*/
	void render(
	    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

    private:
	/**
	\brief Creates the render pass for the shapes.

	This function is called by the ```init``` function. It creates the
	render pass for the shapes.
	*/
	void createRenderPass();
    };
#include "shapeManagerDefs.tpp"
};
};
