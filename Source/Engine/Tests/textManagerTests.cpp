#include "gtest/gtest.h"
#include "chronos.hpp"

class TextManagerTest : public testing::Test {
protected:
    
    Chronos::Manager::Manager* manager = nullptr;
    void SetUp() override{
        Chronos::Manager::Initializer initializer = {800, 600, {0, 0, 0}};
        manager = new Chronos::Manager::Manager(initializer); 
    }
    void TearDown() override {
        delete manager;
    }
};

TEST_F(TextManagerTest, isWorking){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;

    int textNo = manager->addText(textParams);
    EXPECT_EQ(textNo, 0);
}


TEST_F(TextManagerTest, multipleTexts){

    Chronos::Engine::TextParams textParams1;
    textParams1.x = 0.0f;
    textParams1.y = 0.0f;
    textParams1.text = "This is a test";
    textParams1.rotation = 0;
    textParams1.scale = 1.0;

    int textNo1 = manager->addText(textParams1);
    EXPECT_EQ(textNo1, 0);

    Chronos::Engine::TextParams textParams2;
    textParams2.x = 0.5f;
    textParams2.y = 0.3f;
    textParams2.text = "Second test";
    textParams2.rotation = 0.23;
    textParams2.scale = 0.5;

    int textNo2 = manager->addText(textParams2);
    EXPECT_EQ(textNo2, 1);

    Chronos::Engine::TextParams textParams3;
    textParams3.x = 0.5f;
    textParams3.y = 0.3f;
    textParams3.text = "Second test";
    textParams3.rotation = 0.23;
    textParams3.scale = 0.5;

    int textNo3 = manager->addText(textParams3);
    EXPECT_EQ(textNo3, 2);

    Chronos::Engine::TextParams textParams4;
    textParams4.x = 0.5f;
    textParams4.y = 0.3f;
    textParams4.text = "Second test";
    textParams4.rotation = 0.23;
    textParams4.scale = 0.5;

    int textNo4 = manager->addText(textParams4);
    EXPECT_EQ(textNo4, 3);

    Chronos::Engine::TextParams textParams5;
    textParams5.x = 0.5f;
    textParams5.y = 0.3f;
    textParams5.text = "Second test";
    textParams5.rotation = 0.23;
    textParams5.scale = 0.5;

    int textNo5 = manager->addText(textParams5);
    EXPECT_EQ(textNo5, 4);
}