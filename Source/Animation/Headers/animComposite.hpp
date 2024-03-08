#pragma once
namespace Chronos {
namespace Animation {

    /**
     \brief Class for animation composites.

     Animation composites are objects that contain multiple animation shapes.
    */
    class AnimComposite : public AnimObject {
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

        void addShape();
        void removeShape();
    };
}
}