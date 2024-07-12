#include "gtest/gtest.h"
#include "chronos.hpp"

// class GeneralAPITest : public testing::Test {
// protected:

//     Chronos::Manager::Manager* manager = nullptr;
//     void SetUp() override{
//         Chronos::Manager::Initializer initializer = {800, 600, {0, 0, 0}};
//         manager = new Chronos::Manager::Manager(initializer);
//     }
//     void TearDown() override {
//         delete manager;
//     }
// };

// TEST_F(GeneralAPITest, isWorking){

//     Chronos::Manager::ShapeParams triangleParams;
//     triangleParams.x = 0.5;
//     triangleParams.y = 0.5;
//     triangleParams.xSize = 0.5;
//     triangleParams.ySize = 0.5;
//     triangleParams.rotation = 0;
//     Chronos::Manager::PolygonType triangleType;
//     triangleType.triangle = true;
//     int triangle = manager->addPolygon(triangleParams, triangleType,
//     "Assets/texture.jpg"); EXPECT_EQ(triangle, 0);

//     Chronos::Manager::ShapeParams rectangleParams;
//     rectangleParams.x = -0.5;
//     rectangleParams.y = -0.5;
//     rectangleParams.xSize = 0.5;
//     rectangleParams.ySize = 0.5;
//     rectangleParams.rotation = 0;
//     Chronos::Manager::PolygonType rectangleType;
//     rectangleType.rectangle = true;
//     int rectangle = manager->addPolygon(rectangleParams, rectangleType,
//     "Assets/texture.jpg"); EXPECT_EQ(rectangle, 1);

//     Chronos::Engine::TextParams textParams;
//     textParams.x = 0.0f;
//     textParams.y = 0.0f;
//     textParams.text = "This is a test";
//     textParams.rotation = 0;
//     textParams.scale = 1.0;
//     int textNo = manager->addText(textParams);
//     EXPECT_EQ(textNo, 0);

//     manager->drawFrame();
// }

// TEST_F(GeneralAPITest, renderFrames){

//     Chronos::Manager::ShapeParams triangleParams;
//     triangleParams.x = 0.5;
//     triangleParams.y = 0.5;
//     triangleParams.xSize = 0.5;
//     triangleParams.ySize = 0.5;
//     triangleParams.rotation = 0;
//     Chronos::Manager::PolygonType triangleType;
//     triangleType.triangle = true;
//     int triangle = manager->addPolygon(triangleParams, triangleType,
//     "Assets/texture.jpg"); EXPECT_EQ(triangle, 0);

//     Chronos::Manager::ShapeParams rectangleParams;
//     rectangleParams.x = -0.5;
//     rectangleParams.y = -0.5;
//     rectangleParams.xSize = 0.5;
//     rectangleParams.ySize = 0.5;
//     rectangleParams.rotation = 0;
//     Chronos::Manager::PolygonType rectangleType;
//     rectangleType.rectangle = true;
//     int rectangle = manager->addPolygon(rectangleParams, rectangleType,
//     "Assets/texture.jpg"); EXPECT_EQ(rectangle, 1);

//     Chronos::Engine::TextParams textParams;
//     textParams.x = 0.0f;
//     textParams.y = 0.0f;
//     textParams.text = "This is a test";
//     textParams.rotation = 0;
//     textParams.scale = 1.0;
//     int textNo = manager->addText(textParams);
//     EXPECT_EQ(textNo, 0);
//     for(int i = 0; i < 1000; i++){
//         manager->drawFrame();
//     }
// }

// TEST_F(GeneralAPITest, updateShapeAndText){

//     Chronos::Manager::ShapeParams triangleParams;
//     triangleParams.x = 0.5;
//     triangleParams.y = 0.5;
//     triangleParams.xSize = 0.5;
//     triangleParams.ySize = 0.5;
//     triangleParams.rotation = 0;
//     Chronos::Manager::PolygonType triangleType;
//     triangleType.triangle = true;
//     int triangle = manager->addPolygon(triangleParams, triangleType,
//     "Assets/texture.jpg"); EXPECT_EQ(triangle, 0);

//     Chronos::Manager::ShapeParams rectangleParams;
//     rectangleParams.x = -0.5;
//     rectangleParams.y = -0.5;
//     rectangleParams.xSize = 0.5;
//     rectangleParams.ySize = 0.5;
//     rectangleParams.rotation = 0;
//     Chronos::Manager::PolygonType rectangleType;
//     rectangleType.rectangle = true;
//     int rectangle = manager->addPolygon(rectangleParams, rectangleType,
//     "Assets/texture.jpg"); EXPECT_EQ(rectangle, 1);

