#include "gtest/gtest.h"
#include "../include/Commando.h"
#include "../include/Item.h"
#include <memory>
#include <sstream>

TEST(CommandoTest, ConstructorSetsAlive)
{
    Commando commando1;
    EXPECT_TRUE(commando1.isAlive());
}

TEST(CommandoTest, KillSetsAliveFalse)
{
    Commando commando;
    commando.kill();
    EXPECT_FALSE(commando.isAlive());
}

TEST(CommandoTest, DoSpeakOutputsCorrectly)
{
    Commando commando;
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    commando.doSpeak();
    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "[Commando] Do boju!\n");
}
