#include "animFileParser.hpp"

Chronos::Animation::AnimNode Chronos::Animation::loadAnimTree(std::string path)
{
    std::ifstream file(path);
    std::string line;

    AnimNode* currentNode = nullptr;
    AnimNode root = AnimNode();

    std::map<std::string, AnimNode*> nodeMap; // from name to node
    bool insideShape = false;
    bool insideChildren = false;
    std::string currentShapeName;

    /*Scan the file line by line, validating and adding the necessary information to the
    relevant data structures*/
    while (std::getline(file, line)) {

        // line is starting a new shape
        if (!insideShape && line[line.size() - 1] == '{') {
            insideShape = true;

            std::string shapeName = line.substr(0, line.size() - 2);
            if (nodeMap.count(shapeName) > 0) {
                currentNode = nodeMap[shapeName];
            } else {
                if (currentNode == nullptr) {
                    currentNode = &root;
                } else {
                    throw std::runtime_error("Invalid file format");
                }
            }

            // line is type
        } else if (line.substr(0, 5) == "Type: " && insideShape && !insideChildren) {
            if (line[6] == 'T') {
                currentNode->polygonType.triangle = true;
            } else if (line[6] == 'R') {
                currentNode->polygonType.rectangle = true;
            } else {
                throw std::runtime_error("Invalid file format");
            }

            // line is texture path
        } else if (line.substr(0, 13) == "TexturePath: " && insideShape && !insideChildren) {
            currentNode->texturePath = line.substr(13, line.size() - 13);

            // line is shape attributes
        } else if (line[0] == '[' && line[line.size() - 1] == ']' && insideShape && !insideChildren) {
            std::string shapeAttributes = line.substr(1, line.size() - 2);
            std::vector<std::string> shapeAttributesVector;
            std::stringstream ss(shapeAttributes);
            std::string attribute;
            while (std::getline(ss, attribute, ',')) {
                shapeAttributesVector.push_back(attribute);
            }
            currentNode->defaultShapeParams.x = std::stof(shapeAttributesVector[0]);
            currentNode->defaultShapeParams.y = std::stof(shapeAttributesVector[1]);
            currentNode->defaultShapeParams.rotation = std::stof(shapeAttributesVector[2]);
            currentNode->defaultShapeParams.xSize = std::stof(shapeAttributesVector[3]);
            currentNode->defaultShapeParams.ySize = std::stof(shapeAttributesVector[4]);
            currentNode->defaultShapeParams.show = std::stoi(shapeAttributesVector[5]);

            // line is starting children nodes
        } else if (line[0] == '{' && insideShape && !insideChildren) {
            insideChildren = true;

            // line is a child node
        } else if (line[line.size() - 2] == ']' && line[line.size() - 1] == ',' && insideShape && insideChildren) {
            std::string childName = line.substr(0, line.find('[') - 1);
            float x = std::stof(line.substr(line.find('[') + 1, line.find(',') - 1));
            float y = std::stof(line.substr(line.find(',') + 1, line.find(']') - 1));
            AnimNode childNode = AnimNode();
            childNode.name = childName;
            childNode.x_rel = x;
            childNode.y_rel = y;
            currentNode->children.push_back(childNode);
            nodeMap[childName] = &currentNode->children[currentNode->children.size() - 1];

            // line is ending children nodes
        } else if (line[0] == '}' && insideShape && insideChildren) {
            insideChildren = false;

            // line is ending a shape
        } else if (line[0] == '}' && insideShape && !insideChildren) {
            insideShape = false;
            nodeMap[currentNode->name] = currentNode;

            // else something has gone wrong
        } else {
            throw std::runtime_error("Invalid file format");
        }
    }
    file.close();

    return root;
}

