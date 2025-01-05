#include <iostream>
#include "npc.hpp"

NPC::NPC()
{
    npc_rect = (SDL_FRect){100.0f, 100.0f, 100.0f, 100.0f};

    sprite_image = SDL_LoadBMP("./imgs/temp.bmp");

    if (!sprite_image)
    {
        std::cout << "Could not get npc image" << std::endl;
        return;
    }
}

// NPC::track_player(SDLFRect player_rect) {
// }