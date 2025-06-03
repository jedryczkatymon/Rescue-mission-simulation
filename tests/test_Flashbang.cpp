#include "gtest/gtest.h"
#include "../include/Flashbang.h"

TEST(FlashbangTest, ConstructorInitializesState)
{
    Flashbang flashbang;
    EXPECT_FALSE(flashbang.isDetonated());
}

TEST(FlashbangTest, DetonateSetsDetonatedTrue)
{
    Flashbang flashbang;
    flashbang.detonate();
    EXPECT_TRUE(flashbang.isDetonated());
}
