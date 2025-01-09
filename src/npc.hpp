#include <SDL2/SDL.h>
#include <random>
#include "player.hpp"
#pragma once

class NPC
{
public:
    NPC();
    ~NPC();
    SDL_FRect npcRect;
    SDL_Surface *spriteImage;
    SDL_Texture *sprite;
    void trackPlayer();
    bool damagePlayer();
    void setPlayer(Player *player);

private:
    bool isColliding();
    Player *player;
};