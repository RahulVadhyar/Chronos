/** \file shape.hpp

 \brief Contains the class for creating a shape.
*/
#pragma once
#include "structs.hpp"
#include "helper.hpp"
#include "Vertex.hpp"
#include "buffers.hpp"
#include "texture.hpp"
#include "object.hpp"

namespace Chronos {
namespace Engine {

    class Shape : public Object{

    public:
        Chronos::Engine::ShapeParams params;
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, std::string texturePath,
            VkRenderPass* renderPass);

        void update(uint32_t currentFrame);

        void destroy();
        std::vector<uint16_t> indices;
        Chronos::Engine::Texture texture;
        std::vector<Vertex> vertices;
        Chronos::Engine::Buffer vertexBuffer;
        Chronos::Engine::Buffer indexBuffer;
        void createDescriptorSets();
    private:
        std::vector<Chronos::Engine::UniformBuffer> uniformBuffers;
    };

    /**
    \brief Class for creating a rectangle.

    This class is used to create a rectangle. It is a child of the Shape class.
    For more details about the functions, see the Shape class.
    */
    class Rectangle : public Shape {
    public:
        Rectangle()
        {
            indices = std::vector<uint16_t> { 0, 1, 2, 2, 3, 0 };
            vertices = std::vector<Vertex> { { { -0.5f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
                { { 0.5f, -0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
                { { 0.5f, 0.5f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } },
                { { -0.5f, 0.5f }, { 0.5f, 1.0f, 0.5f }, { 1.0f, 1.0f } } };
        }
    };

    /**
    \brief Class for creating a triangle.

    This class is used to create a triangle. It is a child of the Shape class.
    For more details about the functions, see the Shape class.
    */
    class Triangle : public Shape {
    public:
        Triangle()
        {
            indices = std::vector<uint16_t> { 0, 1, 2 };
            vertices = std::vector<Vertex> { { { 0.0f, -0.5f }, { 1.0f, 0.0f, 0.0f }, { 1.0f, 0.0f } },
                { { 0.5f, 0.5f }, { 0.0f, 1.0f, 0.0f }, { 0.0f, 0.0f } },
                { { -0.5f, 0.5f }, { 0.0f, 0.0f, 1.0f }, { 0.0f, 1.0f } } };
        }
    };
};
};