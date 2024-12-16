#include <iostream>
#include "application.hpp"
#include "player.hpp"
#include <SDL2/SDL.h>

// Player::Player()
// {
//     player_rect = SDL_FRect();
//     player_rect.x = 0.0f;
//     player_rect.y = 0.0f;
//     player_rect.w = 100.0f;
//     player_rect.h = 100.0f;

//     sprite_image = nullptr;
//     player_sprite = nullptr;
// };

Player::Player()
{
    player_rect = SDL_FRect();
    player_rect.x = 0.0f;
    player_rect.y = 0.0f;
    player_rect.w = 100.0f;
    player_rect.h = 100.0f;

    sprite_image = SDL_LoadBMP("./player.bmp");

    if (!sprite_image)
    {

        std::cout << "Could not get sprite image: " << SDL_GetError() << std::endl;
        return;
    }

    // player_sprite = SDL_CreateTextureFromSurface(renderer, sprite_image);

    // if (!player_sprite)
    // {
    //     std::cout << "Could not initialise sprite: " << SDL_GetError() << std::endl;
    //     return;
    // }
}

Player::~Player()
{
    SDL_FreeSurface(sprite_image);
    // SDL_DestroyTexture(player_sprite);
}

void Player::move(float delta_time)
{

    float velocity = 100.0;
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    // Array of input keys. up, w, down, a, left, s, right, d
    SDL_Scancode movementKeys[] = {SDL_SCANCODE_UP, SDL_SCANCODE_W, SDL_SCANCODE_LEFT, SDL_SCANCODE_A, SDL_SCANCODE_DOWN, SDL_SCANCODE_S, SDL_SCANCODE_RIGHT, SDL_SCANCODE_D};
    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W])
        player_rect.y -= velocity * delta_time;

    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A])
        player_rect.x -= velocity * delta_time;

    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S])
        player_rect.y += velocity * delta_time;

    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D])
        player_rect.x += velocity * delta_time;
}