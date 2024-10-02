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

int Chronos::Manager::Manager::addPolygon(
    Chronos::Manager::ShapeParams shapeParams,
    Chronos::Manager::PolygonType polygonType, int texture)
{
    // this function is for textured triangles and rectangles only
    // we need to add a check for the texture
    std::vector<Chronos::Manager::TextureDetails> textureDetails
	= getTextureDetails();
    bool textureExists = false;
    for (auto& textureDetail : textureDetails) {
	if (textureDetail.textureNo == texture) {
	    textureExists = true;
	    break;
	}
    }
    if (!textureExists) {
	throw std::runtime_error("Texture does not exist");
    }

    // check whether shape name exists
    for (auto& shape : engine.shapeManager.objects) {
	if (strcmp(shape.second.params.shapeName, shapeParams.shapeName) == 0) {
	    throw std::runtime_error("Shape name already exists");
	}
    }
    int shapeNo;
    if (polygonType.triangle) {
	shapeNo = engine.shapeManager.addTriangle(
	    shapeParams, engine.textureManager.getTexture(texture));
    } else if (polygonType.rectangle) {
	shapeNo = engine.shapeManager.addRectangle(
	    shapeParams, engine.textureManager.getTexture(texture));
    } else {
	throw std::runtime_error("Polygon type not supported");
    }

    // we add 1 to shapeNo to know they are textured triangles or rectangles
    shapeNo = std::stoi("1" + std::to_string(shapeNo));
    return shapeNo;
}

int Chronos::Manager::Manager::addPolygon(
    Chronos::Manager::ShapeParams shapeParams, int texture,
    std::vector<std::array<float, 2>> vertices)
{

    // this fucntion is for npolygons only
    int shapeNo;

    // check to make sure the texture exists
    std::vector<Chronos::Manager::TextureDetails> textureDetails
	= getTextureDetails();
    bool textureExists = false;
    for (auto& textureDetail : textureDetails) {
	if (textureDetail.textureNo == texture) {
	    textureExists = true;
	    break;
	}
    }
    if (!textureExists) {
	throw std::runtime_error("Texture does not exist");
    }

    // check whether shape name exists
    for (auto& shape : engine.shapeManager.objects) {
	if (strcmp(shape.second.params.shapeName, shapeParams.shapeName) == 0) {
	    throw std::runtime_error("Shape name already exists");
	}
    }
    if (!textureExists) {
	throw std::runtime_error("Texture does not exist");
    }
    shapeNo = engine.polygonManager.addPolygon(
	shapeParams, vertices, engine.textureManager.getTexture(texture));

    // we add 3 to shapeNo to know they are textured npolygons
    shapeNo = std::stoi("3" + std::to_string(shapeNo));
    return shapeNo;
}

int Chronos::Manager::Manager::addPolygon(
    Chronos::Manager::ShapeParams shapeParams, PolygonType polygonType)
{
    // this function is for colored triangles and rectangles only
    // check whether shape name exists
    for (auto& shape : engine.shapeManager.objects) {
	if (strcmp(shape.second.params.shapeName, shapeParams.shapeName) == 0) {
	    throw std::runtime_error("Shape name already exists");
	}
    }
    int shapeNo;
    if (polygonType.triangle) {
	shapeNo = engine.colorShapeManager.addTriangle(shapeParams);
    } else if (polygonType.rectangle) {
	shapeNo = engine.colorShapeManager.addRectangle(shapeParams);
    } else {
	throw std::runtime_error("Polygon type not supported");
    }

    // we add 2 to shapeNo to know they are colored triangles or rectangles
    shapeNo = std::stoi("2" + std::to_string(shapeNo));

    return shapeNo;
}
void Chronos::Manager::Manager::updatePolygon(
    int shapeNo, Chronos::Manager::ShapeParams shapeParams)
{
    if (std::to_string(shapeNo).substr(0, 1)
	== "1") { // textured triangles and rectangles
	int actualShapeNo
	    = shapeNo - 1 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.shapeManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.shapeManager.objects[actualShapeNo].params = shapeParams;
    } else if (std::to_string(shapeNo).substr(0, 1)
	== "3") { // textured npolygons
	int actualShapeNo
	    = shapeNo - 3 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.polygonManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.polygonManager.objects[actualShapeNo].params = shapeParams;
    } else if (std::to_string(shapeNo).substr(0, 1)
	== "2") { // colored triangles and rectangles
	int actualShapeNo
	    = shapeNo - 2 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.colorShapeManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.colorShapeManager.objects[actualShapeNo].params = shapeParams;
    } else {
	throw std::runtime_error("Shape does not exist");
    }
}

