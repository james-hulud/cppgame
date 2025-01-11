#include <SDL2/SDL.h>
#include <random>
#include "player.hpp"
#pragma once

// Abstract class all NPCs will implement, setters and getters work the same for all NPCs
// All NPCs have the attributes here
class NPC
{
public:
    virtual ~NPC() = default;

    // Default implementations in npc.cpp
    virtual void setRect(SDL_FRect npcRect);
    virtual SDL_FRect *getRect();
    virtual void setSurface(SDL_Surface *spriteImage);
    virtual SDL_Surface *getSurface();
    virtual void setSprite(SDL_Texture *sprite);
    virtual SDL_Texture *getSprite();
    virtual void setID(int id);
    virtual int getID();
    virtual void setDead(bool dead);
    virtual bool isDead();
    virtual void setPlayer(Player *player);
    virtual bool isPlayerColliding() = 0;

    // Implement these:
    virtual void trackPlayer() = 0;
    virtual bool damagePlayer() = 0;

protected:
    SDL_FRect npcRect;
    SDL_Surface *spriteImage = nullptr;
    SDL_Texture *sprite = nullptr;
    Player *player = nullptr;
    bool dead = false;
    int id = -1;
};