#pragma once
#include "Vertex.hpp"
namespace Chronos{
    namespace Engine{
        class Polygon : public Chronos::Engine::Shape<TexturedVertex>{
        public:
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain,
            VkSampler textureSampler, Chronos::Engine::Texture texture,
            VkRenderPass* renderPass, std::vector<std::array<float, 2>> vertices);
        };      
    };
};