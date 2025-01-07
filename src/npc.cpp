#include <iostream>
#include "npc.hpp"

NPC::NPC()
{
    // TEMP, random coordinates for NPC spawn
    std::random_device rd;
    // seed
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(200, 800);

    npcRect = (SDL_FRect){static_cast<float>(distr(gen)), static_cast<float>(distr(gen)), 200.0f, 100.0f};

    spriteImage = SDL_LoadBMP("./imgs/obunga.bmp");

    if (!spriteImage)
    {
        std::cout << "Could not get npc image" << std::endl;
        return;
    }
}

NPC::~NPC()
{
    SDL_FreeSurface(spriteImage);
}

void NPC::trackPlayer(const SDL_FRect *playerRect)
{
    // Direction vector
    float dx = playerRect->x - npcRect.x;
    float dy = playerRect->y - npcRect.y;

    float length = std::sqrt(dx * dx + dy * dy);
    if (length > 0.0f)
    {
        // float speed = 0.01f;
        float speed = 0.05f;
        npcRect.x += (dx / length) * speed;
        npcRect.y += (dy / length) * speed;
    }
}

void NPC::damagePlayer(const SDL_FRect *playerRect)
{
    isColliding(playerRect);
}

bool NPC::isColliding(const SDL_FRect *playerRect)
{
    // if npc x coord is between players x coord + or - playerWidth
    // and npx y coord is in same boundaries
    // return true else false
    std::cout << "Player coords" << std::endl;
    std::cout << playerRect->x << std::endl;
    std::cout << playerRect->y << std::endl;

    std::cout << "Enemy coords" << std::endl;
    std::cout << npcRect.x << std::endl;
    std::cout << npcRect.y << std::endl;
    return true;
}