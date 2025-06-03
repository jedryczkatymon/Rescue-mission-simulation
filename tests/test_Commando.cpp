#include "gtest/gtest.h"
#include "../include/Commando.h"

TEST(CommandoTest, ConstructorSetsAlive)
{
    Commando commando1;
    EXPECT_TRUE(commando1.isAlive());
}

TEST(CommandoTest, KillSetsAliveFalse)
{
    Commando commando(true);
    commando.kill();
    TEST(CommandoTest, KillSetsAliveFalse)
    {
        Commando commando;
        commando.kill();
        EXPECT_FALSE(commando.isAlive());
    }
    Commando commando(true);
    commando.rescue();
    EXPECT_EQ(commando.getRescueCount(), 1);
}
