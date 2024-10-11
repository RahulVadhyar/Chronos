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

/** \file TexturedRectangle.hpp

 \brief Contains the class for creating a rectangle filled with texture.
*/
#pragma once
#include "object.hpp"
#include "texture.hpp"
#include "Vertex.hpp"
#include "commonStructs.hpp"
namespace Chronos {
namespace Engine {
    class TexturedRectangle : public Object {
    public:
	void init(Chronos::Engine::Device* device, VkCommandPool commandPool,
	    Chronos::Engine::SwapChain* swapChain, VkSampler textureSampler,
	    Chronos::Engine::Texture texture, VkRenderPass* renderPass);
	void update(uint32_t currentFrame) override;
	void destroy() override;
	const std::vector<uint16_t> indices = std::vector<uint16_t> { 0, 1, 2, 2, 3, 0 };

	const std::vector<TexturedVertex> vertices
	    = std::vector<TexturedVertex> {
		{ { -0.5f, -0.5f }, { 1.0f, 0.0f } },
		{ { 0.5f, -0.5f }, { 0.0f, 0.0f } },
		{ { 0.5f, 0.5f }, { 0.0f, 1.0f } },
		{ { -0.5f, 0.5f }, { 1.0f, 1.0f } }
	    };

	Chronos::Engine::Texture texture;
	Chronos::Manager::ShapeParams params;
	/**
    \brief The vertex buffer that is used to store the vertices.
    */
	Chronos::Engine::Buffer vertexBuffer;
	void render(
	    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]) override;

	    /**
	    \brief The index buffer that is used to store the indices.
	    */
	    Chronos::Engine::Buffer indexBuffer;

    private:
	void createDescriptorSets() override;
	std::vector<VkDescriptorType> getDescriptorTypes() override;
	std::vector<VkShaderStageFlagBits> getDescriptorStages() override;
	PipelineAttributes getPipelineAttributes() override;
    };
};
};