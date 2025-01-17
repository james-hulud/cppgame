#include <iostream>
#include <SDL2/SDL.h>
#include "./include/game.hpp"

// GAME PLAN
// HAVE CAMERA FOLLOW THE PLAYER AROUND WHEN MOVING
// CREATE A VIEWPORT FOR THE PLAYER, HAVE THE VIEWPORT FOLLOW THE PLAYER SPRITE AROUND
// HAVE THE WINDOW FOLLOW THE PLAYER SPRITE AROUND AS THEY MOVE

int main()
{
    std::cout << "Output here" << std::endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return -1;
    }

    Game game;
    game.init("Ghost survivors", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, false);

    // Main game loop
    game.loop();

    SDL_Quit();
    return 0;
}