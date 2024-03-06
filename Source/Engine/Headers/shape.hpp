/** \file shape.hpp

 \brief Contains the class for creating a shape.
*/
#pragma once
#include "engineStructs.hpp"
#include "helper.hpp"
#include "Vertex.hpp"
#include "buffers.hpp"
#include "texture.hpp"
#include "object.hpp"
#include "commonStructs.hpp"
namespace Chronos {
namespace Engine {
    /**
    \brief Class for creating a shape(triangle, rectangle, etc.).

    This class is used to create a shape(triangle, rectangle, etc.). It is a child of the Object class.
    It handles all the vulkan objects needed for rendering the shape.
    */
    class Shape : public Object{

    public:

        /**
        \brief The parameters that are associated with the shape.
        */
        Chronos::Manager::ShapeParams params;

        /**
        \brief Initializes the shape object and creates the necessary objects.

        Used to create the shape object and create the necessary vulkan objects for rendering the shape.

        @param device The device to use for creating the objects.
        @param commandPool The command pool to create the command buffer on
        @param swapChain The swapchain that is used
        @param textureSampler The texture sampler to use
        @param texturePath The path to the texture(png and jpg supported)
        */
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, std::string texturePath,
            VkRenderPass* renderPass);


        /**
        \brief Updates the shape object for the current frame.

        This function is used to update the shape object for the current frame. It is called by the ```ObjectManager``` class.
        It does this by updating the uniform buffer.

        @param currentFrame The current frame number to render to.
        */
        void update(uint32_t currentFrame) override;

        /**
        \brief Destroys the shape object and frees the memory.

        This destroys all the vulkan related objects related to this class and frees memory.
        */
        void destroy() override;
        
        /**
        \brief The indices that is used to specify the order of vertices to render.
        */
        std::vector<uint16_t> indices;

        /**
        \brief The texture that is to be used
        */
        Chronos::Engine::Texture texture;

        /**
        \brief The vertices that is used to render the shape.
        */
        std::vector<Vertex> vertices;

        /**
        \brief The vertex buffer that is used to store the vertices.
        */
        Chronos::Engine::Buffer vertexBuffer;

        /**
        \brief The index buffer that is used to store the indices.
        */
        Chronos::Engine::Buffer indexBuffer;
        
        void createDescriptorSets() override;
        std::vector<VkDescriptorType> getDescriptorTypes() override;
        std::vector<VkShaderStageFlagBits> getDescriptorStages() override;
        std::vector<VkShaderStageFlagBits> getShaderStages();
    private:
        PipelineAttributes getPipelineAttributes() override;
        
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