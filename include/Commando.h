#pragma once
#include <memory>
#include <vector>
#include "Item.h"
#include "Agent.h"

class Commando : public Agent
{
public:
    virtual ~Commando() = default;
    void addItem(std::unique_ptr<Item> item);
    const std::vector<std::unique_ptr<Item>> &getItems() const;
    std::vector<std::unique_ptr<Item>> &getItems();
    void doSpeak() override;

private:
    std::vector<std::unique_ptr<Item>> inventory;
};
