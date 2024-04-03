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
/**
\file polygon.hpp
\brief Header file for Polygon class

This file contains all the declarations of the Polygon class
*/
namespace Chronos{
    namespace Engine{
        /**
        \brief A class to represent a polygon object

        A polygon object is a shape that can have any number of vertices and can be textured
        These vertices can also be updated on the fly after creation. This is done by creating a vertex buffer and copying the vertices to it
        The indices are generated using the earcut library. This library takes a list of vertices and generates a list of indices that represent the triangles that make up the polygon
        It uses a polygon triagulation algorithm to do this. 
        Since the vertices can be updated any time, we have to create multiple vertex buffers and update them as the frames are being updated.
        */
        class Polygon : public Chronos::Engine::Object{
        public:

        /**
        \brief Basic properties of the polygon
        */
        Chronos::Manager::ShapeParams params;

        /**
        
        \brief Initializes the polygon object

        This function initializes the polygon object. It creates the vertex buffer, index buffer and descriptor sets for the object
        It also calculates the indices using the earcut library.
        */
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, Chronos::Engine::Texture texture,
            VkRenderPass* renderPass, std::vector<std::array<float, 2>> vertices);
        
        /**
        \brief Updates the vertices of the polygon

        This function updates the vertices of the polygon. It copies the vertices to the vertex stroage buffer and sets the copyVertices flag to true for all buffers
        */
        void updateVertices(std::vector<std::array<float, 2>>vertices);

        /**
        \brief Updates the polygon object

        Same as other objects. One thing to note is that the vertices are copied to the vertex buffer if the copyVertices flag is set to true
        */
        void update(uint32_t currentFrame) override;

        /**
        \brief Destroys the polygon object

        This function destroys the polygon object. It frees the memory allocated for the vertex buffer, index buffer and descriptor sets
        */
        void destroy() override;

        std::vector<uint16_t> indices;
        Chronos::Engine::Texture texture;
        std::vector<TexturedVertex> vertices;
        std::vector<Chronos::Engine::Buffer> polygonVertexBuffers;
        Chronos::Engine::Buffer indexBuffer;

        void createDescriptorSets() override;
        std::vector<VkDescriptorType> getDescriptorTypes() override;
        std::vector<VkShaderStageFlagBits> getDescriptorStages() override;
        PipelineAttributes getPipelineAttributes() override;
        private:
        void* mappedMemory = nullptr;

        /**
        \brief Copies the current vertices in the vertices vector to the vertex buffer given.
        */
        void copyVerticestoBuffer(Chronos::Engine::Buffer vertexBuffer);

        /**
        \brief Flags to know if the vertex buffer is to be updated.
        */
        std::vector<bool> copyVertices;
        };      
    };
};