#pragma once
namespace Chronos{
    namespace Engine{
        class Polygon : public Chronos::Engine::Object{
        public:
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, Chronos::Engine::Texture texture,
            VkRenderPass* renderPass)
       
        void update(uint32_t currentFrame) override;
        void destroy() override;
        std::vector<uint16_t> indices;

        Chronos::Engine::Texture texture;
        std::vector<VertexStruct> vertices;
        Chronos::Engine::Buffer vertexBuffer;
        Chronos::Engine::Buffer indexBuffer;

        void createDescriptorSets() override;
        std::vector<VkDescriptorType> getDescriptorTypes() override;
        std::vector<VkShaderStageFlagBits> getDescriptorStages() override;
        std::vector<VkShaderStageFlagBits> getShaderStages();

    private:
        PipelineAttributes getPipelineAttributes() override;
        };      
    };
};