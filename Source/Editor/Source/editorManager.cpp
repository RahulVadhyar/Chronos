#include "stlheader.hpp"
#include "chronos.hpp"
#include "editorManager.hpp"
#include "imgui.h"
#include "editorHeaders.hpp"

void Chronos::Editor::EditorManager::addElements(){
    this->MenuBar();
    this->ShapeWindow();
    this->PolygonWindow();
    this->TextureWindow();
    this->TextWindow();
    this->SettingsWindow();
}

void Chronos::Editor::EditorManager::MenuBar(){
    ImGui::Begin("Editor", nullptr, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
        ImGui::MenuItem("Shape", NULL, &this->showShapeWindow);
        ImGui::MenuItem("Polygon", NULL, &this->showPolygonWindow);
        ImGui::MenuItem("Texture", NULL, &this->showTextureWindow);
        ImGui::MenuItem("Text", NULL, &this->showTextWindow);
        ImGui::MenuItem("Settings", NULL, &this->showSettingsWindow);
        ImGui::EndMenuBar();
    }
    ImGui::End();
}

void Chronos::Editor::EditorManager::ShapeWindow(){
    if(this->showShapeWindow){
        ImGui::Begin("Shape", &this->showShapeWindow);
            ImGui::BeginChild("Add Shapes");
                ImGui::SeparatorText("Type");
                ImGui::RadioButton("Triangle", &this->newShapeType, 0);
                ImGui::RadioButton("Rectangle", &this->newShapeType, 1);
                ImGui::SeparatorText("Fill");
                ImGui::RadioButton("Color", &this->newShapeFill, 0);
                ImGui::RadioButton("Texture", &this->newShapeFill, 1);
                ImGui::SeparatorText("Properties");
                ImGui::DragFloat("X(-1 to 1)", &this->newShapeParams.x, 0.01f, -1.0f, 1.0f);
                ImGui::DragFloat("Y(-1 to 1)", &this->newShapeParams.y, 0.01f, -1.0f, 1.0f);
                ImGui::DragFloat("X Size", &this->newShapeParams.xSize, 0.01f, 0.0f, FLT_MAX);
                ImGui::DragFloat("Y Size", &this->newShapeParams.ySize, 0.01f, 0.0f, FLT_MAX);
                ImGui::DragFloat("Rotation", &this->newShapeParams.rotation, 0.01f, 0.0f, FLT_MAX);
                if(this->newShapeFill == 0){
                    ImGui::ColorEdit3("Color", this->newShapeParams.color.data());
                }

            ImGui::EndChild();
        ImGui::SeparatorText("Existing Shapes");
        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::PolygonWindow(){
    if(this->showPolygonWindow){
        ImGui::Begin("Polygon", &this->showPolygonWindow);
        ImGui::Text("Hello World!");
        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::TextureWindow(){
    if(this->showTextureWindow){
        ImGui::Begin("Texture", &this->showTextureWindow);
            ImGui::BeginChild("Add Textures");
                ImGui::InputText("Texture Path", this->newTexturePath, 200);
                ImGui::InputText("Texture Name", this->newTextureName, 200);
                if(ImGui::Button("Add Texture")){
                    this->manager->addTexture(this->newTexturePath, this->newTextureName);
                    this->newTexturePath[0] = '\0';
                }
            ImGui::EndChild();            
            ImGui::SeparatorText("Existing Textures");
            if(ImGui::BeginListBox("Textures")){
                std::vector<Chronos::Manager::TextureDetails> details = this->manager->getTextureDetails();
                if(details.size() == 0){
                    ImGui::Selectable("No Textures");
                } else {
                    for(int i = 0; i < details.size(); i++){
                        bool isSelected = currentTextureSelection == i;
                        if(ImGui::Selectable(details[i].textureName.c_str(), isSelected)){
                            currentTextureSelection = i;
                        }
                        if(isSelected){
                            ImGui::SetItemDefaultFocus();
                        }
                    }
                }
                ImGui::EndListBox();
            }
        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::TextWindow(){
    if(this->showTextWindow){
        ImGui::Begin("Text", &this->showTextWindow);
        
        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::SettingsWindow(){
    if(this->showSettingsWindow){
        ImGui::Begin("Settings", &this->showSettingsWindow);
        ImGui::Text("Hello World!");
        ImGui::End();
    }
}   