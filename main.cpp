#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void gameLoop(SDL_Window *window)
{
    SDL_Surface *image = SDL_LoadBMP("./player.bmp");
    SDL_Event e;
    bool quit = false;

    // Renderer is better than SDL_Surface, surface is CPU bound whereas renderer is GPU
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Create texture for image
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    SDL_FreeSurface(image);

    int windowWidth, windowHeight;

    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    cout << windowWidth << " " << windowHeight << endl;

    // the 50 is halfway across the rect and halfway down
    SDL_Rect rect = {windowWidth / 2 - 50, windowHeight / 2 - 50, 100, 100};

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }

            // White
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, texture, NULL, &rect);

            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

// GAME PLAN
// GET A PLAYER SPRITE RENDERED ON THE SCREEN
// HAVE GOOD PLAYER CONTROLS
// HAVE THE WINDOW FOLLOW THE PLAYER SPRITE AROUND AS THEY MOVE

int main()
{
    cout << "Output here" << endl;

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        return -1;
    }

    // Create window
    SDL_Window *window = SDL_CreateWindow(
        "Ghost Surviors",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1000,
        800,
        0);

    // Update it here
    SDL_UpdateWindowSurface(window);

    gameLoop(window);

    SDL_Quit();
    return 0;
}