#include "gtest/gtest.h"
#include <thread>

int main(int args, char **argv)
{
    ::testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
