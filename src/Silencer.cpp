#include "Silencer.h"
#include "Mission.h"

Silencer::Silencer() : Item("Tlumík") {}

void Silencer::applyEffect(Mission& mission) {
    mission.setHasSilencer(true);  // tu ustawiasz flagę w misji, że jest tłumik
}
