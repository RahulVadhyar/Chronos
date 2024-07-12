/*
Copyright (c) 2024 Rahul Satish Vadhyar

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/**
\file textManager.hpp

\brief Contains the class for managing text in the Chronos::Engine namespace.
*/

namespace Chronos {
namespace Engine {

    /**
    \brief This is the text manager for Chronos. It handles creation,
    modification, updating and desrtuction of text.
    */
    class TextManager
	: public Chronos::Engine::ObjectManager<Chronos::Engine::Text> {
    public:
	/**
	\brief Adds a font to the text manager.

	@param font The font to add.
	@param fontStyle The style of the font to add.
	@return The index of the font that was added.
	*/
	int addFont(
	    Chronos::Engine::Text font, Chronos::Engine::FontTypes fontStyle);

	/**
	\brief Records the commands needed for rendering the text.

	When this function is called, it records the commands that are needed
	for rendering all the text stored in this class.

	@param currentFrame The current frame to render to.
	@param imageIndex The index of the framebuffer associated with the
	current frame
	@param bgColor The background color to use for rendering the background.
	*/
	void render(
	    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

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
