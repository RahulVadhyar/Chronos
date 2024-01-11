#include "animData.hpp"
/*
We need to load and write animation files. It will have the extension ".anim".
An example of such a file will be:

shape1{
    Type:Rectangle
    Child:[shape2, shape3, shape4]
    #xValues, yValues, rotation, xSize, ySize, show
    1:[0, 0, 0, 0.5, 0.5, true]
    2:[0.1, -0.32, 0, 0.5, 0.5, true]
    3:[0.1, -0.32, 0, 0.5, 0.5, true]
    4:[0.1, -0.32, 0, 0.5, 0.5, true]
}

shape2{
    Type:Triangle
    Child:[]
    #xValues, yValues, rotation, xSize, ySize, show
    1:[0, 0, 0, 0.5, 0.5, true]
    2:[0.1, -0.32, 0, 0.5, 0.5, true]
    3:[0.1, -0.32, 0, 0.5, 0.5, true]
    4:[0.1, -0.32, 0, 0.5, 0.5, true]
}

shape3{
    Type:Triangle
    Child:[]
    #xValues, yValues, rotation, xSize, ySize, show
    1:[0, 0, 0, 0.5, 0.5, true]
    2:[0.1, -0.32, 0, 0.5, 0.5, true]
    3:[0.1, -0.32, 0, 0.5, 0.5, true]
    4:[0.1, -0.32, 0, 0.5, 0.5, true]
}
shape4{
    Type:Triangle
    Child:[]
    #xValues, yValues, rotation, xSize, ySize, show
    1:[0, 0, 0, 0.5, 0.5, true]
    2:[0.1, -0.32, 0, 0.5, 0.5, true]
    3:[0.1, -0.32, 0, 0.5, 0.5, true]
    4:[0.1, -0.32, 0, 0.5, 0.5, true]
}
The way this format works is that we have multiple shapes. Each shape has the following details:
Type: The type of shape. This can be either "Rectangle" or "Triangle"   
Child: The children of the shape. These are the shapes that are the children of parent. If the parent moves, the children move with it.
'#' denotes comment
1:[0, 0, 0, 0.5, 0.5, true]
This is a frame of animation. The 1 is the frame number.
In the array has the following values:
xValues: The x values of the shape
yValues: The y values of the shape
rotation: The rotation of the shape
xSize: The x size of the shape
ySize: The y size of the shape
show: Whether the shape is shown or not at that particular time
**NOTE** The above values are relative. They will be applied relative to the current value of the attribute in question.
For example:
suppose that the current xValue of the shape is 0.4. Now if the next frame has value -0.1, then at the next frame the xValue will be 0.3.

As we can see this is a simple format. We will need to parse this file and create a tree of AnimationData objects.
The structs are
struct AnimationShapeAttributes{
    float x;
    float y;
    float rotation;
    float xSize;
    float ySize;
    float show;
};

struct AnimationData{
    std::string name;
    std::vector<AnimationData> children;
    std::vector<AnimationShapeAttributes> shapeAttributes;
};
*/

// Function to parse the shape attributes from a line
Chronos::Animation::AnimationShapeAttributes parseShapeAttributes(const std::string& line) {
    Chronos::Animation::AnimationShapeAttributes attributes;
    std::istringstream ss(line);
    char dummy; // to consume the leading '#'
    ss >> dummy >> attributes.x >> dummy >> attributes.y >> dummy >> attributes.rotation
       >> dummy >> attributes.xSize >> dummy >> attributes.ySize >> dummy >> std::boolalpha >> attributes.show;
    return attributes;
}

// Function to parse the animation data from the file
Chronos::Animation::AnimationData parseAnimationData(std::ifstream& file) {
    Chronos::Animation::AnimationData animationData;
    std::string line;

    // Read the shape name
    std::getline(file, line);
    animationData.name = line.substr(0, line.find('{'));

    while (std::getline(file, line) && line.find('}') == std::string::npos) {
        // Check if the line contains the "Child" field
        if (line.find("Child:") != std::string::npos) {
            // Read child shapes
            while (std::getline(file, line) && line.find(']') == std::string::npos) {
                Chronos::Animation::AnimationData childData = parseAnimationData(file);
                animationData.children.push_back(childData);
            }
        } else if (line.find('#') != std::string::npos) {
            // Read shape attributes
            Chronos::Animation::AnimationShapeAttributes attributes = parseShapeAttributes(line);
            animationData.shapeAttributes.push_back(attributes);
        }
    }

    return animationData;
}

Chronos::Animation::AnimationData Chronos::Animation::loadAnimationData(std::string path){
    std::ifstream file(path);

    if (!file.is_open()) {
        throw std::runtime_error("Failed to open animation file: " + path);
    }

    Chronos::Animation::AnimationData data = parseAnimationData(file);
    file.close();
    return data;
}

void Chronos::Animation::writeAnimationData(const AnimationData& data, const std::string& path) {
    // Open the file for writing
    std::ofstream file(path);

    // Check if the file is open
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open animation file for writing: " + path);
    }

    // Write the animation data to the file
    file << "Name: " << data.name << " {\n";

    for (const auto& child : data.children) {
        file << "Child: [\n";
        writeAnimationData(child, path);
        file << "]\n";
    }

    for (const auto& attribute : data.shapeAttributes) {
        file << "# " << attribute.name << " " << attribute.value << "\n";
    }

    file << "}\n";

    // Close the file
    file.close();
}