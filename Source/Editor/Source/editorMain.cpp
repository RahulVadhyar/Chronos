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
    LOG(2, "EditorMain", "Manager created.")
    editorManager.init(&manager);
    LOG(3, "EditorMain", "EditorManager created.")

    std::vector<std::pair<float, float>> keyframes;
    keyframes.push_back(std::make_pair(0, 300));
    keyframes.push_back(std::make_pair(1.0, 500));
    keyframes.push_back(std::make_pair(2.0, 450));
    keyframes.push_back(std::make_pair(3.0, 300));

    int keyframeNo = manager.addKeyframeVariable(keyframes);

    while (!glfwWindowShouldClose(manager.getWindow())) {
        if (glfwGetKey(manager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(manager.getWindow(), true);
        }
        manager.drawFrame();
        LOG(4, "EditorMain", "Frame drawn.")

        LOG(3, "TEST", "Keyframe value: " + std::to_string(manager.keyframeGetVariable(keyframeNo)));
    }
    LOG(2, "EditorMain", "Exited rendering loop, closing program.")
    return 0; 
}
