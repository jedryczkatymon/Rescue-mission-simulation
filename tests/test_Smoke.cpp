#include "gtest/gtest.h"
#include "../include/Smoke.h"
using namespace std;

TEST(SmokeTest, ConstructorInitializesState)
{
    Smoke smoke;
    EXPECT_FALSE(smoke.isDeployed());
}

TEST(SmokeTest, DeploySetsDeployedTrue)
{
    Smoke smoke;
    smoke.deploy();
    EXPECT_TRUE(smoke.isDeployed());
}
