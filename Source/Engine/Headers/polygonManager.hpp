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
