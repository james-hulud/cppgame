#include <iostream>
#include "player.hpp"
#include <SDL2/SDL.h>
#include "textureloader.hpp"

Player::Player()
{
    playerRect = (SDL_FRect){0.0f, 0.0f, 100.0f, 100.0f};
}

Player::Player(std::string textureImage, SDL_Renderer *ren)
{
    playerRect = (SDL_FRect){0.0f, 0.0f, 100.0f, 100.0f};

    texture = TextureLoader::loadTexture(textureImage, ren);

    if (!texture)
    {
        std::cout << "Could not get load texture: " << SDL_GetError() << std::endl;
        return;
    }
}

Player::~Player()
{
    SDL_DestroyTexture(texture);
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
    return texture;
}

SDL_FRect *Player::getPlayerRect()
{
    return &playerRect;
}