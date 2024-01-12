#include "helper.hpp"
#include "stlheader.hpp"
#include "gtest/gtest.h"
TEST(getAbsolutePathTest, BasicTest)
{
    EXPECT_EQ(getAbsolutePath("test.txt"), "/run/media/borked/baby2/StreetChase/build/ThirdParty/test.txt");
}