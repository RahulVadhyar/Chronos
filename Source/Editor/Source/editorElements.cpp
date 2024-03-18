#include "stlheader.hpp"
#include "imgui.h"
#ifdef ENABLE_EDITOR
#include "editorHeaders.hpp"
#include "editorElements.hpp"

void Chronos::Editor::addElements()
{   
    bool showShapeWindow = false;
    ImGui::Begin("Editor", nullptr, ImGuiWindowFlags_MenuBar);
    if (ImGui::BeginMenuBar()) {
        if (ImGui::BeginMenu("Shape")){
            ImGui::MenuItem("Textured");
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Text")){
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Texture")){
            ImGui::EndMenu();
            
        }
        if (ImGui::BeginMenu("Skeleton")){
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Animation")){
            ImGui::EndMenu();

        }
        if (ImGui::BeginMenu("Settings")){
            ImGui::EndMenu();

        }
        ImGui::EndMenuBar();
    }
    ImGui::End();

    if(ImGui::Begin("Shape", &showShapeWindow)){
        
        ImGui::Text("Hello World!");
        ImGui::End();
    }
}
#endif