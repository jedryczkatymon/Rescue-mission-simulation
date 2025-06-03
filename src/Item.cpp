#include "Item.h"

Item::Item(const std::string& name) : name(name) {}

const std::string& Item::getName() const {
    return name;
}

bool Item::isUsed() const {
    return used;
}

void Item::use() {
    used = true;
}

void Item::setUsed(bool value) {
    used = value;
}
