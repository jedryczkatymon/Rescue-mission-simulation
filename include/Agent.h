#pragma once

class Agent {
public:
    Agent(bool alive = true);
    virtual ~Agent() = default;

    bool isAlive() const;
    virtual void kill();

protected:
    bool alive;
};
