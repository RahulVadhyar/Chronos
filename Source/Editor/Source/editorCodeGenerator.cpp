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
#include "chronos.hpp"
#include "editorCodeGenerator.hpp"

std::string Chronos::Editor::generateCode(Chronos::Manager::Manager* manager){
    //generate code for initalizer, textured shape, colored shape, polygons, textures
    std::string code = ""
    "#include \"chronos.hpp\"\n"
    "Chronos::Manager::Initializer initializer;\n"
    "initializer.WindowWidth = 800;\n"
    "initializer.WindowHeight = 600;\n"
    "initializer.BackgroundColor[0] = 0;\n"
    "initializer.BackgroundColor[1] = 0;\n"
    "initializer.BackgroundColor[2] = 0;\n"

    "Chronos::Manager::Manager manager(initializer);\n"
    "//texture\n"
    "//textured shapes\n"
    
    "//colored shapes\n"

    "//polygons\n"

    "settings\n"

    "while (!glfwWindowShouldClose(manager.getWindow())) {\n"
        "if (glfwGetKey(manager.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS) {\n"
            "glfwSetWindowShouldClose(manager.getWindow(), true);\n"
        "}\n"
        "manager.drawFrame();\n"
    "}\n ";
    return code;
}