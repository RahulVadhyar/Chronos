#pragma once

#include "polygon.hpp"
namespace Chronos{
    namespace Engine{
        class PolygonManager : public Chronos::Engine::ObjectManager<Chronos::Engine::Polygon>{
        public:    
            void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3])
        private:
            void createRenderPass();
        };      
    };
};