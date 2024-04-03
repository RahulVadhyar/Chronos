#include "chronos.hpp"
#include "editorManager.hpp"

Chronos::Editor::EditorManager editorManager;

void addElements(){
    editorManager.addElements();
}

int main(){
    Chronos::Manager::Initializer initializer;
    initializer.WindowWidth = 800;
    initializer.WindowHeight = 600;
    initializer.BackgroundColor[0] = 0;
    initializer.BackgroundColor[1] = 0;
    initializer.BackgroundColor[2] = 0;
    initializer.editorAddElements = addElements;

    Chronos::Manager::Manager manager(initializer);
    LOG(2, "EditorMain", "Manager created.");
    editorManager.init(&manager);
    LOG(3, "EditorMain", "EditorManager created.")

    while (!glfwWindowShouldClose(manager.getWindow())) {
        if (glfwGetKey(manager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(manager.getWindow(), true);
        }
        manager.drawFrame();
        LOG(4, "EditorMain", "Frame drawn.");
    }
    LOG(2, "EditorMain", "Exited rendering loop, closing program.");
    return 0;
}