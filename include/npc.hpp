#include <SDL2/SDL.h>
#include <random>
#include "player.hpp"
#pragma once

class NPC
{
public:
    virtual ~NPC() {};
    virtual void setRect(SDL_FRect npcRect) = 0;
    virtual SDL_FRect *getRect() = 0;
    virtual void *setSurface() = 0;
    virtual SDL_Surface *getSurface() = 0;
    virtual void setSprite(SDL_Texture *sprite) = 0;
    virtual SDL_Texture *getSprite() = 0;
    virtual bool isPlayerColliding() = 0;
};