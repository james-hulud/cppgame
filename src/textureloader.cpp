#include "textureloader.hpp"

SDL_Texture *TextureLoader::loadTexture(std::string texturePath, SDL_Renderer *ren)
{
    SDL_Surface *loadedSurface = IMG_Load(texturePath.c_str());
    SDL_Texture *texture = NULL;

    if (!loadedSurface)
    {
        std::cout << "Could not load texture surface: " << SDL_GetError() << std::endl;
    }

    texture = SDL_CreateTextureFromSurface(ren, loadedSurface);

    if (!texture)
    {
        std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
    }

    SDL_FreeSurface(loadedSurface);

    std::cout << "texture here" << std::endl;
    std::cout << texture << std::endl;

    return texture;
}