#include "gtest/gtest.h"
#include "chronos.hpp"

class ShapeAPITest : public testing::Test {
protected:
    
    Chronos::Manager::Manager* manager = nullptr;
    bool cleanup = true;
    void SetUp() override{
        Chronos::Manager::Initializer initializer = {800, 600, {0, 0, 0}};
        //Due to the multiprocess nature of google tests, we cannot delete this, else tests will fail when run together.
        //This is a memory leak. But since these are tests, it is considered to be acceptable, since freeing this memory and will be freed on process exit/destruction
        //is not part of the tests
        manager = new Chronos::Manager::Manager(initializer); 
    }
};

TEST_F(ShapeAPITest, isWorking){

    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams rectangleParams;
    rectangleParams.x = -0.5;
    rectangleParams.y = -0.5;
    rectangleParams.xSize = 0.5;
    rectangleParams.ySize = 0.5;
    rectangleParams.rotation = 0;
    Chronos::Manager::PolygonType rectangleType;
    rectangleType.rectangle = true;
    int rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 1);
}

TEST_F(ShapeAPITest, multipleShapesDifferentType){

    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams rectangleParams;
    rectangleParams.x = -0.5;
    rectangleParams.y = -0.5;
    rectangleParams.xSize = 0.5;
    rectangleParams.ySize = 0.5;
    rectangleParams.rotation = 0;
    Chronos::Manager::PolygonType rectangleType;
    rectangleType.rectangle = true;
    int rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 1);


    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 2);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 3);


    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 4);


    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 5);
}

TEST_F(ShapeAPITest, multipleShapesSameTypeTriangle){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 1);

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 2);

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 3);

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 4);

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 5);

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 6);
}
TEST_F(ShapeAPITest, multipleShapeSameTypeRectangle){

    Chronos::Manager::ShapeParams rectangleParams;
    rectangleParams.x = -0.5;
    rectangleParams.y = -0.5;
    rectangleParams.xSize = 0.5;
    rectangleParams.ySize = 0.5;
    rectangleParams.rotation = 0;
    Chronos::Manager::PolygonType rectangleType;
    rectangleType.rectangle = true;

    int rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 0);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 1);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 2);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 3);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 4);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 5);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 6);

}


TEST_F(ShapeAPITest, incompatibleTextureType1){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.jp"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType2){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pn"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType3){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjp"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType4){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjpg"), std::runtime_error);
}


TEST_F(ShapeAPITest, incompatibleTextureType5){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpgpng"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType6){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjpg"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType7){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/.pngjpg"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType8){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjpg.png"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType9){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture"), std::runtime_error);
}

TEST_F(ShapeAPITest, incompatibleTextureType11){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_ANY_THROW(manager->addPolygon(triangleParams, triangleType, nullptr));
}

TEST_F(ShapeAPITest, multipleShapesDifferentTypeDifferentTexture){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams rectangleParams;
    rectangleParams.x = -0.5;
    rectangleParams.y = -0.5;
    rectangleParams.xSize = 0.5;
    rectangleParams.ySize = 0.5;
    rectangleParams.rotation = 0;
    Chronos::Manager::PolygonType rectangleType;
    rectangleType.rectangle = true;
    int rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture.jpg");
    EXPECT_EQ(rectangle, 1);


    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture2.jpg");
    EXPECT_EQ(rectangle, 2);

    rectangle = manager->addPolygon(rectangleParams, rectangleType, "Assets/texture3.png");
    EXPECT_EQ(rectangle, 3);


    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture2.jpg");
    EXPECT_EQ(triangle, 4);


    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture3.png");
    EXPECT_EQ(triangle, 5);
}

TEST_F(ShapeAPITest, paramsIsNull){
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    Chronos::Manager::ShapeParams triangleParams = (Chronos::Manager::ShapeParams)NULL;
    EXPECT_EQ(manager->addPolygon((Chronos::Manager::ShapeParams)NULL, triangleType, "Assets/texture3.png"), 0);
}

TEST_F(ShapeAPITest, polygonTypeIsNotSet){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;

    Chronos::Manager::PolygonType triangleType = (Chronos::Manager::PolygonType)NULL;
    EXPECT_THROW(manager->addPolygon(triangleParams, (Chronos::Manager::PolygonType)NULL, "Assets/texture3.png"), std::runtime_error);
}

