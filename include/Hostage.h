#pragma once

class Hostage {
public:
    bool isRescued() const;
    void rescue();

private:
    bool rescued = false;
};
