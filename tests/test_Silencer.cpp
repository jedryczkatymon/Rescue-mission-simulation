#include "gtest/gtest.h"
#include "../include/Silencer.h"

TEST(SilencerTest, ConstructorInitializesState)
{
    Silencer silencer;
    EXPECT_FALSE(silencer.isUsed());
}

TEST(SilencerTest, UseSetsUsedTrue)
{
    Silencer silencer;
    silencer.use();
    EXPECT_TRUE(silencer.isUsed());
}
