#pragma once
#include "Item.h"
#include "Mission.h"

class SmokeGrenade : public Item {
public:
    SmokeGrenade();

    void applyEffect(Mission& mission) override;
};