#include <iostream>
#include <SDL2/SDL.h>
#include "./src/application.hpp"

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

    Application app;

    // Main game loop
    app.loop();

    SDL_Quit();
    return 0;
}