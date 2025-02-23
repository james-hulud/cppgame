#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#pragma once

class TextureLoader
{
public:
    static SDL_Texture *loadTexture(std::string texture, SDL_Renderer *renderer);
};