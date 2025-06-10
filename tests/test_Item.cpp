#include "gtest/gtest.h"
#include "../include/Item.h"

Item::Item(const std::string &name) : name(name) {}

const std::string &Item::getName() const
{
    return name;
}

bool Item::isUsed() const
{
    return used;
}

void Item::use()
{
    used = true;
}

void Item::setUsed(bool value)
{
    used = value;
}

class TestItem : public Item
{
public:
    TestItem(const std::string &name) : Item(name) {}
    void applyEffect(Mission &) override {}
};

TEST(ItemTest, IsUsedInitiallyFalse)
{
    TestItem item("Medkit");
    EXPECT_FALSE(item.isUsed());
}

TEST(ItemTest, UseSetsUsedTrue)
{
    TestItem item("Medkit");
    item.use();
    EXPECT_TRUE(item.isUsed());
}

TEST(ItemTest, SetUsedSetsUsedValue)
{
    TestItem item("Medkit");
    item.setUsed(true);
    EXPECT_TRUE(item.isUsed());
    item.setUsed(false);
    EXPECT_FALSE(item.isUsed());
}