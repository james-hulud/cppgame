#include "basicghost.hpp"

BasicGhost::BasicGhost()
{
}

BasicGhost::~BasicGhost()
{
}

// void setRect(SDL_FRect npcRect) override
// {
// }

void BasicGhost::setRect(SDL_FRect npcRect)
{
    this->npcRect = npcRect;
}

SDL_FRect *BasicGhost::getRect()
{
    return &this->npcRect;
}