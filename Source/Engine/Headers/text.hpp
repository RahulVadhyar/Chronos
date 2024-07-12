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

/** \file font.hpp

 \brief Contains the class for creating a font object for rendering text along
 with the FontTypes struct.
*/
#pragma once
#ifndef WIN32
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-function"
#ifdef __clang__
#pragma clang diagnostic ignored "-Weverything"
#endif
#endif
#include "stb_font_consolas_24_latin1.inl"
#ifndef WIN32
#pragma GCC diagnostic pop
#endif
namespace Chronos {
namespace Engine {

    /**
    \brief The parameters needed for the font style

    This structure contains the parameters needed for the font style.

    @param fontWidth The width of the font texture
    @param fontHeight The height of the font texture
    @param getFontData The function to get the font data
    @param firstChar The first character in the texture
    @param numChars The number of characters in the texture
    */
    struct FontTypes {
	uint32_t fontWidth;
	uint32_t fontHeight;
	void (*getFontData)(stb_fontchar*, unsigned char[][256], int);
	uint32_t firstChar;
	int numChars;
    };

    /**
    \brief Class for creating a text object for rendering text.

    We can choose from a lot of fonts and sizes. There are many available.

    For rendering text in vulkan, we need a bunch of setup and objects. It is
    also a very complex process. This class handles this process and abstracts
    this complex process into a simple class with simple methods that can be
    used for rendering text.

    The way the test is rendered is by creating a texture atlas. This is a
    texture that contains all the characters in the font. This texture is then
    used to render the text. The text is rendered by creating a rectangle for
    each character and then rendering it.

    This class is not meant to be directly used, but instead to be used by the
    ```FontManager``` class. That will handle the creation and destruction of
    the font object, along with any updates needed.
    */

    class Text : public Chronos::Engine::Object {
    public:
	/**
	\brief Initializes the font object and creates the necessary objects.

	@param device The device to use for creating the objects.
	@param commandPool The command pool to use for rendering
	@param swapChain The swapchain to use for rendering
	@param textureSampler The texture sampler to use for fonts
	@param renderPass The renderpass to use for rendering
	@param fontStyle The font style to use for rendering

	*/
	void init(Chronos::Engine::Device* device, VkCommandPool commandPool,
	    Chronos::Engine::SwapChain* swapChain, VkSampler textureSampler,
	    VkRenderPass* renderPass, Chronos::Engine::FontTypes fontStyle);

	/**
	\brief Destroys the font object and frees the memory.

	This destroys all the vulkan related objects related to this class and
	frees memory.
	*/
	void destroy();

	/**
	\brief Clears the text stored in the font object.

	Used for resetting the text stored in the font object.
	*/
	void clear();

	/**
	\brief Records the commands needed for rendering the text .

	When this function is called, it records the commands that are needed
	for rendering the text stored in this class.

	@param currentFrame The current frame number to render to.
	@param imageIndex The index of the framebuffer associated with the
	current frame
	@param bgColor The background color to use for rendering the text.
	*/
	void render(
	    uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

	/**
	\brief Updates the attributes(like position, color, etc) of the text.

	This function is used to update the attributes of the text. It is called
	by the ```FontManager``` class. It does this by updating the uniform
	buffer.
	*/
	void update(uint32_t currentFrame);

	/**
	\brief The vertices of each character used for rendering
	*/
	VkBuffer vertexBuffer;

	/**
	\brief The total number of letters to render
	*/
	uint32_t numLetters;

	/**
	\brief Various parameters of the text that are set by the user.
	*/
	Chronos::Engine::TextParams params;

    private:
	stb_fontchar stbFontData[STB_FONT_consolas_24_latin1_NUM_CHARS];
	/**
	\brief Maximum number of characters that can be rendered.
	*/
	uint32_t maxTextLength = 2048;
	/**
	\brief The vertex buffer memory.
	*/
	VkDeviceMemory vertexBufferMemory;
	/**
	The font texture
	*/
	Chronos::Engine::Texture fontTexture;

	std::vector<Chronos::Engine::ColorBuffer> colorBuffers;

	uint32_t firstChar = 'a';

	FontTypes fontStyle;

	/**
	\brief Creates the descriptor sets needed for rendering the text.

	This function is used to create the descriptor sets needed for rendering
	the text. The descriptor sets contain information about the texture
	sampler and the uniform buffer.
	*/
	void createDescriptorSets();

	/**
	\brief Gets the descriptor types needed for rendering the text.
	*/
	std::vector<VkDescriptorType> getDescriptorTypes();

	/**
	\brief Gets the descriptor stages in which the descriptor sets are used.
	*/
	std::vector<VkShaderStageFlagBits> getDescriptorStages();

	/**
	\brief Returns the pipeline attributes that are set for the graphics
	pipeline.
	*/
	PipelineAttributes getPipelineAttributes();

	/**
	\brief Updates the buffer with the new text.
	*/
	void updateBuffer();

	/**
	The mapped memory to the vertex buffer
	*/
	glm::vec4* mappedMemory;
    };

};
};
