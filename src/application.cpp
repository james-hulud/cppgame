#include <iostream>
#include "application.hpp"

// Calling the constructor
Application::Application()
{
    window = SDL_CreateWindow(
        "Ghost Surviors",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1000,
        800,
        0);

    if (!window)
    {
        std::cout << SDL_GetError() << std::endl;
        return;
    }

    // Set the window width and height
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Init renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << SDL_GetError() << std::endl;
        return;
    }

    SDL_Event event;
}

Application::~Application()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

// TODO
void Application::loop()
{
}