/**
\file textManager.hpp

\brief Contains the class for managing text in the Chronos::Engine namespace.
*/
#include "objectManager.hpp"
#include "font.hpp"

namespace Chronos {
namespace Engine{

    /**
    \brief This is the text manager for Chronos. It handles creation, modification, updating and desrtuction of text.
    */
    class TextManager: public Chronos::Engine::ObjectManager<Chronos::Engine::Font> {
    public:

        /**
        \brief Adds a font to the text manager.

        @param font The font to add.
        */
        int addFont(Chronos::Engine::Font font);

        /**
        \brief Records the commands needed for rendering the text.

        When this function is called, it records the commands that are needed for rendering all the text stored in this class.

        @param currentFrame The current frame to render to.
        @param imageIndex The index of the framebuffer associated with the current frame
        @param bgColor The background color to use for rendering the background.
        */
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

        /**
        \brief Removes a font from the text manager.

        @param fontNo The index of the font to remove.
        */
        void remove(int fontNo);

    private:

        /**
        \brief Creates the render pass needed for rendering the text.
        */
        void createRenderPass();

    };
};
};