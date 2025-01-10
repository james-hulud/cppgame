#include <SDL2/SDL.h>
#include <random>
#include "player.hpp"
#pragma once

// Manages a mob's actions
class Mob
{
public:
    virtual ~Mob() = 0;
    virtual void trackPlayer() = 0;
    virtual bool damagePlayer() = 0;
    virtual void setPlayer(Player *player) = 0;
    virtual void setDead(bool dead) = 0;
    virtual bool isDead() = 0;
    virtual void setID(int id) = 0;
    virtual int getID() = 0;
};