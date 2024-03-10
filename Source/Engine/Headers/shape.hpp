/** \file shape.hpp

 \brief Contains the class for creating a shape.
*/
#pragma once

#include "buffers.hpp"
struct Empty {
    Empty() = default;

};

namespace Chronos {
namespace Engine {

    template <typename T>
    concept VertexLike = std::is_base_of<Chronos::Engine::ColorVertex, T>::value || std::is_base_of<Chronos::Engine::TexturedVertex, T>::value;

    /**
    \brief Class for creating a shape(triangle, rectangle, etc.).

    This class is used to create a shape(triangle, rectangle, etc.). It is a child of the Object class.
    It handles all the vulkan objects needed for rendering the shape.
    */
    template <VertexLike VertexStruct>
    class Shape : public Object {

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
            VkRenderPass* renderPass) requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value);

        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler,
            std::array<float, 3> color,
            VkRenderPass* renderPass) requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value);

        /**
        \brief Updates the shape object for the current frame.

        This function is used to update the shape object for the current frame. It is called by the ```ObjectManager``` class.
        It does this by updating the uniform buffer.

        @param currentFrame The current frame number to render to.
        */
        void update(uint32_t currentFrame) override{
            tempUpdate(currentFrame);
        }

        void tempUpdate(uint32_t currentFrame) requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value);
        void tempUpdate(uint32_t currentFrame) requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value);

        /**
        \brief Destroys the shape object and frees the memory.

        This destroys all the vulkan related objects related to this class and frees memory.
        */
        void destroy() override {
            return tempDestroy();
        
        };
        void tempDestroy() requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value);
        void tempDestroy() requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value);


        /**
        \brief The indices that is used to specify the order of vertices to render.
        */
        std::vector<uint16_t> indices;

        /**
        \brief The texture that is to be used
        */
        [[no_unique_address]] std::conditional_t<std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value, Chronos::Engine::Texture, Empty> texture ;

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

        void createDescriptorSets() override {
            return tempCreateDescriptorSets();
        };
        std::vector<VkDescriptorType> getDescriptorTypes() override {
            return tempGetDescriptorTypes();
        };
        std::vector<VkShaderStageFlagBits> getDescriptorStages() override {
            return tempGetDescriptorStages();
        };
        void tempCreateDescriptorSets() requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value);
        std::vector<VkDescriptorType> tempGetDescriptorTypes() requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value);
        std::vector<VkShaderStageFlagBits> tempGetDescriptorStages() requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value);

        void tempCreateDescriptorSets() requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value);
        std::vector<VkDescriptorType> tempGetDescriptorTypes() requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value);
        std::vector<VkShaderStageFlagBits> tempGetDescriptorStages() requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value);
        std::vector<VkShaderStageFlagBits> getShaderStages();

    private:
        [[no_unique_address]] std::conditional_t<std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value, std::vector<Chronos::Engine::ColorBuffer>, Empty> colorBuffers;
        PipelineAttributes getPipelineAttributes() override;
    };
#include "shapeDefs.tpp"

    /**
    \brief Class for creating a rectangle.

    This class is used to create a rectangle. It is a child of the Shape class.
    For more details about the functions, see the Shape class.
    */
    template <VertexLike VertexStruct>
    class Rectangle : public Shape<VertexStruct> {
    public:
        Rectangle()
            requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
        {
            Rectangle<VertexStruct>::indices = std::vector<uint16_t> { 0, 1, 2, 2, 3, 0 };
            Rectangle<VertexStruct>::vertices = std::vector<VertexStruct> { { { -0.5f, -0.5f }},
                { { 0.5f, -0.5f }},
                { { 0.5f, 0.5f }},
                { { -0.5f, 0.5f }} };
        }

        Rectangle()
            requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
        {
            Rectangle<VertexStruct>::indices = std::vector<uint16_t> { 0, 1, 2, 2, 3, 0 };
            Rectangle<VertexStruct>::vertices = std::vector<VertexStruct> { { { -0.5f, -0.5f }, { 1.0f, 0.0f } },
                { { 0.5f, -0.5f }, { 0.0f, 0.0f } },
                { { 0.5f, 0.5f }, { 0.0f, 1.0f } },
                { { -0.5f, 0.5f }, { 1.0f, 1.0f } } };
        }
    };

    /**
    \brief Class for creating a triangle.

    This class is used to create a triangle. It is a child of the Shape class.
    For more details about the functions, see the Shape class.
    */
    template <VertexLike VertexStruct>
    class Triangle : public Shape<VertexStruct> {
    public:
        Triangle()
            requires(std::is_same<Chronos::Engine::TexturedVertex, VertexStruct>::value)
        {
            Triangle<VertexStruct>::indices = std::vector<uint16_t> { 0, 1, 2 };
            Triangle<VertexStruct>::vertices = std::vector<VertexStruct> { { { 0.0f, -0.5f }, { 1.0f, 0.0f } },
                { { 0.5f, 0.5f }, { 0.0f, 0.0f } },
                { { -0.5f, 0.5f }, { 0.0f, 1.0f } } };
        }

        Triangle()
            requires(std::is_same<Chronos::Engine::ColorVertex, VertexStruct>::value)
        {
            Triangle<VertexStruct>::indices = std::vector<uint16_t> { 0, 1, 2 };
            Triangle<VertexStruct>::vertices = std::vector<VertexStruct> { { { 0.0f, -0.5f }},
                { { 0.5f, 0.5f }},
                { { -0.5f, 0.5f }} };
        }
    };
};
};