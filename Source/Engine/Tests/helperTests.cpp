#include "gtest/gtest.h"
#include "helper.hpp"
TEST(getAbsolutePathTest, BasicTest)
{
    EXPECT_EQ(Chronos::Engine::getAbsolutePath("test.txt"), "/run/media/borked/baby2/StreetChase/build/ThirdParty/test.txt");
}