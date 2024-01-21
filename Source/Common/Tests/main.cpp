#include "gtest/gtest.h"
#include "chronos.hpp"
int main(int argc, char **argv) {
    
    std::filesystem::path cwdpath("../../../");
    std::filesystem::current_path(cwdpath);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
