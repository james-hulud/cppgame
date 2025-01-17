#include <iostream>
#include <SDL2/SDL.h>
#include "./include/game.hpp"

Game *game = nullptr;

int main()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return -1;

    game = new Game();
    game->init("Ghost survivors", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 800, false);

    Uint32 lastTime = SDL_GetTicks();
    const int FPS = 60; // Cap at 60fps
    float deltaTime;

    while (game->isRunning)
    {
        Uint32 start = SDL_GetTicks(); // Start of frame
        deltaTime = (start - lastTime) / 1000.0f;
        lastTime = start;

        game->handleEvents(deltaTime);
        game->update();
        game->render();

        if (1000 / FPS > lastTime - start) // End of frame
            SDL_Delay(1000 / FPS - (lastTime - start));
    }

    delete game;
    SDL_Quit();
    std::cout << "Game closed." << std::endl;
    return 0;
}