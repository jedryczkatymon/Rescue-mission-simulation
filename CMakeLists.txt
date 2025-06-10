cmake_minimum_required(VERSION 3.28)
project(RESCUE_MISSION_SIMULATION)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(RESCUE_MISSION_SIMULATION
    include/Agent.h
    include/Commando.h
    include/Flashbang.h
    include/Guard.h
    include/Hostage.h
    include/Item.h
    include/Logger.h
    include/Mission.h
    include/Silencer.h
    include/Smoke.h
    src/Agent.cpp
    src/Commando.cpp
    src/Flashbang.cpp
    src/Guard.cpp
    src/Hostage.cpp
    src/Item.cpp
    src/Logger.cpp
    src/main.cpp
    src/Mission.cpp
    src/Silencer.cpp
    src/Smoke.cpp)

# Enable testing
enable_testing()

# Gather all test files
file(GLOB TEST_SOURCES tests/*.cpp)

add_executable(RESCUE_MISSION_TESTS
    ${TEST_SOURCES}
)

target_include_directories(RESCUE_MISSION_TESTS PRIVATE include)

# Link with GTest and pthread
find_package(GTest REQUIRED)
target_link_libraries(RESCUE_MISSION_TESTS GTest::gtest GTest::gtest_main pthread)

# Register tests with CTest
add_test(NAME AllTests COMMAND RESCUE_MISSION_TESTS)
