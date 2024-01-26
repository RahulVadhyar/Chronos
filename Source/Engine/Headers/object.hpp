/** \file object.hpp

 \brief Contains the class for creating a generic object.
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
    
    */
    struct PipelineAttributes{
        std::vector<VkVertexInputBindingDescription> bindingDescriptions;
        std::vector<VkVertexInputAttributeDescription> attributeDescriptions;
        VkPrimitiveTopology topology;
        VkFrontFace frontFace;
        VkPipelineColorBlendAttachmentState colorBlendAttachment;
    };
    class Object {

    public:
        virtual void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain, 
        VkSampler textureSampler, VkRenderPass* renderPass);
        virtual void update(uint32_t currentFrame) = 0;
        virtual void destroy() = 0;
        void recreateGraphicsPipeline();
        VkPipeline graphicsPipeline;
        VkPipelineLayout pipelineLayout;
        std::vector<VkDescriptorSet> descriptorSets;

    protected:
        std::string vertexShaderPath;
        std::string fragmentShaderPath;
        Chronos::Engine::Device* device;
        Chronos::Engine::SwapChain* swapChain;
        VkCommandPool commandPool;
        VkSampler textureSampler;
        VkRenderPass* renderPass;
        VkDescriptorSetLayout descriptorSetLayout;
        VkDescriptorPool descriptorPool;
        void createGraphicsPipeline();
        void createDescriptorPool();
        void createDescriptorSetLayout();
        virtual void createDescriptorSets() = 0;
        virtual std::vector<VkDescriptorType> getDescriptorTypes() = 0;
        virtual std::vector<VkShaderStageFlagBits> getDescriptorStages() = 0;
        virtual PipelineAttributes getPipelineAttributes() = 0;
        std::vector<Chronos::Engine::UniformBuffer> uniformBuffers;
    };
};
};