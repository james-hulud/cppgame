#include <iostream>
#include "application.hpp"
#include "player.hpp"
#include <SDL2/SDL.h>

Player::Player()
{
    player_rect = (SDL_FRect){0.0f, 0.0f, 100.0f, 100.0f};

    sprite_image = SDL_LoadBMP("./imgs/player.bmp");

    if (!sprite_image)
    {

        std::cout << "Could not get sprite image: " << SDL_GetError() << std::endl;
        return;
    }
}

Player::~Player()
{
    SDL_FreeSurface(sprite_image);
    // SDL_DestroyTexture(player_sprite);
}

void Player::move(float delta_time)
{
    float velocity = 100.0;
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    if (key_state[SDL_SCANCODE_UP] || key_state[SDL_SCANCODE_W])
        player_rect.y -= velocity * delta_time;

    if (key_state[SDL_SCANCODE_LEFT] || key_state[SDL_SCANCODE_A])
        player_rect.x -= velocity * delta_time;

    if (key_state[SDL_SCANCODE_DOWN] || key_state[SDL_SCANCODE_S])
        player_rect.y += velocity * delta_time;

    if (key_state[SDL_SCANCODE_RIGHT] || key_state[SDL_SCANCODE_D])
        player_rect.x += velocity * delta_time;
}