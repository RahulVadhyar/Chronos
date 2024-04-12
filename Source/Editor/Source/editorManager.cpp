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

#include "stlheader.hpp"
#include "editorHeaders.hpp"
#include "chronos.hpp"
#include "editorManager.hpp"
#include "editorTheme.hpp"
#include "editorCodeGenerator.hpp"

void Chronos::Editor::EditorManager::addElements(){
    Chronos::Editor::setImGuiStyle();
    this->MenuBar();
    this->ShapeWindow();
    this->PolygonWindow();
    this->TextureWindow();
    this->TextWindow();
    this->SettingsWindow();
    this->TotalCodeGenerationWindow();
    this->ShapeDetailsWindow();
    this->PolygonDetailsWindow();
    this->TextureDetailsWindow();
    this->TextDetailsWindow();
    this->DebugMetricsWindow();
    this->DebugLogWindow();
#ifdef CHRONOS_PROFILING
    this->ProfilingWindow();
#endif

    LOG(4, "Editor", "Elements added to the editor.")

}

void Chronos::Editor::EditorManager::MenuBar(){
    if(this->pinMenuBar){
        if (ImGui::BeginMainMenuBar()) {
            ImGui::MenuItem("Shape", NULL, &this->showShapeWindow);
            ImGui::MenuItem("Polygon", NULL, &this->showPolygonWindow);
            ImGui::MenuItem("Texture", NULL, &this->showTextureWindow);
            ImGui::MenuItem("Text", NULL, &this->showTextWindow);
            // ImGui::MenuItem("Animation", NULL, &this->showAnimationWindow);
            ImGui::MenuItem("Settings", NULL, &this->showSettingsWindow);
            ImGui::MenuItem("Generated Code", NULL, &this->showGeneratedCodeWindow);
            #ifdef CHRONOS_PROFILING
            ImGui::MenuItem("Profiling", NULL, &this->showProfilingWindow);
            #endif
            ImGui::EndMainMenuBar();
        }
    } else {
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
}

void Chronos::Editor::EditorManager::ShapeWindow(){
    if(this->showShapeWindow){
        ImGui::Begin("Shape", &this->showShapeWindow);
            bool doesNameExist = false;
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
                                    LOG(1, "Editor", "Texture selected for shapeNo [" + std::to_string(currentShapeTextureSelection) + "], textureName [" + currentShapeTextureName + "]")
                                }
                                if(isSelected){
                                    ImGui::SetItemDefaultFocus();
                                }
                            }
                        }
                        ImGui::EndCombo();
                    }
            }
            if(!doesNameExist){           
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
                            LOG(1, "Editor", "Colored shape added with shapeName [" + std::string(this->newShapeParams.shapeName) + "]")
                            break;
                        case 1:
                            this->manager->addPolygon(this->newShapeParams, type, this->currentShapeTextureSelection);
                            LOG(1, "Editor", "Textured shape added with shapeName [" + std::string(this->newShapeParams.shapeName) + "]")
                            break;
                    }
                }
            }
        ImGui::SeparatorText("Current Shapes");
        if(ImGui::BeginListBox("Shapes")){
            std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails = this->manager->getShapeDetails();
            if(shapeDetails.size() == 0){
                ImGui::Selectable("No Shapes");
            } else {
                for(int i = 0; i < static_cast<int>(shapeDetails.size()); i++){
                    if(ImGui::Selectable(shapeDetails[i].second.shapeName, this->currentShapeSelection == i)){
                        this->currentShapeSelection = i;
                    }
                }                
            }
            ImGui::EndListBox();
            if(shapeDetails.size() > 0){
                ImGui::Text("Selected Shape: %d", shapeDetails[currentShapeSelection].first);
                if(ImGui::Button("Edit Shape")){
                    this->showShapeDetailsWindow = true;
                    this->shapeDetailsShapeNo = shapeDetails[currentShapeSelection].first;
                    this->shapeDetailsShapeParams = shapeDetails[currentShapeSelection].second;
                }
                ImGui::SameLine();
                if(ImGui::Button("Remove Shape")){
                    this->manager->removePolygon(shapeDetails[currentShapeSelection].first);
                }
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
        ImGui::SeparatorText("Vertices");
        ImGui::Text("Number of Vertices %d", this->numVertices);
        if(ImGui::Button("Add Vertices")){
            this->numVertices++;
            this->polygonVertices.push_back({0.0f, 0.0f});
            LOG(1, "Editor", "Vertex added to polygon")
        }
        ImGui::SameLine();
        if(ImGui::Button("Remove Vertices")){
            if(this->numVertices > 3){
                this->numVertices--;
                this->polygonVertices.pop_back();
                LOG(1, "Editor", "Vertex removed from polygon")
            }
        }
        for(int i = 0; i < this->numVertices; i++){
            ImGui::Text("Vertex %d", i);
            ImGui::DragFloat(("coord X " + std::to_string(i + 1) + "(-1 to 1)").c_str(), &this->polygonVertices[i][0], 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat(("coord Y " + std::to_string(i + 1) + "(-1 to 1)").c_str(), &this->polygonVertices[i][1], 0.01f, -1.0f, 1.0f);
        }

        if(!doesPolygonExist){
            if(ImGui::Button("Add Shape")){
                this->manager->addPolygon(this->newShapeParams, this->currentPolygonTextureSelection, this->polygonVertices);
                LOG(1, "Editor", "Polygon added with shapeName [" + std::string(this->newShapeParams.shapeName) + "]")
            }
        }
        ImGui::SeparatorText("Current Shapes");
        if(ImGui::BeginListBox("Shapes")){
            std::vector<std::pair<int, Chronos::Manager::ShapeParams>> polygonDetails = this->manager->getPolygonDetails();
            if(polygonDetails.size() == 0){
                ImGui::Selectable("No Polygons");
            } else {
                for(int i = 0; i < static_cast<int>(polygonDetails.size()); i++){
                    if(ImGui::Selectable(polygonDetails[i].second.shapeName, this->currentPolygonSelection == i)){
                        this->currentPolygonSelection = i;
                    }
                }
            }
            ImGui::EndListBox();
            if(polygonDetails.size() > 0){
                if(ImGui::Button("Edit Polygon")){
                    this->showPolygonDetailsWindow = true;
                    this->polygonDetailsShapeNo = polygonDetails[currentPolygonSelection].first;
                    this->polygonDetailsShapeParams = polygonDetails[currentPolygonSelection].second;
                    LOG(1, "Editor", "Polygon selected for editing with shapeNo [" + std::to_string(this->polygonDetailsShapeNo) + "]")
                }                

                ImGui::SameLine();
                if(ImGui::Button("Remove Polygon")){
                    this->manager->removePolygon(polygonDetails[currentPolygonSelection].first);
                    LOG(1, "Editor", "Polygon removed with shapeNo [" + std::to_string(polygonDetails[currentPolygonSelection].first) + "]")
                }
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
                if(std::string(this->newTextureName).size() == '\0'){
                    ImGui::Text("Name Cannot be empty");
                    doesTextureExist = true;
                    break;
                }
                if(!std::string(this->newTexturePath).ends_with(".jpg") && !std::string(this->newTexturePath).ends_with(".png")){
                    ImGui::Text("Only jpg and png files are supported");
                    doesTextureExist = true;
                    break;
                }
            }

            if(!doesTextureExist){
                if(ImGui::Button("Add Texture")){
                    this->manager->addTexture(this->newTexturePath, this->newTextureName);
                    this->newTexturePath[0] = '\0';
                    LOG(1, "Editor", "Texture added with textureName [" + std::string(this->newTextureName) + "] and texturePath [" + this->newTexturePath + "]")
                }  
            }   
            ImGui::SeparatorText("Current Textures");
            std::vector<Chronos::Manager::TextureDetails> details = this->manager->getTextureDetails();
            if(ImGui::BeginListBox("Textures")){
                if(details.size() == 0){
                    ImGui::Selectable("No Textures");
                } else {
                    for(int i = 0; i < static_cast<int>(details.size()); i++){
                        if(ImGui::Selectable(details[i].textureName.c_str(), currentTextureSelection == i)){
                            currentTextureSelection = i;
                        }
                    }
                }
                ImGui::EndListBox();
            }
            if(details.size() > 0){
                if(ImGui::Button("Remove Texture")){
                    this->manager->removeTexture(details[currentTextureSelection].textureNo);
                    LOG(1, "Editor", "Texture removed with textureNo [" + std::to_string(details[currentTextureSelection].textureNo) + "]")
                }
                ImGui::SameLine();
                if(ImGui::Button("View Texture Details")){
                    this->showTextureDetailsWindow = true;
                    LOG(1, "Editor", "Texture selected for editing with textureNo [" + std::to_string(this->textureDetailsCurrentSelection) + "]")
                }
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
                LOG(1, "Editor", "Font selected [" + this->currentFontSelection + "]")
            }
            if(ImGui::Selectable("consolas_bold", this->currentFontSelection == "consolas_bold")){
                this->currentFontSelection = "consolas_bold";
                LOG(1, "Editor", "Font selected [" + this->currentFontSelection + "]")
            }
            if(ImGui::Selectable("arial", this->currentFontSelection == "arial")){
                this->currentFontSelection = "arial";
                LOG(1, "Editor", "Font selected [" + this->currentFontSelection + "]")
            }
            if(ImGui::Selectable("arial_bold", this->currentFontSelection == "arial_bold")){
                this->currentFontSelection = "arial_bold";
                LOG(1, "Editor", "Font selected [" + this->currentFontSelection + "]")
            }
            if(ImGui::Selectable("times", this->currentFontSelection == "times")){
                this->currentFontSelection = "times";
                LOG(1, "Editor", "Font selected [" + this->currentFontSelection + "]")
            }
            if(ImGui::Selectable("times_bold", this->currentFontSelection == "times_bold")){
                this->currentFontSelection = "times_bold";
                LOG(1, "Editor", "Font selected [" + this->currentFontSelection + "]")
            }
            ImGui::EndCombo();
        }
        ImGui::DragInt("Font Size", &this->currentFontSizeSelection, 1, 6, 50);
        if(this->newTextParams.text.size() == 0){
            ImGui::Text("Text Cannot be empty");
        } else{
            if(ImGui::Button("Add Text")){
                this->manager->addText(this->newTextParams, this->currentFontSelection, this->currentFontSizeSelection);
                LOG(1, "Editor", "Text added with text [" + this->newTextParams.text + "]")
            }
        }
        ImGui::SeparatorText("Current Text");
        if(ImGui::BeginListBox("Text")){
            std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails = this->manager->getTextDetails();
            if(textDetails.size() == 0){
                ImGui::Selectable("No Text");
            } else {
                for(int i = 0; i < static_cast<int>(textDetails.size()); i++){
                    if(ImGui::Selectable(textDetails[i].second.text.c_str(), this->currentTextSelection == i)){
                        this->currentTextSelection = i;
                    }
                }
            }
            ImGui::EndListBox();
            if(textDetails.size() > 0){
                if(ImGui::Button("Edit Text")){
                    this->showTextDetailsWindow = true;
                    this->textDetailsTextNo = textDetails[currentTextSelection].first;
                    this->textDetailsTextParams = textDetails[currentTextSelection].second;
                    LOG(1, "Editor", "Text selected for editing with textNo [" + std::to_string(this->textDetailsTextNo) + "]")
                }
                ImGui::SameLine();
                if(ImGui::Button("Remove Text")){
                    this->manager->removeText(textDetails[currentTextSelection].first);
                    LOG(1, "Editor", "Text removed with textNo [" + std::to_string(textDetails[currentTextSelection].first) + "]")
                }
            }
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
            LOG(1, "Editor", "Window title updated to [" + std::string(this->windowTitle) + "]")
        }
        ImGui::Checkbox("Make Window Fullscreen", &this->fullScreen);
        if(this->fullScreen && !this->isWindowFullscreen){
            GLFWwindow* window = this->manager->getWindow();
            const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
            glfwSetWindowMonitor(window, glfwGetPrimaryMonitor(), 0, 0, mode->width, mode->height, mode->refreshRate);
            this->isWindowFullscreen = true;
            LOG(1, "Editor", "Window set to fullscreen")
        } else if(!this->fullScreen && this->isWindowFullscreen){
            GLFWwindow* window = this->manager->getWindow();
            glfwSetWindowMonitor(window, nullptr, 0, 0, 800, 600, 0);
            this->isWindowFullscreen = false;
            LOG(1, "Editor", "Window set to windowed mode")
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
            LOG(1, "Editor", "Present mode updated to [" + this->presentMode + "]")
        }

        ImGui::SeparatorText("MSAA Samples");
        std::vector<std::string> msaaSamples = this->manager->getMSAAModes();
        for(std::string sample : msaaSamples){
            if(ImGui::Selectable(sample.c_str(), this->msaaSamples == sample)){
                this->msaaSamples = sample;
            }
        }
        if(ImGui::Button("Update MSAA Samples")){
            this->manager->changeMSAA(this->msaaSamples);
            LOG(1, "Editor", "MSAA Samples updated to [" + this->msaaSamples + "]")
        }


        ImGui::SeparatorText("Background Color");
        ImGui::ColorEdit3("Background Color", this->bgColor);
        if(ImGui::Button("Update Background Color")){
            this->manager->changeBackgroundColor(this->bgColor[0], this->bgColor[1], this->bgColor[2]);
            LOG(1, "Editor", "Background color updated to [" + std::to_string(this->bgColor[0]) + ", " + std::to_string(this->bgColor[1]) + ", " + std::to_string(this->bgColor[2]) + "]")
        }

        ImGui::SeparatorText("ImGui Debug Settings");
        ImGui::Checkbox("Show Metrics", &this->showDebugMetricsWindow);
        ImGui::Checkbox("Show Log", &this->showDebugLogWindow);
        ImGui::Checkbox("Pin Menu Bar", &this->pinMenuBar);

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
            this->manager->updatePolygon(this->shapeDetailsShapeNo, this->shapeDetailsShapeParams);
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
            ImGui::InputText("Polygon Name", this->polygonDetailsShapeParams.shapeName, 200);
            ImGui::DragFloat("X(-1 to 1)", &this->polygonDetailsShapeParams.x, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("Y(-1 to 1)", &this->polygonDetailsShapeParams.y, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("X Size", &this->polygonDetailsShapeParams.xSize, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Y Size", &this->polygonDetailsShapeParams.ySize, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Rotation", &this->polygonDetailsShapeParams.rotation, 0.01f, 0.0f, FLT_MAX);

            this->currentPolygonVertices = this->manager->getPolygonVertices(this->polygonDetailsShapeNo);
            ImGui::SeparatorText("Polygon Vertices");
            for(int i = 0; i < static_cast<int>(this->currentPolygonVertices.size()); i++){
                ImGui::Text("Vertex %d", i);
                ImGui::DragFloat(("X " + std::to_string(i + 1) + "(-1 to 1)").c_str(), &this->currentPolygonVertices[i][0], 0.01f, -1.0f, 1.0f);
                ImGui::DragFloat(("Y " + std::to_string(i + 1) + "(-1 to 1)").c_str(), &this->currentPolygonVertices[i][1], 0.01f, -1.0f, 1.0f);
            }
            this->manager->updatePolygon(this->polygonDetailsShapeNo, this->polygonDetailsShapeParams, this->currentPolygonVertices);
        }
        ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextureDetailsWindow(){
    if(this->showTextureDetailsWindow){
        ImGui::Begin("Texture Details", &this->showTextureDetailsWindow);
        ImGui::SeparatorText("Texture Details");
        std::vector<Chronos::Manager::TextureDetails> textureDetails = this->manager->getTextureDetails();
        if(textureDetails.size() == 0){
            ImGui::Text("No Textures");
        } else {
            ImGui::Text("Texture Name: %s", textureDetails[this->textureDetailsCurrentSelection].textureName.data());
            ImGui::Text("Texture Path: %s", textureDetails[this->textureDetailsCurrentSelection].texturePath.data());
            ImGui::Text("Width: %d", textureDetails[this->textureDetailsCurrentSelection].width);
            ImGui::Text("Height: %d", textureDetails[this->textureDetailsCurrentSelection].height);
            ImGui::SeparatorText("Texture Preview");
            ImGui::Image((ImTextureID)textureDetails[this->textureDetailsCurrentSelection].descriptorSet, ImVec2(textureDetails[this->textureDetailsCurrentSelection].width, textureDetails[this->textureDetailsCurrentSelection].height));

        }
        ImGui::End();
    }
}

void Chronos::Editor::EditorManager::TextDetailsWindow(){
    if(this->showTextDetailsWindow){
        ImGui::Begin("Text Details", &this->showTextDetailsWindow);
        ImGui::SeparatorText("Text Details");
        std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails = this->manager->getTextDetails();
        if(textDetails.size() == 0){
            ImGui::Text("No Text");
        } else {
            char inputText[2048];
            strcpy(inputText, this->textDetailsTextParams.text.c_str());
            ImGui::InputText("Text", inputText, 2048);
            if(inputText[0] != '\0'){
                this->textDetailsTextParams.text = inputText;
                ImGui::Text("Text Field cannot be empty");
            }

            ImGui::DragFloat("X(-1 to 1)", &this->textDetailsTextParams.x, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("Y(-1 to 1)", &this->textDetailsTextParams.y, 0.01f, -1.0f, 1.0f);
            ImGui::DragFloat("Rotation", &this->textDetailsTextParams.rotation, 0.01f, 0.0f, FLT_MAX);
            ImGui::DragFloat("Scale", &this->textDetailsTextParams.scale, 0.01f, 0.0f, FLT_MAX);
            ImGui::ColorEdit3("Color", this->textDetailsTextParams.color.data());
            this->manager->updateText(this->textDetailsTextNo, this->textDetailsTextParams);
        }
        ImGui::End();
    }
}
void Chronos::Editor::EditorManager::DebugMetricsWindow(){
    if(this->showDebugMetricsWindow){
        ImGui::ShowMetricsWindow(&this->showDebugMetricsWindow);
    }
}

void Chronos::Editor::EditorManager::DebugLogWindow(){
    if(this->showDebugLogWindow){
        ImGui::ShowDebugLogWindow(&this->showDebugLogWindow);
    }
}

#ifdef CHRONOS_PROFILING
void Chronos::Editor::EditorManager::ProfilingWindow(){
    if(this->showProfilingWindow){
        ImGui::Begin("Profiling", &this->showProfilingWindow);
        ImGui::Text("FPS %f ms", 1000/this->manager->getTotalTime());
        ImGui::Text("Frame Time %f ms", this->manager->getTotalTime());
        ImGui::Text("Update Time %f ms", this->manager->getUpdateTime());
        ImGui::Text("CPU Time %f ms", this->manager->getCpuTime());
        ImGui::Text("GPU Time %f ms", this->manager->getTotalTime() - this->manager->getCpuTime());
        ImGui::Text("Present Time %f ms", this->manager->getPresentTime());
        ImGui::End();
    }
}
#endif

void Chronos::Editor::EditorManager::TotalCodeGenerationWindow(){
    if(this->showGeneratedCodeWindow){
        ImGui::Begin("Generated Code", &this->showGeneratedCodeWindow);
        ImGui::SeparatorText("Generated Code");
        std::string code = Chronos::Editor::generateCode(this->manager);
        ImGui::InputTextMultiline("Code", code.data(), code.size(), ImVec2(800, 600), ImGuiInputTextFlags_ReadOnly);
        ImGui::End();
    }
}
