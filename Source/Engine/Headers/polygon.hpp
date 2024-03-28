#pragma once
#include "Vertex.hpp"
namespace Chronos{
    namespace Engine{
        class Polygon : public Chronos::Engine::Shape<TexturedVertex>{
        public:
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, Chronos::Engine::Texture texture,
            VkRenderPass* renderPass, std::vector<std::array<float, 2>> vertices);
        
        void destroy() override;
        void updateVertices(std::vector<std::array<float, 2>>vertices);
        private:
        void* mappedMemory = nullptr;
        void copyVerticestoBuffer();
        };      
    };
};