#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#pragma once

class TextureManager
{
public:
    static SDL_Texture *loadTexture(std::string texture);
};