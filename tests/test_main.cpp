#include "gtest/gtest.h"
#include "gtest/gtest.h"
#include "Mission.h"
#include <sstream>
#include <iostream>

// Helper class to mock Mission for testing main logic
class MockMission : public Mission
{
public:
    bool runCalled = false;
    bool logResultsCalled = false;
    bool throwOnRun = false;

    void run()
    {
        runCalled = true;
        if (throwOnRun)
        {
            throw std::runtime_error("Test exception");
        }
    }

    void logResults()
    {
        logResultsCalled = true;
    }
};

// Helper function to simulate main logic
int test_main_like(MockMission &mission, std::ostream &out, std::ostream &err)
{
    out << "MISJA W TOKU...\n\n";
    // Skipping sleep for test speed

    try
    {
        mission.run();
    }
    catch (const std::exception &e)
    {
        err << "Błąd: " << e.what() << std::endl;
        return 1;
    }

    // Skipping sleep for test speed
    out << "\n=== PODSUMOWANIE MISJI ===\n\n";
    mission.logResults();
    return 0;
}

TEST(MainTest, MissionRunAndLogResultsCalled)
{
    MockMission mission;
    std::ostringstream out, err;
    int ret = test_main_like(mission, out, err);

    EXPECT_TRUE(mission.runCalled);
    EXPECT_TRUE(mission.logResultsCalled);
    EXPECT_EQ(ret, 0);
    EXPECT_NE(out.str().find("MISJA W TOKU"), std::string::npos);
    EXPECT_NE(out.str().find("PODSUMOWANIE MISJI"), std::string::npos);
    EXPECT_EQ(err.str(), "");
}

TEST(MainTest, MissionRunThrowsException)
{
    MockMission mission;
    mission.throwOnRun = true;
    std::ostringstream out, err;
    int ret = test_main_like(mission, out, err);

    EXPECT_TRUE(mission.runCalled);
    EXPECT_FALSE(mission.logResultsCalled);
    EXPECT_EQ(ret, 1);
    EXPECT_NE(err.str().find("Błąd: Test exception"), std::string::npos);
}
