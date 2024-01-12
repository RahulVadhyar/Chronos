#include "gtest/gtest.h"
#include "stlheader.hpp"
#include "helper.hpp"
TEST(getAbsolutePathTest, BasicTest)
{
    EXPECT_EQ(getAbsolutePath("test.txt"), "/run/media/borked/baby2/StreetChase/build/ThirdParty/test.txt");
}