//     Chronos::Engine::TextParams textParams;
//     textParams.x = 0.0f;
//     textParams.y = 0.0f;
//     textParams.text = "This is a test";
//     textParams.rotation = 0;
//     textParams.scale = 1.0;
//     int textNo = manager->addText(textParams);
//     EXPECT_EQ(textNo, 0);
//     for(int i = 0; i < 1000; i++){
//         triangleParams.x += 0.1f;
//         triangleParams.y += 0.1f;
//         triangleParams.rotation += 0.1;
//         triangleParams.xSize += 0.1;
//         triangleParams.ySize += 0.1;
//         manager->updatePolygon(0, triangleParams);

//         rectangleParams.x -= 0.1f;
//         rectangleParams.y -= 0.1f;
//         rectangleParams.rotation -= 0.1;
//         rectangleParams.xSize -= 0.1;
//         rectangleParams.ySize -= 0.1;
//         manager->updatePolygon(1, rectangleParams);

//         textParams.x = 0.0f;
//         textParams.y = 0.0f;
//         textParams.text = "This is a test";
//         textParams.rotation = 0;
//         textParams.scale = 1.0;
//         manager->addText(textParams);
//         manager->drawFrame();
//     }
// }

// TEST_F(GeneralAPITest, changeBackgroundColor){
//     for(int i = 0; i < 1000; i++){
//         manager->changeBackgroundColor(0.0f, 0.0f, 0.0f);
//         manager->drawFrame();
//         manager->changeBackgroundColor(1.0f, 1.0f, 1.0f);
//         manager->drawFrame();
//     }
// }

// TEST_F(GeneralAPITest, invalidBackgroundColor){
//     EXPECT_THROW(manager->changeBackgroundColor(-1.0f, 0.0f, 0.0f),
//     std::runtime_error); EXPECT_THROW(manager->changeBackgroundColor(0.0f,
//     -1.0f, 0.0f), std::runtime_error);
//     EXPECT_THROW(manager->changeBackgroundColor(0.0f, 0.0f, -1.0f),
//     std::runtime_error); EXPECT_THROW(manager->changeBackgroundColor(2.0f,
//     0.0f, 0.0f), std::runtime_error);
//     EXPECT_THROW(manager->changeBackgroundColor(0.0f, 2.0f, 0.0f),
//     std::runtime_error); EXPECT_THROW(manager->changeBackgroundColor(0.0f,
//     0.0f, 2.0f), std::runtime_error);
//     EXPECT_THROW(manager->changeBackgroundColor(1.1f, 0.0f, 0.0f),
//     std::runtime_error);
//     EXPECT_THROW(manager->changeBackgroundColor(0.0f, 1.1f, 0.0f),
//     std::runtime_error); EXPECT_THROW(manager->changeBackgroundColor(0.0f,
//     0.0f, 1.1f), std::runtime_error);
//     EXPECT_THROW(manager->changeBackgroundColor(0.0f, 0.0f, -0.1f),
//     std::runtime_error); EXPECT_THROW(manager->changeBackgroundColor(0.0f,
//     -0.1f, 0.0f), std::runtime_error);
//     EXPECT_THROW(manager->changeBackgroundColor(-0.1f, 0.0f, 0.0f),
//     std::runtime_error);
// }

// TEST_F(GeneralAPITest, getWindow){
//     EXPECT_NE(manager->getWindow(), nullptr);
// }

// TEST(InitManagerTest, invalidInit1){
//     Chronos::Manager::Initializer initializer = {0, 0, {0, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }
// TEST(InitManagerTest, invalidInit2){
//     Chronos::Manager::Initializer initializer = {0, 600, {0, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }
// TEST(InitManagerTest, invalidInit3){
//     Chronos::Manager::Initializer initializer = {800, 0, {0, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit4){
//     Chronos::Manager::Initializer initializer = {800, 600, {-1, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit5){
//     Chronos::Manager::Initializer initializer = {800, 600, {0, -1, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit6){
//     Chronos::Manager::Initializer initializer = {800, 600, {0, 0, -1}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit7){
//     Chronos::Manager::Initializer initializer = {800, 600, {2, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit8){
//     Chronos::Manager::Initializer initializer = {800, 600, {0, 2, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit9){
//     Chronos::Manager::Initializer initializer = {800, 600, {0, 0, 2}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit10){
//     Chronos::Manager::Initializer initializer = {-1, 0, {0, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }

// TEST(InitManagerTest, invalidInit11){
//     Chronos::Manager::Initializer initializer = {0, -1, {0, 0, 0}};
//     EXPECT_THROW(Chronos::Manager::Manager manager(initializer),
//     std::runtime_error);
// }