TEST_F(ShapeAPITest, bothParamsAndPolygonTypeIsNotSet){
    cleanup = false;
    EXPECT_THROW(manager->addPolygon((Chronos::Manager::ShapeParams)NULL, (Chronos::Manager::PolygonType)NULL, "Assets/texture3.png"), std::runtime_error);
}

TEST_F(ShapeAPITest, allArgsIsNullptr){
    cleanup = false;
    EXPECT_THROW(manager->addPolygon((Chronos::Manager::ShapeParams)NULL, (Chronos::Manager::PolygonType)NULL, ""), std::runtime_error);
}

TEST_F(ShapeAPITest, removeShape){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    EXPECT_NO_THROW(manager->removePolygon(triangle));
}
TEST_F(ShapeAPITest, removeShapeWrongIndex){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    EXPECT_THROW(manager->removePolygon(1), std::runtime_error);
}
TEST_F(ShapeAPITest, removeShapeAfterUpdate){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 1.0;
    triangleParams.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = 0.5;
    triangleParams2.y = 0.5;
    triangleParams2.xSize = 0.5;
    triangleParams2.ySize = 0.5;

    EXPECT_NO_THROW(manager->updatePolygon(triangle, triangleParams2));

    EXPECT_NO_THROW(manager->removePolygon(triangle));
}
TEST_F(ShapeAPITest, removeShapeAfterRemove){
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 1.0;
    triangleParams.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = 0.5;
    triangleParams2.y = 0.5;
    triangleParams2.xSize = 0.5;
    triangleParams2.ySize = 0.5;

    EXPECT_NO_THROW(manager->removePolygon(triangle));

    EXPECT_THROW(manager->removePolygon(triangle), std::runtime_error);
}
TEST_F(ShapeAPITest, removeShapeAsNullptr){
    cleanup = false;
    EXPECT_THROW(manager->removePolygon((int)NULL), std::runtime_error);
}

TEST_F(ShapeAPITest, multipleAddRemove){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 1.0;
    triangleParams.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = 0.5;
    triangleParams2.y = 0.5;
    triangleParams2.xSize = 0.5;
    triangleParams2.ySize = 0.5;

    EXPECT_NO_THROW(manager->removePolygon(triangle));

    triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 1);

    EXPECT_NO_THROW(manager->removePolygon(triangle));
}

TEST_F(ShapeAPITest, updateShape) {
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 1.0;
    triangleParams.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams params2;
    params2.x = 0.1;
    params2.y = 0.4;
    params2.rotation = 0.0;
    params2.xSize = 1.0;
    params2.ySize = 1.0;

    EXPECT_NO_THROW(manager->updatePolygon(triangle, params2));
}


TEST_F(ShapeAPITest, updateShapeWrongIndex) {
    cleanup = false;
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 1.0;
    triangleParams.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Manager::ShapeParams params2;
    params2.x = 0.1;
    params2.y = 0.4;
    params2.rotation = 0.0;
    params2.xSize = 1.0;
    params2.ySize = 1.0;

    EXPECT_THROW(manager->updatePolygon(1, params2), std::runtime_error);
}

TEST_F(ShapeAPITest, updateShapeAfterUpdate) {
    Chronos::Manager::ShapeParams params;
    params.x = 0.5;
    params.y = 0.5;
    params.rotation = 0.0;
    params.xSize = 1.0;
    params.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int shapeIndex = manager->addPolygon(params, triangleType, "Assets/texture.jpg");
    EXPECT_NO_THROW(manager->updatePolygon(shapeIndex, params));

    Chronos::Manager::ShapeParams params2;
    params2.x = 0.1;
    params2.y = 0.4;
    params2.rotation = 0.0;
    params2.xSize = 1.0;
    params2.ySize = 1.0;
    EXPECT_NO_THROW(manager->updatePolygon(shapeIndex, params2));
}

TEST_F(ShapeAPITest, updateShapeNoAsNullptr) {
    cleanup = false;
    Chronos::Manager::ShapeParams params;
    params.x = 0.5;
    params.y = 0.5;
    params.rotation = 0.0;
    params.xSize = 1.0;
    params.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int shapeIndex = manager->addPolygon(params, triangleType, "Assets/texture.jpg");
    EXPECT_NO_THROW(manager->updatePolygon(shapeIndex, params));

    int shapeIndex2 = manager->addPolygon(params, triangleType, "Assets/texture.jpg");

    manager->removePolygon(shapeIndex);

    Chronos::Manager::ShapeParams params2;
    params2.x = 0.1;
    params2.y = 0.4;
    params2.rotation = 0.0;
    params2.xSize = 1.0;
    params2.ySize = 1.0;
    EXPECT_THROW(manager->updatePolygon((int)NULL, params2), std::runtime_error);

}


