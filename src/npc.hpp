#include <SDL2/SDL.h>
#pragma once

class NPC
{
public:
    NPC();
    ~NPC();
    SDL_FRect npc_rect;
    SDL_Surface *sprite_image;
    void track_player(float delta_time);
};