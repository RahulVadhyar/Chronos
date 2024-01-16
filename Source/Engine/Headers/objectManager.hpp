#pragma once
#include "shape.hpp"

/** \file shapeManager.hpp

 \brief Contains the class for managing shapes.
*/


namespace Chronos {
namespace Engine {
    template <class T>
    concept ObjectLike = std::is_base_of<Chronos::Engine::Object, T>::value;


    template <ObjectLike Object>
    class ObjectManager {
    public:
        int nextFreeObjectNo = 0;
        std::map<int, Object> objects;
        std::vector<VkCommandBuffer> commandBuffers;

        void remove(int objectNo);
        void init(Chronos::Engine::Device* device, Chronos::Engine::SwapChain* swapChain, VkCommandPool commandPool);
        void destroy();
        void update(uint32_t currentFrame);
        virtual void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
        void changeMsaa();
        void recreate();

    protected:
        void endRender(uint32_t currentFrame);
        int addObject(Object object);
        virtual void createRenderPass() = 0;
        void cleanup();
        Chronos::Engine::Device* device;
        Chronos::Engine::SwapChain* swapChain;
        VkCommandPool commandPool;
        VkRenderPass renderPass;
        VkSampler textureSampler;
        std::vector<VkFramebuffer> framebuffers;
    };
};
};