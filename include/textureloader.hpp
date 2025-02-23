#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class TextureLoader
{
public:
    static SDL_Texture *loadTexture(std::string texture, SDL_Renderer *renderer);
};