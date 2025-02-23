#include <SDL2/SDL.h>
#pragma once

class Player
{
public:
    Player();                                                 // default constructor
    Player(std::string textureImage, SDL_Renderer *renderer); // non-default constructor
    ~Player();
    void move(float deltaTime);
    // SDL_Texture *getSprite();
    // void setSprite(SDL_Texture *playerSprite);
    SDL_Texture *getSprite();
    // void setSpriteImage(SDL_Surface *spriteImage);
    SDL_FRect *getPlayerRect();

private:
    SDL_Texture *texture;
    SDL_FRect playerRect;
};