#include "stlheader.hpp"
#include "chronos.hpp"
#include "editorManager.hpp"
#include "imgui.h"
#include "editorHeaders.hpp"
#include "editorTheme.hpp"

void Chronos::Editor::EditorManager::addElements(){\
    Chronos::Editor::setImGuiStyle();
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
        ImGui::MenuItem("Animation", NULL, &this->showAnimationWindow);
        ImGui::MenuItem("Settings", NULL, &this->showSettingsWindow);
        ImGui::MenuItem("Generated Code", NULL, &this->showGeneratedCodeWindow);
        ImGui::EndMenuBar();
    }
    ImGui::End();
}

void Chronos::Editor::EditorManager::ShapeWindow(){
    if(this->showShapeWindow){
        ImGui::Begin("Shape", &this->showShapeWindow);
            ImGui::BeginChild("Add Shapes");
                ImGui::SeparatorText("Shape Name");
                ImGui::InputText("Shape Name", this->newShapeParams.shapeName, 200);
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
                switch(this->newShapeFill){
                    case 0:
                        ImGui::ColorEdit3("Color", this->newShapeParams.color.data());
                        break;
                    case 1:
                        if(ImGui::BeginCombo("Select Texture", currentShapeTextureName)){
                            std::vector<Chronos::Manager::TextureDetails> details = this->manager->getTextureDetails();
                            if(details.size() == 0){
                                ImGui::Selectable("No Textures");
                            } else {
                                for(Chronos::Manager::TextureDetails textureDetail : details){
                                    bool isSelected = currentShapeTextureSelection == textureDetail.textureNo;
                                    if(ImGui::Selectable(textureDetail.textureName.c_str(), isSelected)){
                                        currentShapeTextureSelection = textureDetail.textureNo;
                                        strcpy(currentShapeTextureName, textureDetail.textureName.c_str());
                                    }
                                    if(isSelected){
                                        ImGui::SetItemDefaultFocus();
                                    }
                                }
                            }
                            ImGui::EndCombo();
                        }
                }
                if(ImGui::Button("Add Shape")){
                    Chronos::Manager::PolygonType type;
                    switch(this->newShapeType){
                        case 0:
                            type.triangle = true;
                            break;
                        case 1:
                            type.rectangle = true;
                            break;
                    }
                    switch(this->newShapeFill){
                        case 0:
                            this->manager->addPolygon(this->newShapeParams, type);
                            break;
                        case 1:
                            this->manager->addPolygon(this->newShapeParams, type, this->currentShapeTextureSelection);
                            break;
                    }
                }
            ImGui::EndChild();
        ImGui::SeparatorText("Current Shapes");
        if(ImGui::BeginListBox("Shapes")){
            std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails = this->manager->getShapeDetails();
            if(shapeDetails.size() == 0){
                ImGui::Selectable("No Shapes");
            } else {
                for(std::pair<int, Chronos::Manager::ShapeParams> shapeDetail : shapeDetails){
                    bool isSelected = this->currentShapeSelection == shapeDetail.first;
                    if(ImGui::Selectable(shapeDetail.second.shapeName, isSelected)){
                        this->currentShapeSelection = shapeDetail.first;
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

void Chronos::Editor::EditorManager::PolygonWindow(){
    if(this->showPolygonWindow){
        ImGui::Begin("Polygon", &this->showPolygonWindow);
        ImGui::SeparatorText("Add Polygon");
        ImGui::SeparatorText("Polygon Name");
        ImGui::InputText("Polygon Name", this->newPolygonParams.shapeName, 200);
        ImGui::SeparatorText("Properties");
        ImGui::DragFloat("X(-1 to 1)", &this->newPolygonParams.x, 0.01f, -1.0f, 1.0f);
        ImGui::DragFloat("Y(-1 to 1)", &this->newPolygonParams.y, 0.01f, -1.0f, 1.0f);
        ImGui::DragFloat("X Size", &this->newPolygonParams.xSize, 0.01f, 0.0f, FLT_MAX);
        ImGui::DragFloat("Y Size", &this->newPolygonParams.ySize, 0.01f, 0.0f, FLT_MAX);
        ImGui::DragFloat("Rotation", &this->newPolygonParams.rotation, 0.01f, 0.0f, FLT_MAX);
        if(ImGui::BeginCombo("Select Texture", currentPolygonTextureName)){
            std::vector<Chronos::Manager::TextureDetails> details = this->manager->getTextureDetails();
            if(details.size() == 0){
                ImGui::Selectable("No Textures");
            } else {
                for(Chronos::Manager::TextureDetails textureDetail : details){
                    bool isSelected = currentPolygonTextureSelection == textureDetail.textureNo;
                    if(ImGui::Selectable(textureDetail.textureName.c_str(), isSelected)){
                        currentPolygonTextureSelection = textureDetail.textureNo;
                        strcpy(currentPolygonTextureName, textureDetail.textureName.c_str());
                    }
                    if(isSelected){
                        ImGui::SetItemDefaultFocus();
                    }
                }
            }
            ImGui::EndCombo();
        }
        if(ImGui::Button("Add Shape")){
            Chronos::Manager::PolygonType type;
            type.npolygon = true;
            this->manager->addPolygon(this->newShapeParams, type, this->currentPolygonTextureSelection, {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5} });
        }
        ImGui::SeparatorText("Current Shapes");
        if(ImGui::BeginListBox("Shapes")){
            std::vector<std::pair<int, Chronos::Manager::ShapeParams>> polygonDetails = this->manager->getPolygonDetails();
            if(polygonDetails.size() == 0){
                ImGui::Selectable("No Polygons");
            } else {
                for(std::pair<int, Chronos::Manager::ShapeParams> polygonDetail : polygonDetails){
                    bool isSelected = this->currentShapeSelection == polygonDetail.first;
                    if(ImGui::Selectable(polygonDetail.second.shapeName, isSelected)){
                        this->currentShapeSelection = polygonDetail.first;
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

void Chronos::Editor::EditorManager::TextureWindow(){
    if(this->showTextureWindow){
        ImGui::Begin("Texture", &this->showTextureWindow);
            ImGui::SeparatorText("Add Textures");
            ImGui::InputText("Texture Path", this->newTexturePath, 200);
            ImGui::InputText("Texture Name", this->newTextureName, 200);
            if(ImGui::Button("Add Texture")){
                this->manager->addTexture(this->newTexturePath, this->newTextureName);
                this->newTexturePath[0] = '\0';
            }     
            ImGui::SeparatorText("Current Textures");
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
        ImGui::Text("Functions for this are yet to be defined");
        ImGui::End();
    }
}   

