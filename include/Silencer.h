#pragma once
#include "Item.h"

class Silencer : public Item
{
public:
    Silencer();
    void applyEffect(Mission &mission) override;
};
