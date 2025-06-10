// #include "gtest/gtest.h"
// #include "../include/Mission.h"

// // Basic construction test
// TEST(MissionTest, ConstructorInitializesCorrectly)
// {
//     Mission mission;
//     // Should have 6 guards and 2 hostages
//     EXPECT_EQ(mission.getGuards().size(), 6);
//     EXPECT_EQ(mission.getHostages().size(), 2);
//     // Commando should have 3 items
//     EXPECT_EQ(mission.getCommando().getItems().size(), 3);
// }

// // Test logging functionality
// TEST(MissionTest, LogAddsEntry)
// {
//     Mission mission;
//     mission.log("Test entry");
//     const auto &logs = mission.getLogEntries();
//     ASSERT_FALSE(logs.empty());
//     EXPECT_EQ(logs.back(), "Test entry");
// }

// // Test flashbang and smoke effect application
// TEST(MissionTest, ApplyEffects)
// {
//     Mission mission;
//     mission.applyFlashbangEffect();
//     EXPECT_EQ(mission.getFlashbangEffect(), 2);
//     mission.applySmokeEffect();
//     EXPECT_EQ(mission.getSmokeEffect(), 2);
// }

// // Test that running the mission sets start and end time and logs results
// TEST(MissionTest, RunSetsTimesAndLogs)
// {
//     Mission mission;
//     mission.run();
//     // After run, endTime should be after startTime
//     EXPECT_LT(mission.getStartTime(), mission.getEndTime());
//     // There should be log entries
//     EXPECT_FALSE(mission.getLogEntries().empty());
// }

// // Test that after rescueHostages, hostages are rescued and log is updated
// TEST(MissionTest, RescueHostagesRescuesAll)
// {
//     Mission mission;
//     mission.rescueHostages();
//     for (const auto &hostage : mission.getHostages())
//     {
//         EXPECT_TRUE(hostage.isRescued());
//     }
//     // Check log for success message
//     const auto &logs = mission.getLogEntries();
//     auto it = std::find_if(logs.begin(), logs.end(), [](const std::string &entry)
//                            { return entry.find("Zakładnicy uratowani.") != std::string::npos; });
//     EXPECT_NE(it, logs.end());
// }

// // Test simulateGuardEncounters with all guards dead (should not fail mission)
// TEST(MissionTest, SimulateGuardEncountersAllDead)
// {
//     Mission mission;
//     for (auto &guard : mission.getGuards())
//     {
//         guard.kill();
//     }
//     bool missionFailed = false;
//     mission.simulateGuardEncounters(missionFailed);
//     EXPECT_FALSE(missionFailed);
// }

// // Test logToCSV creates a file (integration, may be skipped if file IO not wanted)
// TEST(MissionTest, LogToCSVCreatesFile)
// {
//     Mission mission;
//     mission.run();
//     mission.logToCSV();
//     EXPECT_TRUE(std::filesystem::exists("logs/mission_log.csv"));
// }
