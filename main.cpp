#include <iostream>
#include <SDL2/SDL.h>

void print(std::string input)
{
    std::cout << input << std::endl;
    return;
}

int main()
{
    std::cout << "Output here" << std::endl;
    // Create window
    SDL_Window *window = SDL_CreateWindow(
        "Monster Brawler",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        200,
        200,
        0);

    SDL_Surface *surface = SDL_GetWindowSurface(window);

    // Fill surface then update it
    SDL_FillRect(
        surface,
        NULL,
        SDL_MapRGB(surface->format, 0xFF, 0xFF, 0xFF));

    // Update it here
    SDL_UpdateWindowSurface(window);
    SDL_Event e;
    bool quit = false;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                print("Quitting");
                quit = true;
            }
            SDL_UpdateWindowSurface(window);
        }
    }

    return 0;
}