#include <SDL2/SDL.h>
#pragma once

class Player
{
public:
    Player();                       // default constructor
    Player(SDL_Renderer *renderer); // non-default constructor
    ~Player();
    SDL_FRect player_rect;
    SDL_Surface *sprite_image;
    SDL_Texture *sprite;
    void move(float delta_time);

private:
};