#pragma once
#include "animObject.hpp"
#include "structs.hpp"
#include "stlheader.hpp"
namespace Chronos {
namespace Animation {
    /**
    \brief Class for animation shapes.

    Animation shapes are shapes that can be animated/
    */
    class AnimShape : public AnimObject{
    public:
    void init();
    void update();
    void destroy();
    void loadFromFile();
    void saveToFile();
    void nextFrame();
    void prevFrame();
    void setFrame();
    void createFrame();
    void changeAnimation();
    
    private:
    std::vector<Chronos::Engine::ShapeParams> animFrames;
    
    };
}
}