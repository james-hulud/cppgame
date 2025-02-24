#include "gameobject.hpp"
#include "texturemanager.hpp"
#include "game.hpp"

GameObject::GameObject(std::string textureSheet, int x, int y)
{
    objTexture = TextureManager::loadTexture(textureSheet);
    xpos = x;
    ypos = y;
}

void GameObject::update()
{
    srcRect.h = 100;
    srcRect.w = 100;
    srcRect.x = 0;
    srcRect.y = 0;

    destRect.x = xpos;
    destRect.y = ypos;

    destRect.w = srcRect.w * 2;
    destRect.h = srcRect.h * 2;
}

void GameObject::render()
{
    SDL_RenderCopyF(Game::renderer, objTexture, NULL, &destRect); // temporary null
}

void GameObject::move(float deltaTime)
{
    float velocity = 100.0;
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W])
        ypos -= velocity * deltaTime;

    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A])
        xpos -= velocity * deltaTime;

    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S])
        ypos += velocity * deltaTime;

    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D])
        xpos += velocity * deltaTime;
}

SDL_FRect *GameObject::getRect()
{
    return &this->destRect;
}