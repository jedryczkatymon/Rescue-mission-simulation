#include <gtest/gtest.h>
#include <sstream>
#include <iostream>
#include "../include/Agent.h"

Agent::Agent(bool alive) : alive(alive) {}

bool Agent::isAlive() const
{
    return alive;
}

void Agent::kill()
{
    alive = false;
}

void Agent::doSpeak()
{
    std::cout << "[Agent] Czysto!\n";
}

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

TEST(AgentTest, IsAliveReturnsCorrectValue)
{
    Agent agent(true);
    EXPECT_TRUE(agent.isAlive());
    agent.kill();
    EXPECT_FALSE(agent.isAlive());
}

TEST(AgentTest, SpeakOutputsCorrectMessage)
{
    Agent agent(true);
    std::stringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    agent.doSpeak();

    std::cout.rdbuf(oldCout);
    EXPECT_EQ(buffer.str(), "[Agent] Czysto!\n");
}

TEST(AgentTest, DoSpeakOutputsCorrectMessage)
{
    Agent agent(true);
    std::stringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    agent.doSpeak();

    std::cout.rdbuf(oldCout);
    EXPECT_EQ(buffer.str(), "[Agent] Czysto!\n");
}