void Chronos::Manager::Manager::updatePolygon(int shapeNo,
    Chronos::Manager::ShapeParams shapeParams,
    std::vector<std::array<float, 2>> vertices)
{
    if (std::to_string(shapeNo).substr(0, 1) == "3") { // textured npolygons
	int actualShapeNo
	    = shapeNo - 3 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.polygonManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.polygonManager.objects[actualShapeNo].params = shapeParams;
	engine.polygonManager.objects[actualShapeNo].updateVertices(vertices);
    } else {
	throw std::runtime_error("Shape does not exist");
    }
}

std::vector<std::pair<int, Chronos::Manager::ShapeParams>>
Chronos::Manager::Manager::getShapeDetails()
{
    std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails;
    // we need both colored and textured triangles and rectangles
    for (auto& shape : engine.shapeManager.objects) {
	std::pair<int, Chronos::Manager::ShapeParams> shapeDetail;
	shapeDetail.first = std::stoi("1" + std::to_string(shape.first));
	shapeDetail.second = shape.second.params;
	shapeDetails.push_back(shapeDetail);
    }
    for (auto& shape : engine.colorShapeManager.objects) {
	std::pair<int, Chronos::Manager::ShapeParams> shapeDetail;
	shapeDetail.first = std::stoi("2" + std::to_string(shape.first));
	shapeDetail.second = shape.second.params;
	shapeDetails.push_back(shapeDetail);
    }
    return shapeDetails;
}
std::vector<std::pair<int, Chronos::Manager::ShapeParams>>
Chronos::Manager::Manager::getPolygonDetails()
{

    // get the details of the npolygons
    std::vector<std::pair<int, Chronos::Manager::ShapeParams>> shapeDetails;
    for (auto& shape : engine.polygonManager.objects) {
	std::pair<int, Chronos::Manager::ShapeParams> shapeDetail;
	shapeDetail.first = std::stoi("3" + std::to_string(shape.first));
	shapeDetail.second = shape.second.params;
	shapeDetails.push_back(shapeDetail);
    }
    return shapeDetails;
}

std::vector<std::array<float, 2>> Chronos::Manager::Manager::getPolygonVertices(
    int polygonNo)
{
    if (std::to_string(polygonNo).substr(0, 1) == "3") { // textured npolygons
	int actualPolygonNo
	    = polygonNo - 3 * (10 * (std::to_string(polygonNo).size() - 1));
	if (engine.polygonManager.objects.count(actualPolygonNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	std::vector<Chronos::Engine::TexturedVertex> texturedVertices
	    = engine.polygonManager.objects[actualPolygonNo].vertices;
	std::vector<std::array<float, 2>> vertices;
	for (Chronos::Engine::TexturedVertex vertex : texturedVertices) {
	    vertices.push_back({ vertex.pos[0], vertex.pos[1] });
	}
	return vertices;
    } else {
	throw std::runtime_error("Shape does not exist");
    }
}

void Chronos::Manager::Manager::removePolygon(int shapeNo)
{
    if (std::to_string(shapeNo).substr(0, 1)
	== "1") { // textured triangles and rectangles
	int actualShapeNo
	    = shapeNo - 1 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.shapeManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.shapeManager.remove(actualShapeNo);
    } else if (std::to_string(shapeNo).substr(0, 1)
	== "2") { // colored triangles and rectangles
	int actualShapeNo
	    = shapeNo - 2 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.colorShapeManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.colorShapeManager.remove(actualShapeNo);
    } else if (std::to_string(shapeNo).substr(0, 1)
	== "3") { // textured npolygons
	int actualShapeNo
	    = shapeNo - 3 * (10 * (std::to_string(shapeNo).size() - 1));
	if (engine.polygonManager.objects.count(actualShapeNo) == 0) {
	    throw std::runtime_error("Shape does not exist");
	}
	engine.polygonManager.remove(actualShapeNo);
    } else {
	throw std::runtime_error("Shape does not exist");
    }
}
