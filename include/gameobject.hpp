#include "game.hpp"

class GameObject
{
public:
    GameObject(SDL_Renderer *renderer);
    ~GameObject();

private:
    int xpos;
    int ypos;
};