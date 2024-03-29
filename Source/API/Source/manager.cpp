#include "chronos.hpp"
// #include "text.hpp"
#include "object.hpp"
#include "fontTypes.hpp"

namespace Chronos {
GLFWwindow* Manager::Manager::getWindow()
{
    return engine.window;
}
Manager::Manager::Manager(Chronos::Manager::Initializer initializer)
{
    if (initializer.BackgroundColor[0] < 0 || initializer.BackgroundColor[0] > 1 || initializer.BackgroundColor[1] < 0 || initializer.BackgroundColor[1] > 1 || initializer.BackgroundColor[2] < 0 || initializer.BackgroundColor[2] > 1) {
        throw std::runtime_error("Invalid background color");
    }
    engine.bgColor[0] = initializer.BackgroundColor[0];
    engine.bgColor[1] = initializer.BackgroundColor[1];
    engine.bgColor[2] = initializer.BackgroundColor[2];

    if (initializer.WindowWidth <= 0 || initializer.WindowHeight <= 0) {
        throw std::runtime_error("Invalid window size");
    }
    engine.width = initializer.WindowWidth;
    engine.height = initializer.WindowHeight;
    #ifdef ENABLE_EDITOR
    engine.setEditorAddElementsCallback(initializer.editorAddElements);
    #endif
}
void Manager::Manager::drawFrame()
{

    engine.drawFrame();
}
int Manager::Manager::changeBackgroundColor(float r, float g, float b)
{
    if (r < 0 || r > 1 || g < 0 || g > 1 || b < 0 || b > 1) {
        throw std::runtime_error("Invalid background color");
    }
    engine.bgColor[0] = r;
    engine.bgColor[1] = g;
    engine.bgColor[2] = b;
    return 0;
}

int Manager::Manager::addPolygon(Chronos::Manager::ShapeParams shapeParams, Chronos::Manager::PolygonType polygonType, int texture)
{   
    int shapeNo;
    if (polygonType.triangle) {
        shapeNo = engine.shapeManager.addTriangle(shapeParams, engine.textureManager.getTexture(texture));
    } else if (polygonType.rectangle) {
        shapeNo =  engine.shapeManager.addRectangle(shapeParams, engine.textureManager.getTexture(texture));
    } else if(polygonType.npolygon){
        throw std::runtime_error("Please use vertices and use other override for this type of polygon.");
    } else {
        throw std::runtime_error("Polygon type not supported");
    }
    shapeNo = std::stoi("1" + std::to_string(shapeNo));
    return shapeNo;
}

int Manager::Manager::addPolygon(Chronos::Manager::ShapeParams shapeParams, Chronos::Manager::PolygonType polygonType, int texture, 
    std::vector<std::array<float, 2>> vertices)
{   
    int shapeNo;
    if (polygonType.triangle) {
        throw std::runtime_error("Please do not use vertices and use other override for this type of polygon.");
    } else if (polygonType.rectangle) {
        throw std::runtime_error("Please do not use vertices and use other override for this type of polygon.");
    } else if(polygonType.npolygon){
        shapeNo = engine.polygonManager.addPolygon(shapeParams, vertices, engine.textureManager.getTexture(texture));
    }else {
        throw std::runtime_error("Polygon type not supported");
    }
    shapeNo = std::stoi("3" + std::to_string(shapeNo));
    return shapeNo;
}


int Manager::Manager::addPolygon(Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType)
{   
    int shapeNo;
    if (polygonType.triangle) {
        shapeNo = engine.colorShapeManager.addTriangle(shapeParams);
    } else if (polygonType.rectangle) {
        shapeNo = engine.colorShapeManager.addRectangle(shapeParams);
    } else {
        throw std::runtime_error("Polygon type not supported");
    }
    shapeNo = std::stoi("2" + std::to_string(shapeNo));

    return shapeNo;
}
void Manager::Manager::updatePolygon(int shapeNo, Chronos::Manager::ShapeParams shapeParams)
{   
    if (std::to_string(shapeNo).substr(0, 1) == "1") {
        int actualShapeNo = shapeNo - 1*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.shapeManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.shapeManager.objects[actualShapeNo].params = shapeParams;
    } else if (std::to_string(shapeNo).substr(0, 1) == "3") {
        int actualShapeNo = shapeNo - 3*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.polygonManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.polygonManager.objects[actualShapeNo].params = shapeParams;
    }  else if (std::to_string(shapeNo).substr(0, 1) == "2") {
        int actualShapeNo = shapeNo - 2*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.colorShapeManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.colorShapeManager.objects[actualShapeNo].params = shapeParams;
    } else {
        throw std::runtime_error("Shape does not exist");
    }
}

void Manager::Manager::updatePolygon(int shapeNo, Chronos::Manager::ShapeParams shapeParams, std::vector<std::array<float, 2>> vertices)
{   
    if (std::to_string(shapeNo).substr(0, 1) == "3") {
        int actualShapeNo = shapeNo - 3*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.polygonManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.polygonManager.objects[actualShapeNo].params = shapeParams;
        engine.polygonManager.objects[actualShapeNo].updateVertices(vertices);
    } else {
        throw std::runtime_error("Shape does not exist");
    }
}

std::vector<std::pair<int, Chronos::Manager::ShapeParams>> Manager::Manager::getShapeDetails(){
    std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails;
    for (auto& shape : engine.shapeManager.objects)
    {
        std::pair<int, Chronos::Manager::ShapeParams> shapeDetail;
        shapeDetail.first = shape.first;
        shapeDetail.second = shape.second.params;
        shapeDetails.push_back(shapeDetail);
    }
    for(auto& shape : engine.colorShapeManager.objects){
        std::pair<int, Chronos::Manager::ShapeParams> shapeDetail;
        shapeDetail.first = shape.first;
        shapeDetail.second = shape.second.params;
        shapeDetails.push_back(shapeDetail);
    }
    return shapeDetails;
}
std::vector<std::pair<int, Chronos::Manager::ShapeParams>> Manager::Manager::getPolygonDetails(){
    std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails;
    for (auto& shape : engine.polygonManager.objects)
    {
        std::pair<int, Chronos::Manager::ShapeParams> shapeDetail;
        shapeDetail.first = shape.first;
        shapeDetail.second = shape.second.params;
        shapeDetails.push_back(shapeDetail);
    }
    return shapeDetails;
}


void Manager::Manager::removePolygon(int shapeNo)
{   
    if (std::to_string(shapeNo).substr(0, 1) == "1") {
        int actualShapeNo = shapeNo - 1*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.shapeManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.shapeManager.remove(actualShapeNo);
    } else if (std::to_string(shapeNo).substr(0, 1) == "2") {
        int actualShapeNo = shapeNo - 2*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.colorShapeManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.colorShapeManager.remove(actualShapeNo);
    } else if (std::to_string(shapeNo).substr(0, 1) == "3") {
        int actualShapeNo = shapeNo - 3*(10*(std::to_string(shapeNo).size() - 1));
        if (engine.polygonManager.objects.count(actualShapeNo) == 0) {
            throw std::runtime_error("Shape does not exist");
        }
        engine.polygonManager.remove(actualShapeNo);
    } else {
        throw std::runtime_error("Shape does not exist");
    }
}
int Manager::Manager::addText(Chronos::Engine::TextParams params)
{
    if (params.text == "") {
        throw std::runtime_error("Text cannot be empty");
    }
    // Chronos::Engine::Text font;
    Chronos::Engine::Text font;
    font.params = params;
    Chronos::Engine::FontTypes fontStyle = Chronos::Engine::FontStructs::consolas_24;
    return engine.textManager.addFont(font, fontStyle);
}

void Manager::Manager::updateText(int textNo, Chronos::Engine::TextParams params)
{   
    if (params.text == "") {
        throw std::runtime_error("Text cannot be empty");
    }
    if(engine.textManager.objects.count(textNo) == 0) {
        throw std::runtime_error("Text does not exist");
    }
    engine.textManager.objects[textNo].params = params;
}

void Manager::Manager::removeText(int textNo)
{

    engine.textManager.remove(textNo);
}

int Manager::Manager::addTexture(std::string texturePath, std::string textureName)
{
    return engine.textureManager.addTexture(texturePath, textureName);
}
void Manager::Manager::removeTexture(int textureNo)
{
    engine.textureManager.removeTexture(textureNo);
}

std::vector <Chronos::Manager::TextureDetails> Manager::Manager::getTextureDetails()
{
    std::vector<Chronos::Manager::TextureDetails> textureDetails;
    for (auto& texture : engine.textureManager.textures)
    {
        Chronos::Manager::TextureDetails details;
        details.textureNo = texture.first;
        details.textureName = texture.second.textureName;
        details.texturePath = texture.second.texturePath;
        textureDetails.push_back(details);
    }
    return textureDetails;

}

std::vector<std::pair<int, Chronos::Engine::TextParams>> Manager::Manager::getTextDetails(){
    std::vector<std::pair<int, Chronos::Engine::TextParams>> textDetails;
    for (auto& text : engine.textManager.objects)
    {
        std::pair<int, Chronos::Engine::TextParams> textDetail;
        textDetail.first = text.first;
        textDetail.second = text.second.params;
        textDetails.push_back(textDetail);
    }
    return textDetails;
}

};

