#include <iostream>
#include "npc.hpp"

NPC::NPC()
{
    // TEMP, random coordinates for NPC spawn
    std::random_device rd;
    // seed
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(200, 800);

    npc_rect = (SDL_FRect){static_cast<float>(distr(gen)), static_cast<float>(distr(gen)), 200.0f, 100.0f};

    sprite_image = SDL_LoadBMP("./imgs/obunga.bmp");

    if (!sprite_image)
    {
        std::cout << "Could not get npc image" << std::endl;
        return;
    }
}

void NPC::track_player(const SDL_FRect &player_rect)
{
    // Direction vector
    float dx = player_rect.x - npc_rect.x;
    float dy = player_rect.y - npc_rect.y;

    float length = std::sqrt(dx * dx + dy * dy);
    if (length > 0.0f)
    {
        float speed = 0.01f;
        npc_rect.x += (dx / length) * speed;
        npc_rect.y += (dy / length) * speed;
    }
}

NPC::~NPC()
{
    SDL_FreeSurface(sprite_image);
}