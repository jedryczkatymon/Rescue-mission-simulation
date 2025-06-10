#include "gtest/gtest.h"
#include "../include/Hostage.h"

bool Hostage::isRescued() const
{
    return rescued;
}

void Hostage::rescue()
{
    rescued = true;
}

TEST(HostageTest, InitiallyNotRescued)
{
    Hostage h;
    EXPECT_FALSE(h.isRescued());
}

TEST(HostageTest, RescueChangesState)
{
    Hostage h;
    h.rescue();
    EXPECT_TRUE(h.isRescued());
}

TEST(HostageTest, MultipleRescueCalls)
{
    Hostage h;
    h.rescue();
    h.rescue(); // Call rescue again
    EXPECT_TRUE(h.isRescued());
}
