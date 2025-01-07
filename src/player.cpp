#include <iostream>
#include "application.hpp"
#include "player.hpp"
#include <SDL2/SDL.h>

Player::Player()
{
    playerRect = (SDL_FRect){0.0f, 0.0f, 100.0f, 100.0f};

    setSpriteImage(SDL_LoadBMP("./imgs/player.bmp"));

    if (!spriteImage)
    {
        std::cout << "Could not get sprite image: " << SDL_GetError() << std::endl;
        return;
    }
}

Player::~Player()
{
    SDL_FreeSurface(spriteImage);
}

void Player::move(float deltaTime)
{
    float velocity = 100.0;
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W])
        playerRect.y -= velocity * deltaTime;

    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A])
        playerRect.x -= velocity * deltaTime;

    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S])
        playerRect.y += velocity * deltaTime;

    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D])
        playerRect.x += velocity * deltaTime;
}

SDL_Texture *Player::getSprite()
{
    return sprite;
}

void Player::setSprite(SDL_Texture *sprite)
{
    this->sprite = sprite;
}

SDL_Surface *Player::getSpriteImage()
{
    return spriteImage;
}

void Player::setSpriteImage(SDL_Surface *spriteImage)
{
    this->spriteImage = spriteImage;
}

SDL_FRect *Player::getPlayerRect()
{
    return &playerRect;
}