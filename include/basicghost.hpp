#include <SDL2/SDL.h>
#include "npc.hpp"
#pragma once

// class for the beginner enemy BasicGhost
// all enemies will implement the NPC abstract class
class BasicGhost : virtual public NPC
{
public:
    BasicGhost();
    ~BasicGhost();

    bool isPlayerColliding();
    void trackPlayer();
    bool damagePlayer();
};