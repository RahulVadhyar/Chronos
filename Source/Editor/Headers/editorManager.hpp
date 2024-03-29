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

                void MenuBar();
                void ShapeWindow();
                void PolygonWindow();
                void TextureWindow();
                void TextWindow();
                void SettingsWindow();

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
        };  
    }
}