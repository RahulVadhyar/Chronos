/** \file Vertex.hpp

 \brief This file includes the structure of a vertex.

 This is used to create the vertices of a shape and define basic parameters(position, texture, color).
*/
#pragma once
namespace Chronos {
namespace Engine {

    /**
    \brief This defines the position, color(not used), and texture coordinates of a vertex.
    */
    struct ColorVertex {
        glm::vec2 pos;

        /**
        \brief Creates a ```VkVertexInputBindingDescription``` for the vertex based on the size of the vertex.
        */
        static VkVertexInputBindingDescription getBindingDescription()
        {
            VkVertexInputBindingDescription bindingDescription {};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(ColorVertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingDescription;
        }

        /**
        \brief Generates the ```VkVertexInputAttributeDescription``` for the vertex based on attributes(pos, color, texCoord) of the vertex.
        */
        static std::array<VkVertexInputAttributeDescription, 1>
        getAttributeDescriptions()
        {
            std::array<VkVertexInputAttributeDescription, 1> attributeDescriptions {};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(ColorVertex, pos);
            return attributeDescriptions;
        }
    };

    struct TexturedVertex {
        glm::vec2 pos;
        glm::vec2 texCoord;

        /**
        \brief Creates a ```VkVertexInputBindingDescription``` for the vertex based on the size of the vertex.
        */
        static VkVertexInputBindingDescription getBindingDescription()
        {
            VkVertexInputBindingDescription bindingDescription {};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(TexturedVertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingDescription;
        }

        /**
        \brief Generates the ```VkVertexInputAttributeDescription``` for the vertex based on attributes(pos, color, texCoord) of the vertex.
        */
        static std::array<VkVertexInputAttributeDescription, 2>
        getAttributeDescriptions()
        {
            std::array<VkVertexInputAttributeDescription, 2> attributeDescriptions {};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(TexturedVertex, pos);

            attributeDescriptions[1].binding = 0;
            attributeDescriptions[1].location = 1;
            attributeDescriptions[1].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[1].offset = offsetof(TexturedVertex, texCoord);

            return attributeDescriptions;
        }
    };
};
};