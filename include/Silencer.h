#pragma once
#include "Item.h"

class Silencer : public Item {
public:
    Silencer();

    // nadpisujemy polimorficzną metodę, która działa na Mission
    void applyEffect(Mission& mission) override;
};
