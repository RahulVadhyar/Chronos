#include "gtest/gtest.h"
#include "chronos.hpp"

class ShapeManagerTest : public testing::Test {
protected:
    
    Chronos::Manager::Manager* manager = nullptr;
    bool cleanup = true;
    void SetUp() override{
        Chronos::Manager::Initializer initializer = {800, 600, {0, 0, 0}};
        manager = new Chronos::Manager::Manager(initializer); 
    }
    void TearDown() override {
        if(cleanup)
            delete manager;
    }
};

TEST_F(ShapeManagerTest, isWorking){

    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Engine::ShapeParams rectangleParams;
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

TEST_F(ShapeManagerTest, multipleShapesDifferentType){

    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    int triangle = manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpg");
    EXPECT_EQ(triangle, 0);

    Chronos::Engine::ShapeParams rectangleParams;
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

TEST_F(ShapeManagerTest, multipleShapesSameTypeTriangle){
    Chronos::Engine::ShapeParams triangleParams;
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
TEST_F(ShapeManagerTest, multipleShapeSameTypeRectangle){

    Chronos::Engine::ShapeParams rectangleParams;
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


TEST_F(ShapeManagerTest, incompatibleTextureType1){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.jp"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType2){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pn"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType3){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjp"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType4){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjpg"), std::runtime_error);
}


TEST_F(ShapeManagerTest, incompatibleTextureType5){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.jpgpng"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType6){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjpg"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType7){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/.pngjpg"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType8){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture.pngjpg.png"), std::runtime_error);
}

TEST_F(ShapeManagerTest, incompatibleTextureType9){
    cleanup = false;
    Chronos::Engine::ShapeParams triangleParams;
    triangleParams.x = 0.5;
    triangleParams.y = 0.5;
    triangleParams.xSize = 0.5;
    triangleParams.ySize = 0.5;
    triangleParams.rotation = 0;
    Chronos::Manager::PolygonType triangleType;
    triangleType.triangle = true;
    EXPECT_THROW(manager->addPolygon(triangleParams, triangleType, "Assets/texture"), std::runtime_error);
}

// TEST_F(ShapeManagerTest, multipleShapesDifferentTypeDifferentTexture)
// TEST_F(ShapeManagerTest, wrongTexturePath)
// TEST_F(ShapeManagerTest, paramsIsNullptr)
// TEST_F(ShapeManagerTest, polygonTypeIsNullptr)
// TEST_F(ShapeManagerTest, texturePathIsNullptr)
// TEST_F(ShapeManagerTest, removeShape)
// TEST_F(ShapeManagerTest, removeShapeWrongIndex)
// TEST_F(ShapeManagerTest, removeShapeAfterUpdate)
// TEST_F(ShapeManagerTest, removeShapeAfterRemove)
// TEST_F(ShapeManagerTest, removePutAsNullptr)
// TEST_F(ShapeManagerTest, multipleAddRemove)
// TEST_F(ShapeManagerTest, updateShape)
// TEST_F(ShapeManagerTest, updateShapeWrongIndex)
// TEST_F(ShapeManagerTest, updateShapeWrongParams)
// TEST_F(ShapeManagerTest, updateShapeAfterRemove)


