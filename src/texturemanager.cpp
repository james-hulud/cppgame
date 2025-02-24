#include "texturemanager.hpp"
#include "game.hpp"

SDL_Texture *TextureManager::loadTexture(std::string texturePath)
{
    SDL_Surface *loadedSurface = IMG_Load(texturePath.c_str());
    SDL_Texture *texture = NULL;

    if (!loadedSurface)
    {
        std::cout << "Could not load texture surface: " << SDL_GetError() << std::endl;
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(Game::renderer, loadedSurface);

    if (!texture)
    {
        std::cout << "Could not create texture: " << SDL_GetError() << std::endl;
        return NULL;
    }

    SDL_FreeSurface(loadedSurface);

    std::cout << "texture here" << std::endl;

    return texture;
}