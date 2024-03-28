#pragma once

namespace Chronos {
namespace Engine {

    class PolygonManager : public Chronos::Engine::ObjectManager<Chronos::Engine::Polygon> {
    public:

        int addPolygon(Chronos::Manager::ShapeParams shapeParams, std::vector<std::array<float, 2>> vertices, Chronos::Engine::Texture texture);
        /**
        \brief Records the commands needed for rendering the shapes.

        When this function is called, it records the commands that are needed for rendering all the shapes stored in this class.

        @param currentFrame The current frame to render to.
        @param imageIndex The index of the framebuffer associated with the current frame
        @param bgColor The background color to set during rendering
        */
        void render(uint32_t currentFrame, uint32_t imageIndex, float bgColor[3]);

    private:
        /**
        \brief Creates the render pass for the shapes.

        This function is called by the ```init``` function. It creates the render pass for the shapes.
        */
        void createRenderPass();
    };
};
};
