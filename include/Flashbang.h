#pragma once
#include "Item.h"
#include "Mission.h"

class Flashbang : public Item {
public:
    Flashbang();

    void applyEffect(Mission& mission) override;
};
