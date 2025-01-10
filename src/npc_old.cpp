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

    // Starts alive
    isDead = false;
}

NPC::~NPC()
{
    SDL_FreeSurface(spriteImage);
    // SDL_DestroyTexture(sprite);
}

void NPC::trackPlayer()
{
    // Direction vector
    float dx = player->getPlayerRect()->x - npcRect.x;
    float dy = player->getPlayerRect()->y - npcRect.y;

    float length = std::sqrt(dx * dx + dy * dy);
    if (length > 0.0f)
    {
        float speed = 0.01f;
        npcRect.x += (dx / length) * speed;
        npcRect.y += (dy / length) * speed;
    }
}

bool NPC::damagePlayer()
{
    return isColliding() ? true : false;
}

bool NPC::isColliding()
{
    if (SDL_HasIntersectionF(player->getPlayerRect(), &npcRect))
    {
        return true;
    }
    return false;
}

void NPC::setPlayer(Player *player)
{
    this->player = player;
}

void NPC::setID(int id)
{
    this->id = id;
}