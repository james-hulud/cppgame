#include <SDL2/SDL.h>
#pragma once

class Player
{
public:
    Player();                       // default constructor
    Player(SDL_Renderer *renderer); // non-default constructor
    ~Player();
    // SDL_Texture *player_sprite;
    SDL_FRect player_rect;
    SDL_Surface *sprite_image;
    void move(float delta_time);

private:
};