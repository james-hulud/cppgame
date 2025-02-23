#include <iostream>
#include "game.hpp"

class GameObject
{
public:
    GameObject(std::string textureSheet, SDL_Renderer *renderer);
    ~GameObject();

    void update();
    void render();

private:
    int xpos;
    int ypos;

    SDL_Texture *objTexture;
    SDL_FRect srcRect, destRect;
    SDL_Renderer *renderer;
};