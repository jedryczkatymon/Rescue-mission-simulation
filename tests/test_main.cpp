#include "gtest/gtest.h"

TEST(MainIntegrationTest, SimulationRunsWithoutError)
{
    EXPECT_NO_THROW(sim.run());
    SUCCEED();
}