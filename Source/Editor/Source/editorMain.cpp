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

void addElements()
{
    editorManager.addElements();
}

int main()
{
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

    // Chronos::Manager::ShapeParams shapeParams;
    // shapeParams.color = {1.0f, 1.0f, 1.0f};
    // shapeParams.xSize = 0.5f;
    // shapeParams.ySize = 0.5f;
    // int shapeNo = manager.addPolygon(shapeParams, {false, true});

    // int keyframeNo = manager.addKeyframeVariable({{0, 0}, {400, 0.1}, {800, 0.5}, {1200, 0.4}, {1600, 0.2}});

    while (!glfwWindowShouldClose(manager.getWindow())) {
        if (glfwGetKey(manager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(manager.getWindow(), true);
        }
        // shapeParams.x = manager.keyframeGetVariable(keyframeNo);
        // manager.updatePolygon(shapeNo, shapeParams);
        manager.drawFrame();
        LOG(4, "EditorMain", "Frame drawn.")
    }
    LOG(2, "EditorMain", "Exited rendering loop, closing program.")
    return 0;
}
