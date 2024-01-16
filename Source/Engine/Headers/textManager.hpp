#include "ObjectManager.hpp"
#include "text.hpp"

namespace Chronos {
namespace Engine{
    enum TextAlignment { Left,
        Center,
        Right };
    class TextManager: public Chronos::Engine::ObjectManager<Chronos::Engine::Font> {
    public:
        int addFont(Chronos::Engine::Font font);
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);
        void remove(int fontNo);

    };
};
};