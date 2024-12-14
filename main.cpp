#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void handlePlayerInput(SDL_Event e, SDL_Rect *playerPtr)
{

    int speed = 10;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    // keyStates works with continous presses
    const Uint8 *keyStates = SDL_GetKeyboardState(NULL);

    // Refactor this, does not work right when keys come up / down after pressing / holding
    // Moving up or down
    if (keyStates[SDL_SCANCODE_UP] ||
        keyStates[SDL_SCANCODE_W] ||
        keyStates[SDL_SCANCODE_DOWN] ||
        keyStates[SDL_SCANCODE_S])
    {
        playerPtr->y += keyStates[SDL_SCANCODE_UP] ||
                                keyStates[SDL_SCANCODE_W]
                            ? -speed
                            : speed;

        // and left
        if (keyStates[SDL_SCANCODE_LEFT] ||
            keyStates[SDL_SCANCODE_A])
            playerPtr->x -= speed;
        // and right
        else if (keyStates[SDL_SCANCODE_RIGHT] ||
                 keyStates[SDL_SCANCODE_D])
            playerPtr->x += speed;
    }
    // Moving left or right
    else if (keyStates[SDL_SCANCODE_LEFT] ||
             keyStates[SDL_SCANCODE_A] ||
             keyStates[SDL_SCANCODE_RIGHT] ||
             keyStates[SDL_SCANCODE_D])
    {
        playerPtr->x += keyStates[SDL_SCANCODE_LEFT] ||
                                keyStates[SDL_SCANCODE_A]
                            ? -speed
                            : speed;

        // and up
        if (keyStates[SDL_SCANCODE_UP] ||
            keyStates[SDL_SCANCODE_W])
            playerPtr->y -= speed;
        // and down
        else if (keyStates[SDL_SCANCODE_DOWN] ||
                 keyStates[SDL_SCANCODE_S])
            playerPtr->y += speed;
    }
}

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
    SDL_Rect playerRect = {windowWidth / 2 - 50, windowHeight / 2 - 50, 100, 100};
    SDL_Rect *playerPtr = &playerRect;

    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
            case SDL_KEYDOWN:
                handlePlayerInput(e, playerPtr);
            }

            // White
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

            SDL_RenderClear(renderer);

            SDL_RenderCopy(renderer, texture, NULL, &playerRect);

            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

// GAME PLAN
// HAVE GOOD PLAYER CONTROLS
// HAVE CAMERA FOLLOW THE PLAYER AROUND WHEN MOVING
// CREATE A VIEWPORT FOR THE PLAYER, HAVE THE VIEWPORT FOLLOW THE PLAYER SPRITE AROUND
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