TEST_F(ShapeAPITest, updateShapeParamsAsNull) {
    Chronos::Manager::ShapeParams params;
    params.x = 0.5;
    params.y = 0.5;
    params.rotation = 0.0;
    params.xSize = 1.0;
    params.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int shapeIndex = manager->addPolygon(params, triangleType, "Assets/texture.jpg");
    EXPECT_NO_THROW(manager->updatePolygon(shapeIndex, (Chronos::Manager::ShapeParams)NULL));
}

TEST_F(ShapeAPITest, updateShapeAfterRemove) {
    cleanup = false;
    Chronos::Manager::ShapeParams params;
    params.x = 0.5;
    params.y = 0.5;
    params.rotation = 0.0;
    params.xSize = 1.0;
    params.ySize = 1.0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;

    int shapeIndex = manager->addPolygon(params, triangleType, "Assets/texture.jpg");
    manager->removePolygon(shapeIndex);

    Chronos::Manager::ShapeParams params2;
    params2.x = 0.1;
    params2.y = 0.4;
    params2.rotation = 0.0;
    params2.xSize = 1.0;
    params2.ySize = 1.0;
    EXPECT_THROW(manager->updatePolygon(shapeIndex, params), std::runtime_error);
}

TEST_F(ShapeAPITest, extremeMultipleShapesSameType){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = -0.2;
    triangleParams2.y = 0.9;
    triangleParams2.xSize = 0.4;
    triangleParams2.ySize = 0.5;
    triangleParams2.rotation = 0.6;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    manager->drawFrame();
    for(int i = 0; i < 1000; i++){
        int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
        EXPECT_EQ(triangle, i);
        manager->updatePolygon(triangle, triangleParams2);
        if(i > 0)
            manager->removePolygon(triangle - 1);
        manager->drawFrame();

    }
}

TEST_F(ShapeAPITest, multipleShapesSameType2){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = -0.2;
    triangleParams2.y = 0.9;
    triangleParams2.xSize = 0.4;
    triangleParams2.ySize = 0.5;
    triangleParams2.rotation = 0.6;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    manager->drawFrame();
    for(int i = 0; i < 10; i++){
        int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
        EXPECT_EQ(triangle, i);
        manager->updatePolygon(triangle, triangleParams2);
        manager->drawFrame();
        manager->removePolygon(triangle);
        std::cout << i << std::endl;
    }
}


TEST_F(ShapeAPITest, extremeShapesUpdates){
    Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = -0.2;
    triangleParams2.y = 0.9;
    triangleParams2.xSize = 0.4;
    triangleParams2.ySize = 0.5;
    triangleParams2.rotation = 0.6;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);
    manager->drawFrame();
    for(int i = 0; i < 1000; i++){
        triangleParams2.x -= -0.2;
        triangleParams2.y += 0.9;
        triangleParams2.xSize -= 0.4;
        triangleParams2.ySize += 0.5;
        triangleParams2.rotation -= 0.6;
        manager->updatePolygon(triangle, triangleParams2);
        manager->drawFrame();
    }
}

TEST_F(ShapeAPITest, extremeParamsTest1){
   Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = 0;
    triangleParams2.y = 0;
    triangleParams2.xSize = 0;
    triangleParams2.ySize = 0;
    triangleParams2.rotation = 0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);
    manager->drawFrame();
    for(int i = 0; i < 10000; i++){
        triangleParams2.x -= 0.1;
        triangleParams2.y -= 0.1;
        triangleParams2.xSize -= 0.1;
        triangleParams2.ySize -= 0.1;
        triangleParams2.rotation -= 0.1;
        manager->updatePolygon(triangle, triangleParams2);
        manager->drawFrame();
    }
}

TEST_F(ShapeAPITest, extremeParamsTest2){
   Chronos::Manager::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;

    Chronos::Manager::ShapeParams triangleParams2;
    triangleParams2.x = 0;
    triangleParams2.y = 0;
    triangleParams2.xSize = 0;
    triangleParams2.ySize = 0;
    triangleParams2.rotation = 0;

    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);
    manager->drawFrame();
    for(int i = 0; i < 10000; i++){
        triangleParams2.x += 0.1;
        triangleParams2.y += 0.1;
        triangleParams2.xSize += 0.1;
        triangleParams2.ySize += 0.1;
        triangleParams2.rotation += 0.1;
        manager->updatePolygon(triangle, triangleParams2);
        manager->drawFrame();
    }
}