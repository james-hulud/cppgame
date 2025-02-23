#include <SDL2/SDL.h>
#include <iostream>
#pragma once

class GameObject
{
public:
    GameObject(std::string textureSheet, SDL_Renderer *renderer);
    ~GameObject();

    void update();
    void render();
    void move(float deltaTime);
    SDL_FRect *getRect();

private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_Rect srcRect;
    SDL_FRect destRect;
    SDL_Renderer *renderer;
};