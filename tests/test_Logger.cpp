#include "gtest/gtest.h"
#include "../include/Logger.h"

TEST(LoggerTest, ConstructorInitializesLogger)
{
    Logger logger;
    EXPECT_TRUE(logger.getLogs().empty());
}

TEST(LoggerTest, LogAddsEntry)
{
    Logger logger;
    logger.log("Test entry");
    auto logs = logger.getLogs();
    EXPECT_EQ(logs.size(), 1);
    EXPECT_EQ(logs[0], "Test entry");
}
