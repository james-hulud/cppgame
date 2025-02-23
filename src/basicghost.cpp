#include "basicghost.hpp"

BasicGhost::BasicGhost()
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
    dead = false;
}

BasicGhost::~BasicGhost()
{
    if (spriteImage)
        SDL_FreeSurface(spriteImage);
    if (sprite)
        SDL_DestroyTexture(sprite);
    if (player)
        player = nullptr;
}

void BasicGhost::trackPlayer()
{
    // Direction vector
    float dx = player->getRect()->x - npcRect.x;
    float dy = player->getRect()->y - npcRect.y;

    float length = std::sqrt(dx * dx + dy * dy);
    if (length > 0.0f)
    {
        float speed = 0.5f;
        npcRect.x += (dx / length) * speed;
        npcRect.y += (dy / length) * speed;
    }
}

bool BasicGhost::damagePlayer()
{
    return isPlayerColliding() ? true : false;
}

bool BasicGhost::isPlayerColliding()
{
    if (SDL_HasIntersectionF(player->getRect(), &npcRect))
    {
        return true;
    }
    return false;
}