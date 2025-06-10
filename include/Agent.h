#pragma once

class Agent
{
public:
    Agent(bool alive = true);
    virtual ~Agent() = default;

    bool isAlive() const;
    void kill();

    virtual void doSpeak();

protected:
    bool alive;
};
