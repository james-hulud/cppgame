#include "npc.hpp"

void NPC::setRect(SDL_FRect npcRect)
{
    this->npcRect = npcRect;
}

SDL_FRect *NPC::getRect()
{
    return &this->npcRect;
}

void NPC::setSurface(SDL_Surface *surface)
{
    this->spriteImage = surface;
}

SDL_Surface *NPC::getSurface()
{
    return this->spriteImage;
}

void NPC::setSprite(SDL_Texture *sprite)
{
    this->sprite = sprite;
}

SDL_Texture *NPC::getSprite()
{
    return this->sprite;
}

void NPC::setID(int id)
{
    this->id = id;
}

uint32_t NPC::getID()
{
    return this->id;
}

void NPC::setDead(bool dead)
{
    this->dead = dead;
}

bool NPC::isDead()
{
    return this->dead;
}

void NPC::setPlayer(GameObject *player)
{
    this->player = player;
}