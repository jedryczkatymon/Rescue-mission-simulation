#include "Hostage.h"

bool Hostage::isRescued() const {
    return rescued;
}

void Hostage::rescue() {
    rescued = true;
}
