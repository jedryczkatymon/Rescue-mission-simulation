#include "gtest/gtest.h"
#include "../include/Item.h"

TEST(ItemTest, ConstructorInitializesState)
{
    Item item;
    EXPECT_FALSE(item.isUsed());
}

TEST(ItemTest, UseSetsUsedTrue)
{
    Item item;
    item.use();
    EXPECT_TRUE(item.isUsed());
}