std::string convertAnimNodeToString(Chronos::Animation::AnimNode node)
{
    std::string nodeString = "";
    nodeString += node.name + "{\n";
    nodeString += "Type: ";
    if (node.polygonType.triangle) {
        nodeString += "Triangle\n";
    } else if (node.polygonType.rectangle) {
        nodeString += "Rectangle\n";
    } else {
        throw std::runtime_error("Invalid file format");
    }
    nodeString += "TexturePath: " + node.texturePath + "\n";
    nodeString += "[" + std::to_string(node.defaultShapeParams.x) + ", " + std::to_string(node.defaultShapeParams.y) + ", " + std::to_string(node.defaultShapeParams.rotation) + ", " + std::to_string(node.defaultShapeParams.xSize) + ", " + std::to_string(node.defaultShapeParams.ySize) + ", " + std::to_string(node.defaultShapeParams.show) + "]\n";
    if (node.children.size() > 0) {
        nodeString += "{\n";
        for (auto child : node.children) {
            nodeString += child.name + "[" + std::to_string(child.x_rel) + ", " + std::to_string(child.y_rel) + "],\n";
        }
        nodeString += "}\n";
    }
    nodeString += "}\n";

    return nodeString;
}

void Chronos::Animation::saveAnimTree(Chronos::Animation::AnimNode animTree, std::string path)
{
    std::ofstream file;
    file.open(path);

    AnimNode currentNode = animTree;
    std::vector<AnimNode> nodeStack;
    nodeStack.push_back(currentNode);
    while (nodeStack.size() > 0) {
        currentNode = nodeStack[nodeStack.size() - 1];
        nodeStack.pop_back();
        file << convertAnimNodeToString(currentNode);
        for (auto child : currentNode.children) {
            nodeStack.push_back(child);
        }
    }
    file.close();
}

std::map<std::string, std::vector<Chronos::Animation::AnimShapeAttributes>> Chronos::Animation::loadAnimFile(std::string path)
{
    std::ifstream file(path);
    std::string line;

    std::map<std::string, std::vector<AnimShapeAttributes>> animationMap;

    std::string currentShape;
    bool insideShape = false;
    /*Scan the file line by line, validating and adding the necessary information to the
    relevant data structures*/
    while (std::getline(file, line)) {
        if (!insideShape && line[line.size() - 1] == '{') {
            insideShape = true;
            std::string shapeName = line.substr(0, line.size() - 2);
            animationMap[shapeName] = std::vector<AnimShapeAttributes>();
            currentShape = shapeName;
        } else if (insideShape && line[0] == '[' && line[line.size() - 2] == ']') {
            AnimShapeAttributes shapeAttributes;
            std::string shapeAttributesString = line.substr(1, line.size() - 2);
            std::vector<std::string> shapeAttributesVector;
            std::stringstream ss(shapeAttributesString);
            std::string attribute;
            while (std::getline(ss, attribute, ',')) {
                shapeAttributesVector.push_back(attribute);
            }
            shapeAttributes.x = std::stof(shapeAttributesVector[0]);
            shapeAttributes.y = std::stof(shapeAttributesVector[1]);
            shapeAttributes.rotation = std::stof(shapeAttributesVector[2]);
            shapeAttributes.xSize = std::stof(shapeAttributesVector[3]);
            shapeAttributes.ySize = std::stof(shapeAttributesVector[4]);
            shapeAttributes.show = std::stoi(shapeAttributesVector[5]);
            animationMap[currentShape].push_back(shapeAttributes);
        } else if (insideShape && line[0] == '}') {
            insideShape = false;
        } else {
            throw std::runtime_error("Invalid file format");
        }
    }
    file.close();
    return animationMap;
}

void Chronos::Animation::saveAnimFile(std::map<std::string, std::vector<Chronos::Animation::AnimShapeAttributes>> animation, std::string path)
{
    std::ofstream file;
    file.open(path);

    for (auto shape : animation) {
        file << shape.first << "{\n";
        for (auto shapeAttributes : shape.second) {
            file << "[" << shapeAttributes.x << ", " << shapeAttributes.y << ", " << shapeAttributes.rotation << ", " << shapeAttributes.xSize << ", " << shapeAttributes.ySize << ", " << shapeAttributes.show << "]\n";
        }
        file << "}\n";
    }
    file.close();
}