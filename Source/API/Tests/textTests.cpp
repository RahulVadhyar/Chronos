#include "gtest/gtest.h"
#include "chronos.hpp"

class TextAPITest : public testing::Test {
protected:
    
    Chronos::Manager::Manager* manager = nullptr;
    bool cleanup = true;
    void SetUp() override{
        Chronos::Manager::Initializer initializer = {800, 600, {0, 0, 0}};
        manager = new Chronos::Manager::Manager(initializer); 
    }
};

TEST_F(TextAPITest, isWorking){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;

    int textNo = manager->addText(textParams);
    EXPECT_EQ(textNo, 0);
}

TEST_F(TextAPITest, extremeMultipleTextsSameParams){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;
    for(int i = 0; i < 1000; i++){
        int textNo = manager->addText(textParams);
        EXPECT_EQ(textNo, i);
        manager->drawFrame();
    }
}

TEST_F(TextAPITest, extremeMultipleTextsDifferentParams1){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;
    for(int i = 0; i < 1000; i++){
        textParams.x += 0.1f;
        textParams.y += 0.1f;
        textParams.rotation += 0.1;
        textParams.scale += 0.1;
        int textNo = manager->addText(textParams);
        EXPECT_EQ(textNo, i);
        manager->drawFrame();
    }
}

TEST_F(TextAPITest, extremeMultipleTextsDifferentParams2){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;
    for(int i = 0; i < 1000; i++){
        textParams.x -= 0.1f;
        textParams.y -= 0.1f;
        textParams.rotation -= 0.1;
        textParams.scale -= 0.1;
        int textNo = manager->addText(textParams);
        EXPECT_EQ(textNo, i);
        manager->drawFrame();
    }
}

TEST_F(TextAPITest, extremeMultipleTextsDifferentParams3){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;
    for(int i = 0; i < 100; i++){
        textParams.x -= 0.1f;
        textParams.y -= 0.1f;
        textParams.rotation -= 0.1;
        textParams.scale -= 0.1;
        textParams.text += "a";
        int textNo = manager->addText(textParams);
        EXPECT_EQ(textNo, i);
        manager->drawFrame();
    }
}

TEST_F(TextAPITest, removeText){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;

    int textNo = manager->addText(textParams);
    EXPECT_EQ(textNo, 0);
    manager->removeText(textNo);
    manager->drawFrame();
}

TEST_F(TextAPITest, addBlankText){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "";
    textParams.rotation = 0;
    textParams.scale = 1.0;
    EXPECT_THROW(manager->addText(textParams);, std::runtime_error);
    manager->drawFrame();
}

TEST_F(TextAPITest, extremeAddRemoveText){
    Chronos::Engine::TextParams textParams;
    textParams.x = 0.0f;
    textParams.y = 0.0f;
    textParams.text = "This is a test";
    textParams.rotation = 0;
    textParams.scale = 1.0;
    for(int i = 0; i < 100; i++){
        textParams.x -= 0.1f;
        textParams.y -= 0.1f;
        textParams.rotation -= 0.1;
        textParams.scale -= 0.1;
        textParams.text += "a";
        int textNo = manager->addText(textParams);
        EXPECT_EQ(textNo, i);
        manager->drawFrame();
        if(i > 0){
            manager->removeText(i-1);
            manager->drawFrame();
        }
    }
}
