#include "chronos.hpp"
// #include "text.hpp"
#include "object.hpp"
#include "objectManagerDefs.hpp"


namespace Chronos {
GLFWwindow* Manager::Manager::getWindow()
{
    return engine.window;
}
Manager::Manager::Manager(Chronos::Manager::Initializer initializer)
{   
    engine.width = initializer.WindowWidth;
    engine.height = initializer.WindowHeight;
}
void Manager::Manager::drawFrame()
{

    engine.drawFrame();
}
int Manager::Manager::changeBackgroundColor(float r, float g, float b)
{
    if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1) {
        return -1;
    }
    engine.bgColor[0] = r;
    engine.bgColor[1] = g;
    engine.bgColor[2] = b;
    return 0;
}

int Manager::Manager::addPolygon(Chronos::Engine::ShapeParams shapeParams, Chronos::Manager::PolygonType polygonType, std::string texturePath)
{
    if (polygonType.triangle) {
        return engine.shapeManager.addTriangle(shapeParams, texturePath);
    } else if (polygonType.rectangle) {
        return engine.shapeManager.addRectangle(shapeParams, texturePath);
    }
    return 0;
}
int Manager::Manager::updatePolygon(int shapeNo, Chronos::Engine::ShapeParams shapeParams)
{
    if (engine.shapeManager.objects.count(shapeNo) == 0) {
        return -1;
    }
    engine.shapeManager.objects[shapeNo].params = shapeParams;
    return 0;
}
void Manager::Manager::removePolygon(int shapeNo)
{
    if (engine.shapeManager.objects.count(shapeNo) > 0) {
        engine.shapeManager.remove(shapeNo);
    }
}
int Manager::Manager::addText(Chronos::Manager::Text text)
{
    int fontNo = engine.textManager.addFont(Chronos::Engine::Font());
    engine.textManager.objects[fontNo].addText(text.text, text.x, text.y);
    return fontNo;
}
void Manager::Manager::removeText(int textNo)
{
    
}

// int Manager::Manager::createAnimObject(int shapeNo){
//     if(engine.shapeManager.objects.count(shapeNo) == 0){
//         throw std::runtime_error("Shape does not exist");
//     }
//     int animObjNo = nextFreeAnimObjNo;
//     nextFreeAnimObjNo++;
//     Shape* shape = &engine.shapeManager.objects[shapeNo];
//     Chronos::Animation::AnimObject animObject(shapeNo, animObjNo, shape);
//     animObject.animObjNo = animObjNo;
//     animObjects[animObjNo] = animObject;
//     return animObjNo;
// }

// void Manager::Manager::deleteAnimObject(int animObjNo){
//     if(animObjects.count(animObjNo) == 0){
//         throw std::runtime_error("AnimObject does not exist");
//     }
//     //TODO: remove the animObject from its parent's children
//     animObjects.erase(animObjNo);
// }

// void Manager::Manager::makeAnimObjectChild(int parentAnimObjNo, int childAnimObjNo){
//     if(animObjects.count(parentAnimObjNo) == 0){
//         throw std::runtime_error("Parent AnimObject does not exist");
//     }
//     if(animObjects.count(childAnimObjNo) == 0){
//         throw std::runtime_error("Child AnimObject does not exist");
//     }
//     Chronos::Animation::AnimObject* parent = &animObjects[parentAnimObjNo];
//     Chronos::Animation::AnimObject* child = &animObjects[childAnimObjNo];
//     parent->addChild(child);
// }

// void Manager::Manager::removeAnimObjectChild(int parentAnimObjNo, int childAnimObjNo){
//     if(animObjects.count(parentAnimObjNo) == 0){
//         throw std::runtime_error("Parent AnimObject does not exist");
//     }
//     if(animObjects.count(childAnimObjNo) == 0){
//         throw std::runtime_error("Child AnimObject does not exist");
//     }
//     Chronos::Animation::AnimObject* parent = &animObjects[parentAnimObjNo];
//     Chronos::Animation::AnimObject* child = &animObjects[childAnimObjNo];
//     parent->removeChild(child);
// }

};