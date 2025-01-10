#include <SDL2/SDL.h>
#pragma once

class Player
{
public:
    Player();                       // default constructor
    Player(SDL_Renderer *renderer); // non-default constructor
    ~Player();
    void move(float deltaTime);
    SDL_Texture *getSprite();
    void setSprite(SDL_Texture *playerSprite);
    SDL_Surface *getSpriteImage();
    void setSpriteImage(SDL_Surface *spriteImage);
    SDL_FRect *getPlayerRect();

private:
    SDL_Texture *sprite;
    SDL_FRect playerRect;
    SDL_Surface *spriteImage;
};