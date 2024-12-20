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
#include "ColoredRectangle.hpp"
#include "TexturedRectangle.hpp"
int Chronos::Manager::Manager::addShape(Chronos::Manager::ShapeParams shapeParams){
    Chronos::Engine::ColoredRectangle* shape = new Chronos::Engine::ColoredRectangle();
    shape->params = shapeParams;
    shape->init(&this->engine.device, this->engine.commandPool, &(this->engine.swapChain), this->engine.objectManager.textureSampler, &this->engine.objectManager.renderPass);
    return engine.objectManager.addObject(shape);
}

int Chronos::Manager::Manager::addShape(Chronos::Manager::ShapeParams shapeParams,  int texture){
    Chronos::Engine::TexturedRectangle* shape = new Chronos::Engine::TexturedRectangle();
    shape->params = shapeParams;
    shape->init(&this->engine.device, this->engine.commandPool, &(this->engine.swapChain), this->engine.objectManager.textureSampler, this->engine.textureManager.textures[texture], &this->engine.objectManager.renderPass);
    return engine.objectManager.addObject(shape);
}

std::vector<std::pair<int, Chronos::Manager::ShapeParams>> Chronos::Manager::Manager::getShapeDetails(){
    std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails;
    for(auto const& [objectNo, object] : engine.objectManager.objects){
        if(object->objectType == Chronos::Engine::ObjectType::TypeColoredRectangle){
            Chronos::Engine::ColoredRectangle* shape = (Chronos::Engine::ColoredRectangle*)object;
            shapeDetails.push_back(std::make_pair(objectNo, shape->params));
        }
        else if(object->objectType == Chronos::Engine::ObjectType::TypeTexturedRectangle){
            Chronos::Engine::TexturedRectangle* shape = (Chronos::Engine::TexturedRectangle*)object;
            shapeDetails.push_back(std::make_pair(objectNo, shape->params));
        }
    }
    return shapeDetails;
}
void Chronos::Manager::Manager::updateShape(int objectNo, Chronos::Manager::ShapeParams shapeParams){
    if(engine.objectManager.objects.count(objectNo) == 0){
        throw std::runtime_error("Shape does not exist");
    }
    if(engine.objectManager.objects[objectNo]->objectType != Chronos::Engine::ObjectType::TypeColoredRectangle && engine.objectManager.objects[objectNo]->objectType != Chronos::Engine::ObjectType::TypeTexturedRectangle){
        throw std::runtime_error("Object is not a shape object");
    }
    if(engine.objectManager.objects[objectNo]->objectType == Chronos::Engine::ObjectType::TypeColoredRectangle){
        Chronos::Engine::ColoredRectangle* shape = (Chronos::Engine::ColoredRectangle*)engine.objectManager.objects[objectNo];
        shape->params = shapeParams;
    }
    else if(engine.objectManager.objects[objectNo]->objectType == Chronos::Engine::ObjectType::TypeTexturedRectangle){
        Chronos::Engine::TexturedRectangle* shape = (Chronos::Engine::TexturedRectangle*)engine.objectManager.objects[objectNo];
        shape->params = shapeParams;
    }
}