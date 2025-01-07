#include <SDL2/SDL.h>
#include <random>
#pragma once

class NPC
{
public:
    NPC();
    ~NPC();
    SDL_FRect npcRect;
    SDL_Surface *spriteImage;
    SDL_Texture *sprite;
    void trackPlayer(const SDL_FRect *playerRect);
    void damagePlayer(const SDL_FRect *playerRect);

private:
    bool isColliding(const SDL_FRect *playerRect);
};