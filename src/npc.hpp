#include <SDL2/SDL.h>
#include <random>
#pragma once

class NPC
{
public:
    NPC();
    ~NPC();
    SDL_FRect npc_rect;
    SDL_Surface *sprite_image;
    SDL_Texture *sprite;
    void track_player(const SDL_FRect &player_rect);
};