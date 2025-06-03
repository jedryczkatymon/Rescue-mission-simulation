#include "gtest/gtest.h"
#include "../include/Guard.h"

TEST(GuardTest, ConstructorSetsAlive)
{
    Guard guard1(true);
    EXPECT_TRUE(guard1.isAlive());

    Guard guard2(false);
    EXPECT_FALSE(guard2.isAlive());
}

TEST(GuardTest, KillSetsAliveFalse)
{
    Guard guard(true);
    guard.kill();
    EXPECT_FALSE(guard.isAlive());
}
