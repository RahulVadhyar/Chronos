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
                bool showSettingsWindow = false;

                void MenuBar();
                void ShapeWindow();
                void PolygonWindow();
                void TextureWindow();
                void TextWindow();
                void SettingsWindow();

                Chronos::Manager::ShapeParams newShapeParams;
                int newShapeType = 0;
                int newShapeFill = 0;

                char newTexturePath[200];
                char newTextureName[200];
                int currentTextureSelection = 0;
        };  
    }
}