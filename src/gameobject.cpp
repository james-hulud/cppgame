#include <iostream>
#include "gameobject.hpp"
#include "textureloader.hpp"

GameObject::GameObject(std::string textureSheet, SDL_Renderer *ren)
{
    renderer = ren;
    objTexture = TextureLoader::loadTexture(textureSheet, ren);
}

void GameObject::update()
{
    // update here
    xpos = 0;
    ypos = 0;

    srcRect.h = 32;
    srcRect.w = 32;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;

    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
    // render here
    SDL_RenderCopyF(renderer, objTexture, NULL, &destRect); // in og code NULL is obj's srcRect
}