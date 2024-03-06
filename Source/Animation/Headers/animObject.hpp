#pragma once

namespace Chronos {
namespace Animation {

    /**
     \brief Abstract class for animation objects.
 
    It contains the basic functions and variables needed for animation objects.
    */
    class AnimObject{
    public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void destroy() = 0;
    virtual void loadFromFile() = 0;
    virtual void saveToFile() = 0;
    virtual void nextFrame() = 0;
    virtual void prevFrame() = 0;
    virtual void setFrame() = 0;
    virtual void createFrame() = 0;
    virtual void changeAnimation() = 0;
    };
}
}