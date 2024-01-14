/** \file shape.hpp

 \brief Contains the class for creating a shape.
*/
#pragma once
#include "structs.hpp"
#include "helper.hpp"
#include "Vertex.hpp"
#include "buffers.hpp"
#include "texture.hpp"

namespace Chronos {
namespace Engine {

    /**
    \brief Class for creating a generic shape.

    Triangle and Rectangle classes are derived from this class.
    To modify the shape, modify the shapeParams variable. The changes will be propogated to the shader on the next frame.

    For a shape to be rendered we need the following:
    - A vertex buffer
    - An index buffer
    - A texture(optional)
    - A graphics pipeline
    - A descriptor set layout
    - A descriptor pool
    - A descriptor set
    - A pipeline layout

    These objects are created and managed by this function.
    It also handles updating of variables(uniforms) in the shader based on the shapeParams.
    Recreating of graphics pipeline when MSAA is updated is also handled by this class.
    */
    class Shape {

    public:
        /**
        \brief Parameters of the shape. Can be updated at any time.

        The parameters contain the attributes for rendering the shape.
        It can be also be updated at any time. The changes will be propogated to the shader on call of update().
        */
        Chronos::Engine::ShapeParams params;

        /**
        \brief Initializes the shape.

        Initializes the shape by creating the vertex buffer, index buffer, texture, graphics pipeline, descriptor set layout, descriptor pool, descriptor set and pipeline layout.

        @param device The device to create the shape on.
        @param commandPool The command pool to record the commands to render the shape.
        @param swapChain The swapchain to create the command buffers on.
        @param textureSampler The sampler to use for the texture.
        @param texturePath The path to the texture.
        @param renderPass The render pass to use for the shape.
        */
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, std::string texturePath,
            VkRenderPass* renderPass);

        /**
        \brief Updates the shape.

        Every frame, this function is called. It updates the attributes of the uniform buffer based on the updated shapeParams
        and records the commands to render the shape.

        @param currentFrame The frame to be rendered to.
        */
        void update(uint32_t currentFrame);

        /**
        \brief Destroys the shape along with its associated objects.

        When an shape is no longer needed, cleanup of its objects must be done. Hence when a shape is not needed anymore, this function must be called.
        */
        void destroy();

        /**
        \brief Recreates the graphics pipeline.

        When MSAA is updated, the graphics pipeline must be recreated. This function handles that.
        */
        void recreateGraphicsPipeline();

        /**
        \brief The indices of the shape.

        When we create an shape with more than 3 vertices, we need to specify in which order to create the triangles(all shapes are made of triangles).
        This is done by specifying the indices of the vertices in the order in which they must be connected.
        Using this we can also save memory as we don't need to specify the same vertex multiple times.

        Indicies are defined by the child classes(Triangle and Rectangle).
        */
        std::vector<uint16_t> indices;

        /**
        \brief The vertices of the shape.

        We need to give coordinates for each vertex. We also need to specify the color and texture coordinates of the vertices.
        The Vertex class contains these attributes.

        Note that the coordinates of the vertex are not final. When shader recieves uniforms, it will modify these coordinates.
        These are mainly for base size and position of the shape.

        Vertices are defined by the child classes(Triangle and Rectangle).
        */
        std::vector<Vertex> vertices;

        /**
        \brief The graphics pipeline used to render the shape.

        For any shape to be rendered, we need a graphics pipeline. It contains all the information and steos needed to render the shape.
        It must be created for every shape.
        */
        VkPipeline graphicsPipeline;

        /**
        \brief The buffer on the GPU containing the vertices of the shape.
        */
        Chronos::Engine::Buffer vertexBuffer;

        /**
        \brief The buffer on the GPU containing the indices of the shape.
        */
        Chronos::Engine::Buffer indexBuffer;

        /**
        \brief The pipeline layout of the shape.

        Pipeline layout is needed to create the graphics pipeline. It contains the information about the uniform buffers and the descriptor sets.
        */
        VkPipelineLayout pipelineLayout;

        /**
        \brief The descriptor sets of the shape.

        Descriptor sets are needed to update the uniforms in the shader. They are also needed to bind the texture to the shader.
        */
        std::vector<VkDescriptorSet> descriptorSets;

    private:
        /**
        \brief The path to the vertex SPIV-V shader file.
        */
        const char* vertexShaderPath = "ThirdParty/Chronos/Shaders/vert.spv";

        /**
        \brief The path to the fragment SPIV-V shader file.
        */
        const char* fragmentShaderPath = "ThirdParty/Chronos/Shaders/frag.spv";

        /**
        \brief The device to create and render the shape on.
        */
        Chronos::Engine::Device* device;

        /**
        \brief The swapchain to create the command buffers on.
        */
        Chronos::Engine::SwapChain* swapChain;

        /**
        \brief The texture of the shape.
        */
        Chronos::Engine::Texture texture;

        /**
        The uniform buffers describe the attributes of the shape. They are used to update the uniforms in the shader.
        They are calculated from the shapeParams struct
        */
        std::vector<Chronos::Engine::UniformBuffer> uniformBuffers;

        /**
        \brief The command pool to record the commands to render the shape.
        */

        VkCommandPool commandPool;

        /**
        \brief The sampler to use for the texture.
        */
        VkSampler textureSampler;

        /**
        \brief The render pass to use for the shape.
        */
        VkRenderPass* renderPass;
        VkDescriptorSetLayout descriptorSetLayout;
        VkDescriptorPool descriptorPool;

        /**
        \brief Creates the graphics pipeline for this shape.

        As we can see below, creating the graphics pipeline is a very long process. Hence it is better to have a function for it.
        This function sets all the parameters and stages for the graphics pipeline and creates it.
        For now only vertex and fragment shaders are used. In future, mesh shaders will be used instead of vertex shaders.
        */
        void createGraphicsPipeline();

        /**
        \brief Creates the descriptor pool for this shape.
        */
        void createDescriptorPool();

        /**
        \brief Creates the descriptor set layout for this shape.
        */
        void createDescriptorSetLayout();

        /**
        \brief Creates the descriptor sets for this shape.
        */
        void createDescriptorSets();
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