/** \file text.hpp

 \brief Contains the class for rendering and managing text.
*/
#pragma once
#include "swapchain.hpp"
#include "texture.hpp"

#include "stb_font_consolas_24_latin1.inl"
namespace Chronos {
namespace Engine {
    enum TextAlignment { Left,
        Center,
        Right };

    /**
    \brief Class for rendering and managing text.

    This class is used to render text on the screen. It uses the stb fonts to render the text.
    It renderers in a similar way to shapes.

    ## To add text to the screen:
    During the main loop:

    - Call ```beginUpdate```
    - Call ```add``` for each text to be added.
    - Call ```endUpdate```

    ## Important:

     - When ```beginUpdate``` is called, the previous text in the buffer is erased. Hence it is important to readd all the text in the buffer regardless of whether it was previously stored or not.
     - The text is rendered in the order in which it is added. Hence the text added last will be rendered on top of the text added before it.
     - If text is not updated for a frame, then the previously added text will be rendered.
    */
    class Text {
    public:

        /**
        \brief Initializes the text Manager.

        Initializes the text Manager by creating the vertex buffer, index buffer, texture, graphics pipeline,
        descriptor set layout, descriptor pool, descriptor set and pipeline layout.

        @param device The device to create the text on.
        @param commandPool The command pool to record the commands to render the text.
        @param swapChain The swapchain to create the command buffers on.S
        */
        void init(Chronos::Engine::Device* device, VkCommandPool commandPool, Chronos::Engine::SwapChain* swapChain);

        /**
        \brief Destroy the Vulkan objects and variables created by this class.

        This is not done using a destructor(```~Text``) as the destruction of objects in Vulkan has to be in a specific order and will
        not be guaranteed if such methods are used. Hence explicit methods are used for destruction.
        */
        void destroy();

        /**
        \brief Recreates the graphics pipeline.

        When MSAA is updated, the graphics pipeline must be recreated. This function handles that.
        */
        void recreateGraphicsPipeline();

        /**
        \brief Begin updating the text.

        This is to be called before adding any text. It is not required to update every frame.
        Note that the previous text in the buffer is erased when this method is called.
        */
        void beginUpdate();

        /**
        \brief Add text to the buffer.

        This is to be called after ```beginUpdate``` and before ```endUpdate```.
        This method adds the text to the buffer. The text is rendered in the order in which it is added.
        Hence the text added last will be rendered on top of the text added before it.
        
        @param text The text to be added.
        @param x The x coordinate of the text.
        @param y The y coordinate of the text.
        @param alignment The alignment of the text. Can be ```Left```, ```Center``` or ```Right```.
        */
        void add(std::string text, float x, float y, TextAlignment alignment);

        /**
        \brief End updating the text.

        This is to be called after adding all the text. Must be called if ```beginUpdate``` is called.
        */
        void endUpdate();

        /**
        \brief If MSAA is updated, this method must be called.

        If the MSAA is changed, this method has to be called to recreate the renderPass and framebuffers, along with associated objects
        */
        void changeMsaa();

        /**
        \brief Record the commands needed to render the text to the command buffers.

        @param currentFrame This is the current frame number that is to be queued for rendering.
        @param imageIndex This is the index of the image in the swapchain that is to be rendered to.
        @param bgColor This is the background color of the window. This is used to clear the screen before rendering the shapes if this is the first or standalone renderPass.
        */
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

        /**
        /brief If the swapChain has to be recreated, this method must be called.

        If the swapChain is invalid or has to be recreated, this method has to be called to recreate the renderPass and framebuffers, along with associated objects
        */
        void recreate();

        /**
        \brief Set of command buffers for rendering the text.

        This is the command Buffers to which the rendering commands needed to render the text are recorded .
        This gets updated on calling ```render``` method.
        */
        std::vector<VkCommandBuffer> commandBuffers;
private:

        /**
        \brief Cleanup the rendering objects.

        This is used to desroy the renderPass and framebuffers, along with associated objects during recreation of such objects.
        This is not equal to ```destroy``` as this does not destroy the shapes, their uniforms or their textures.
        This is just used to destroy the objects that are needed for rendering the shapes.
        */
        void cleanup();


        /**
        \brief The maximum length of the text that can be rendered. 

        This is set to 2048 by default. If you want to render more text, change this value.
        It is used to allocate memory for the buffers.
        */
        uint32_t maxTextLength = 2048;

        /**
        \brief The font data.
        */
        stb_fontchar stbFontData[STB_FONT_consolas_24_latin1_NUM_CHARS];
        
        /**
        \brief The number of letters in the font.
        */
        uint32_t numLetters;

        /**
        \brief The scale of the font.
        */
        float scale = 4.0f;

        /**
        \brief The path to the vertex SPIV-V shader file.
        */
        const char* vertexShaderPath = "ThirdParty/Chronos/Shaders/textVert.spv";
        
        /**
        \brief The path to the fragment SPIV-V shader file.
        */
        const char* fragmentShaderPath = "ThirdParty/Chronos/Shaders/textFrag.spv";
        
        /**
        \brief The device to render the text on.
        */
        Chronos::Engine::Device* device;

        /**
        \brief The swapchain to render the text on.
        */
        Chronos::Engine::SwapChain* swapChain;

        /**
        \brief The command pool to create the command buffers on.
        */
        VkCommandPool commandPool;

        /**
        \brief The sampler to use for the texture.
        */
        VkSampler textureSampler;


        VkBuffer vertexBuffer;
        VkDeviceMemory vertexBufferMemory;
        // VkImage texture;
        // VkImageView textureImageView;
        // VkDeviceMemory textureImageMemory;
        Chronos::Engine::Texture fontTexture;
        glm::vec4* mappedMemory;

        /**
        \brief RenderPass used for rendering the text
        */
        VkRenderPass renderPass;

        /**
        \brief This is the framebuffers to which the output of the associated renderPass is written to.
        */
        std::vector<VkFramebuffer> framebuffers;
        std::vector<VkDescriptorSet> descriptorSets;
        VkDescriptorSetLayout descriptorSetLayout;
        VkDescriptorPool descriptorPool;
        VkPipelineLayout pipelineLayout;
        VkPipeline graphicsPipeline;

        /**
        \brief Creates the graphics pipeline for this text.

        As we can see below, creating the graphics pipeline is a very long process. Hence it is better to have a function for it.
        This function sets all the parameters and stages for the graphics pipeline and creates it.
        For now only vertex and fragment shaders are used. In future, mesh shaders will be used instead of vertex shaders.
        */
        void createGraphicsPipeline();

        /**
        \brief Creates the descriptor pool for this text.
        */
        void createDescriptorPool();

        /**
        \brief Creates the descriptor set layout for this text.
        */
        void createDescriptorSetLayout();

        /**
        \brief Creates the descriptor sets for this text.
        */
        void createDescriptorSets();
    };
};
};