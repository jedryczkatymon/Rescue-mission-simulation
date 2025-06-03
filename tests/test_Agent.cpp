#include <gtest/gtest.h>
#include "../include/Agent.h"

TEST(AgentTest, ConstructorSetsAlive)
{
    Agent agent1(true);
    EXPECT_TRUE(agent1.isAlive());

    Agent agent2(false);
    EXPECT_FALSE(agent2.isAlive());
}

TEST(AgentTest, KillSetsAliveFalse)
{
    Agent agent(true);
    agent.kill();
    EXPECT_FALSE(agent.isAlive());
}
