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
namespace Editor {
    class EditorManager {
    public:
        void init(Chronos::Manager::Manager* manager)
        {
            this->manager = manager;
        }
        void addElements();

    private:
        Chronos::Manager::Manager* manager;
        bool pinMenuBar = true;

        bool showShapeWindow = false;
        bool showPolygonWindow = false;
        bool showTextureWindow = false;
        bool showTextWindow = false;
        bool showAnimationWindow = false;
        bool showSettingsWindow = false;
        bool showGeneratedCodeWindow = false;

        bool showShapeDetailsWindow = false;
        bool showPolygonDetailsWindow = false;
        bool showTextureDetailsWindow = false;
        bool showTextDetailsWindow = false;

        bool showDebugMetricsWindow = false;
        bool showDebugLogWindow = false;
#ifdef CHRONOS_PROFILING
        bool showProfilingWindow = false;
#endif

        void MenuBar();
        void ShapeWindow();
        void PolygonWindow();
        void TextureWindow();
        void TextWindow();
        void SettingsWindow();
        void TotalCodeGenerationWindow();

        void ShapeDetailsWindow();
        void PolygonDetailsWindow();
        void TextureDetailsWindow();
        void TextDetailsWindow();

        void DebugMetricsWindow();
        void DebugLogWindow();
#ifdef CHRONOS_PROFILING
        void ProfilingWindow();
#endif
        // Shape Window
        Chronos::Manager::ShapeParams newShapeParams;
        int newShapeType = 0;
        int newShapeFill = 0;
        int currentShapeTextureSelection = 0;
        char currentShapeTextureName[200] = "Select Texture";
        int currentShapeSelection = 0;

        // Polygon Window
        Chronos::Manager::ShapeParams newPolygonParams;
        int numVertices = 4;
        std::vector<std::array<float, 2>> polygonVertices = { { -0.5, -0.5 }, { 0.5, -0.5 }, { 0.5, 0.5 }, { -0.5, 0.5 } };
        int currentPolygonTextureSelection = 0;
        char currentPolygonTextureName[200] = "Select Texture";
        int currentPolygonSelection = 0;
        std::vector<std::array<float, 2>> currentPolygonVertices;

        // Texture Window
        char newTexturePath[200];
        char newTextureName[200];
        int currentTextureSelection = 0;

        // Text Window
        Chronos::Engine::TextParams newTextParams;
        std::string currentFontSelection = "consolas";
        int currentFontSizeSelection = 6;
        int currentTextSelection = 0;

        // Shape details window
        Chronos::Manager::ShapeParams shapeDetailsShapeParams;
        int shapeDetailsShapeNo = 0;

        // polygon details window
        Chronos::Manager::ShapeParams polygonDetailsShapeParams;
        int polygonDetailsShapeNo = 0;

        // text details window
        Chronos::Engine::TextParams textDetailsTextParams;
        int textDetailsTextNo = 0;

        // texture details window
        int textureDetailsCurrentSelection = 0;

        // settings window
        char windowTitle[200] = GAME_NAME;
        std::string presentMode = "mailbox";
        float bgColor[3] = { 0, 0, 0 };
        bool fullScreen = false;
        bool isWindowFullscreen = false;
        std::string msaaSamples = "1";
    };
}
}
