#pragma once

namespace Chronos{
    namespace Editor{
        class EditorManager{
            public:
                void init(Chronos::Manager::Manager* manager){
                    this->manager = manager;
                }
                void addElements();
            private:
                Chronos::Manager::Manager* manager;
                
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

                void MenuBar();
                void ShapeWindow();
                void PolygonWindow();
                void TextureWindow();
                void TextWindow();
                void SettingsWindow();

                void ShapeDetailsWindow();
                void PolygonDetailsWindow();
                void TextureDetailsWindow();
                void TextDetailsWindow();

                //Shape Window
                Chronos::Manager::ShapeParams newShapeParams;
                int newShapeType = 0;
                int newShapeFill = 0;
                int currentShapeTextureSelection = 0;
                char currentShapeTextureName[200] = "Select Texture";
                int currentShapeSelection = 0;


                //Polygon Window
                Chronos::Manager::ShapeParams newPolygonParams;
                int currentPolygonTextureSelection = 0;
                char currentPolygonTextureName[200] = "Select Texture";
                int currentPolygonSelection = 0;

                
                //Texture Window
                char newTexturePath[200];
                char newTextureName[200];
                int currentTextureSelection = 0;
                char currentTextureName[200] = "Select Texture";

                //Text Window
                Chronos::Engine::TextParams newTextParams;
                std::string currentFontSelection = "consolas";
                int currentFontSizeSelection = 6;
                int currentTextSelection = 0;

                //Shape details window
                Chronos::Manager::ShapeParams shapeDetailsShapeParams;
                int shapeDetailsShapeNo = 0;

                //polygon details window
                Chronos::Manager::ShapeParams polygonDetailsShapeParams;
                int polygonDetailsShapeNo = 0;

                //settings window
                char windowTitle[200] = GAME_NAME;
                std::string presentMode = "mailbox";
        };  
    }
}