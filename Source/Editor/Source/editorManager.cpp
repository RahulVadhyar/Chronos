#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "stlheader.hpp"
#include "editorHeaders.hpp"
#include "chronos.hpp"
#include "editorManager.hpp"
#include "editorTheme.hpp"
#include <cstring>

void Chronos::Editor::EditorManager::addElements(){
    Chronos::Editor::setImGuiStyle();
    this->MenuBar();
    this->ShapeWindow();
    this->PolygonWindow();
    this->TextureWindow();
    this->TextWindow();
    this->SettingsWindow();
    this->ShapeDetailsWindow();
    this->PolygonDetailsWindow();
    this->TextureDetailsWindow();
    this->TextDetailsWindow();

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
            bool doesNameExist = false;
            ImGui::BeginChild("Add Shapes");
                ImGui::SeparatorText("Shape Name");
                ImGui::InputText("Shape Name", this->newShapeParams.shapeName, 200);
                std::vector<std::pair<int, Chronos::Manager::ShapeParams>> nameShapeDetails = this->manager->getShapeDetails();
                for(std::pair<int, Chronos::Manager::ShapeParams> shapeDetail : nameShapeDetails){
                    if(!strcmp(this->newShapeParams.shapeName, shapeDetail.second.shapeName)){
                        ImGui::Text("Name Already Exists");
                        doesNameExist = true;
                        break;
                    }
                }
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
                if(!doesNameExist){           \
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
                }
            ImGui::EndChild();
        ImGui::SeparatorText("Current Shapes");
        if(ImGui::BeginListBox("Shapes")){
            std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails = this->manager->getShapeDetails();
            if(shapeDetails.size() == 0){
                ImGui::Selectable("No Shapes");
            } else {
                for(std::pair<int, Chronos::Manager::ShapeParams> shapeDetail : shapeDetails){
                    if(ImGui::Selectable(shapeDetail.second.shapeName, (this->currentShapeSelection == shapeDetail.first))){
                        this->currentShapeSelection = shapeDetail.first;
                    }
                }
                
            }
            ImGui::EndListBox();
            ImGui::Text("Selected Shape: %d", shapeDetails[currentShapeSelection].first);
            if(ImGui::Button("Edit Shape")){
                this->showShapeDetailsWindow = true;
                this->shapeDetailsShapeNo = shapeDetails[currentShapeSelection].first;
                this->shapeDetailsShapeParams = shapeDetails[currentShapeSelection].second;
            }
            ImGui::SameLine();
            if(ImGui::Button("Remove Shape")){
                this->manager->removePolygon(this->currentShapeSelection);
            }
        }

        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::PolygonWindow(){
    if(this->showPolygonWindow){
        bool doesPolygonExist = false;
        ImGui::Begin("Polygon", &this->showPolygonWindow);
        ImGui::SeparatorText("Add Polygon");
        ImGui::SeparatorText("Polygon Name");
        ImGui::InputText("Polygon Name", this->newPolygonParams.shapeName, 200);
        std::vector<std::pair<int, Chronos::Manager::ShapeParams>> namePolygonDetails = this->manager->getPolygonDetails();
        for(std::pair<int, Chronos::Manager::ShapeParams> polygonDetail : namePolygonDetails){
            if(!strcmp(this->newPolygonParams.shapeName, polygonDetail.second.shapeName)){
                ImGui::Text("Name Already Exists");
                doesPolygonExist = true;
                break;
            }
        }
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
        if(!doesPolygonExist){
            if(ImGui::Button("Add Shape")){
                this->manager->addPolygon(this->newShapeParams, this->currentPolygonTextureSelection, {{-0.5, -0.5}, {0.5, -0.5}, {0.5, 0.5}, {-0.5, 0.5} });
            }
        }
        ImGui::SeparatorText("Current Shapes");
        if(ImGui::BeginListBox("Shapes")){
            std::vector<std::pair<int, Chronos::Manager::ShapeParams>> polygonDetails = this->manager->getPolygonDetails();
            if(polygonDetails.size() == 0){
                ImGui::Selectable("No Polygons");
            } else {
                for(std::pair<int, Chronos::Manager::ShapeParams> polygonDetail : polygonDetails){
                    if(ImGui::Selectable(polygonDetail.second.shapeName, this->currentPolygonSelection == polygonDetail.first)){
                        this->currentPolygonSelection = polygonDetail.first;
                    }
                }
                if(ImGui::Button("Edit Polygon")){
                    this->showPolygonDetailsWindow = true;
                }                
            }
            ImGui::EndListBox();
            ImGui::SameLine();
                if(ImGui::Button("Remove Polygon")){
                    this->manager->removePolygon(this->currentPolygonSelection);
                }
        }
        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::TextureWindow(){
    if(this->showTextureWindow){
        ImGui::Begin("Texture", &this->showTextureWindow);
            bool doesTextureExist = false;
            ImGui::SeparatorText("Add Textures");
            ImGui::InputText("Texture Path", this->newTexturePath, 200);
            ImGui::InputText("Texture Name", this->newTextureName, 200);
            std::vector<Chronos::Manager::TextureDetails> nameTextureDetails = this->manager->getTextureDetails();
            for(Chronos::Manager::TextureDetails textureDetail : nameTextureDetails){
                if(!strcmp(this->newTextureName, textureDetail.textureName.c_str())){
                    ImGui::Text("Name Already Exists");
                    doesTextureExist = true;
                    break;
                }
            }

            if(!doesTextureExist){
                if(ImGui::Button("Add Texture")){
                    this->manager->addTexture(this->newTexturePath, this->newTextureName);
                    this->newTexturePath[0] = '\0';
                }  
            }   
            ImGui::SeparatorText("Current Textures");
            if(ImGui::BeginListBox("Textures")){
                std::vector<Chronos::Manager::TextureDetails> details = this->manager->getTextureDetails();
                if(details.size() == 0){
                    ImGui::Selectable("No Textures");
                } else {
                    for(int i = 0; i < details.size(); i++){
                        if(ImGui::Selectable(details[i].textureName.c_str(), currentTextureSelection == i)){
                            currentTextureSelection = i;
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
        ImGui::SeparatorText("Add Text");
        char inputText[2048];
        strcpy(inputText, this->newTextParams.text.c_str());
        ImGui::InputText("Text", inputText, 2048);
        this->newTextParams.text = inputText;
        ImGui::DragFloat("X(-1 to 1)", &this->newTextParams.x, 0.01f, -1.0f, 1.0f);
        ImGui::DragFloat("Y(-1 to 1)", &this->newTextParams.y, 0.01f, -1.0f, 1.0f);
        ImGui::DragFloat("Rotation", &this->newTextParams.rotation, 0.01f, 0.0f, FLT_MAX);
        ImGui::DragFloat("Scale", &this->newTextParams.scale, 0.01f, 0.0f, FLT_MAX);
        ImGui::ColorEdit3("Color", this->newTextParams.color.data());
        if(ImGui::BeginCombo("Select Font", this->currentFontSelection.c_str())){
            if(ImGui::Selectable("consolas", this->currentFontSelection == "consolas")){
                this->currentFontSelection = "consolas";
            }
            if(ImGui::Selectable("consolas_bold", this->currentFontSelection == "consolas_bold")){
                this->currentFontSelection = "consolas_bold";
            }
            if(ImGui::Selectable("arial", this->currentFontSelection == "arial")){
                this->currentFontSelection = "arial";
            }
            if(ImGui::Selectable("arial_bold", this->currentFontSelection == "arial_bold")){
                this->currentFontSelection = "arial_bold";
            }
            if(ImGui::Selectable("times", this->currentFontSelection == "times")){
                this->currentFontSelection = "times";
            }
            if(ImGui::Selectable("times_bold", this->currentFontSelection == "times_bold")){
                this->currentFontSelection = "times_bold";
            }
            ImGui::EndCombo();
        }
        ImGui::DragInt("Font Size", &this->currentFontSizeSelection, 1, 6, 50);
        if(ImGui::Button("Add Text")){
            this->manager->addText(this->newTextParams, this->currentFontSelection, this->currentFontSizeSelection);
        }
        ImGui::SeparatorText("Current Text");
        if(ImGui::BeginListBox("Text")){
            std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails = this->manager->getTextDetails();
            if(textDetails.size() == 0){
                ImGui::Selectable("No Text");
            } else {
                for(std::pair<int, Chronos::Engine::TextParams> textDetail : textDetails){
                    if(ImGui::Selectable(textDetail.second.text.c_str(), this->currentTextSelection == textDetail.first)){
                        this->currentTextSelection = textDetail.first;
                    }
                }
            }
            ImGui::EndListBox();
        }
        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::SettingsWindow(){
    if(this->showSettingsWindow){
        ImGui::Begin("Settings", &this->showSettingsWindow);
        ImGui::SeparatorText("Build Information");
        ImGui::Text("Engine name: %s", "Chronos");
        ImGui::Text("Build Version: %d.%d.%d", CHRONOS_VERSION_MAJOR, CHRONOS_VERSION_MINOR, CHRONOS_VERSION_PATCH);
        ImGui::Text("Build Date: %s", __DATE__);
        ImGui::Text("Build Time: %s", __TIME__);
        ImGui::SeparatorText("Window Settings");
        ImGui::InputText("Window Title", this->windowTitle, 200);
        if(ImGui::Button("Update Window Title")){
            glfwSetWindowTitle(this->manager->getWindow(), this->windowTitle);
        }
        ImGui::Checkbox("Make Window Fullscreen", &this->fullScreen);
        if(this->fullScreen && !this->isWindowFullscreen){
            GLFWwindow* window = this->manager->getWindow();
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
            this->isWindowFullscreen = true;
        } else if(!this->fullScreen && this->isWindowFullscreen){
            GLFWwindow* window = this->manager->getWindow();
            glfwSetWindowMonitor(window, nullptr, 0, 0, 800, 600, 0);
            this->isWindowFullscreen = false;
        }
        ImGui::SeparatorText("Present Mode");
        if(ImGui::BeginCombo("Present Mode", this->presentMode.c_str())){
            if(ImGui::Selectable("mailbox", this->presentMode == "mailbox")){
                this->presentMode = "mailbox";
            }
            if(ImGui::Selectable("immediate", this->presentMode == "immediate")){
                this->presentMode = "immediate";
            }
            if(ImGui::Selectable("fifo", this->presentMode == "fifo")){
                this->presentMode = "fifo";
            }
            if(ImGui::Selectable("fifo_relaxed", this->presentMode == "fifo_relaxed")){
                this->presentMode = "fifo_relaxed";
            }
            ImGui::EndCombo();
        }
        if(ImGui::Button("Update Present Mode")){
            this->manager->changePresentMode(this->presentMode);
        }
        ImGui::SeparatorText("Background Color");
        ImGui::ColorEdit3("Background Color", this->bgColor);
        if(ImGui::Button("Update Background Color")){
            this->manager->changeBackgroundColor(this->bgColor[0], this->bgColor[1], this->bgColor[2]);
        }

        ImGui::End();
    }
}   

void Chronos::Editor::EditorManager::ShapeDetailsWindow(){
    if(this->showShapeDetailsWindow){
        ImGui::Begin("Shape Details", &this->showShapeDetailsWindow);
        ImGui::SeparatorText("Shape Details");
        if(this->manager->getShapeDetails().size() == 0){
            ImGui::Text("No Shapes");
        } else {
            ImGui::InputText("Shape Name", this->shapeDetailsShapeParams.shapeName, 200);
            ImGui::DragFloat("X(-1 to 1)", &this->shapeDetailsShapeParams.x, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("Y(-1 to 1)", &this->shapeDetailsShapeParams.y, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("X Size", &this->shapeDetailsShapeParams.xSize, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Y Size", &this->shapeDetailsShapeParams.ySize, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Rotation", &this->shapeDetailsShapeParams.rotation, 0.01f, 0.0f, FLT_MAX);
            ImGui::ColorEdit3("Color", this->shapeDetailsShapeParams.color.data());
            if(ImGui::Button("Update Shape")){
                this->manager->updatePolygon(this->shapeDetailsShapeNo, this->shapeDetailsShapeParams);
            }
        }
        ImGui::End();
    }
}

void Chronos::Editor::EditorManager::PolygonDetailsWindow(){
    if(this->showPolygonDetailsWindow){
        ImGui::Begin("Polygon Details", &this->showPolygonDetailsWindow);
        ImGui::SeparatorText("Polygon Details");
        std::vector<std::pair<int, Chronos::Manager::ShapeParams>> polygonDetails = this->manager->getPolygonDetails();
        if(polygonDetails.size() == 0){
            ImGui::Text("No Polygons");
        } else {
            this->polygonDetailsShapeNo = polygonDetails[currentShapeSelection].first;
            this->polygonDetailsShapeParams = polygonDetails[currentShapeSelection].second;
            ImGui::InputText("Polygon Name", this->polygonDetailsShapeParams.shapeName, 200);
            ImGui::DragFloat("X(-1 to 1)", &this->polygonDetailsShapeParams.x, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("Y(-1 to 1)", &this->polygonDetailsShapeParams.y, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("X Size", &this->polygonDetailsShapeParams.xSize, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Y Size", &this->polygonDetailsShapeParams.ySize, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Rotation", &this->polygonDetailsShapeParams.rotation, 0.01f, 0.0f, FLT_MAX);
            if(ImGui::Button("Update Polygon")){
                this->manager->updatePolygon(this->polygonDetailsShapeNo, this->polygonDetailsShapeParams);
            }
        }
        ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextureDetailsWindow(){
    if(this->showTextureDetailsWindow){
        ImGui::Begin("Texture Details", &this->showTextureDetailsWindow);
        ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextDetailsWindow(){
    if(this->showTextDetailsWindow){
        ImGui::Begin("Text Details", &this->showTextDetailsWindow);
        ImGui::End();
    }
}