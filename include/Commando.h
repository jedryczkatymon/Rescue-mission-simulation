#pragma once
#include <memory>
#include <vector>
#include "Item.h"

class Commando {
public:
    void addItem(std::unique_ptr<Item> item);
    const std::vector<std::unique_ptr<Item>>& getItems() const;
    std::vector<std::unique_ptr<Item>>& getItems();

private:
    std::vector<std::unique_ptr<Item>> inventory;
};
