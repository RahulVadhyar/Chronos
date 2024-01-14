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
    struct Vertex {
        glm::vec2 pos;
        glm::vec3 color;
        glm::vec2 texCoord;

        /**
        \brief Creates a ```VkVertexInputBindingDescription``` for the vertex based on the size of the vertex.
        */
        static VkVertexInputBindingDescription getBindingDescription()
        {
            VkVertexInputBindingDescription bindingDescription {};
            bindingDescription.binding = 0;
            bindingDescription.stride = sizeof(Vertex);
            bindingDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

            return bindingDescription;
        }

        /**
        \brief Generates the ```VkVertexInputAttributeDescription``` for the vertex based on attributes(pos, color, texCoord) of the vertex.
        */
        static std::array<VkVertexInputAttributeDescription, 3>
        getAttributeDescriptions()
        {
            std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions {};

            attributeDescriptions[0].binding = 0;
            attributeDescriptions[0].location = 0;
            attributeDescriptions[0].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[0].offset = offsetof(Vertex, pos);

            attributeDescriptions[1].binding = 0;
            attributeDescriptions[1].location = 1;
            attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
            attributeDescriptions[1].offset = offsetof(Vertex, color);

            attributeDescriptions[2].binding = 0;
            attributeDescriptions[2].location = 2;
            attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
            attributeDescriptions[2].offset = offsetof(Vertex, texCoord);

            return attributeDescriptions;
        }
    };
};
};