#pragma once
#include <string>

class Mission;

class Item {
public:
    Item(const std::string& name);
    virtual ~Item() = default;

    virtual const std::string& getName() const;
    virtual bool isUsed() const;
    virtual void use();

    virtual void applyEffect(Mission& mission) = 0;

    void setUsed(bool value);

protected:
    std::string name;
    bool used = false;
};
