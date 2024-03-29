#include "chronos.hpp"
#include "editorManager.hpp"

Chronos::Editor::EditorManager editorManager;

void addElements(){
    editorManager.addElements();
}

int main(){

    std::filesystem::path cwdpath("../../../");
    std::filesystem::current_path(cwdpath);
    Chronos::Manager::Initializer initializer;
    initializer.WindowWidth = 800;
    initializer.WindowHeight = 600;
    initializer.BackgroundColor[0] = 0;
    initializer.BackgroundColor[1] = 0;
    initializer.BackgroundColor[2] = 0;
    initializer.editorAddElements = addElements;

    Chronos::Manager::Manager manager(initializer);
    editorManager.init(&manager);
    
    while (!glfwWindowShouldClose(manager.getWindow())) {
        if (glfwGetKey(manager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(manager.getWindow(), true);
        }
        manager.drawFrame();
    }
    
    return 0;
}