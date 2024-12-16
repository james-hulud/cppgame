#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void handlePlayerMovement(SDL_FRect *playerPtr, float deltaTime)
{

    float velocity = 100.0;
    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
    // keyState works with continous presses
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    // Array of input keys. up, w, down, a, left, s, right, d
    SDL_Scancode movementKeys[] = {SDL_SCANCODE_UP, SDL_SCANCODE_W, SDL_SCANCODE_LEFT, SDL_SCANCODE_A, SDL_SCANCODE_DOWN, SDL_SCANCODE_S, SDL_SCANCODE_RIGHT, SDL_SCANCODE_D};

    // Check if keys are pressed
    bool isMoving = false;
    for (int i = 0; i < sizeof(movementKeys) / sizeof(movementKeys[0]); i++)
    {
        if (keyState[movementKeys[i]])
        {
            isMoving = true;
            break;
        }
    }

    if (keyState[SDL_SCANCODE_UP] || keyState[SDL_SCANCODE_W])
        playerPtr->y -= velocity * deltaTime;

    if (keyState[SDL_SCANCODE_LEFT] || keyState[SDL_SCANCODE_A])
        playerPtr->x -= velocity * deltaTime;

    if (keyState[SDL_SCANCODE_DOWN] || keyState[SDL_SCANCODE_S])
        playerPtr->y += velocity * deltaTime;

    if (keyState[SDL_SCANCODE_RIGHT] || keyState[SDL_SCANCODE_D])
        playerPtr->x += velocity * deltaTime;
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
    SDL_FRect playerRect = {windowWidth / 2.0 - 50.0, windowHeight / 2.0 - 50.0, 100.0, 100.0};
    SDL_FRect *playerPtr = &playerRect;

    Uint32 lastTime = SDL_GetTicks();
    float deltaTime = 0.0f;
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    while (!quit)
    {
        Uint32 currentTime = SDL_GetTicks();
        // cout << "currentTime:" << currentTime << endl;

        deltaTime = (currentTime - lastTime) / 1000.0f; // Bases deltaTime on the time the game has been running instead of the frame rate / loop iterations
        lastTime = currentTime;

        while (SDL_PollEvent(&e) != 0)
        {

            switch (e.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        handlePlayerMovement(playerPtr, deltaTime);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White
        SDL_RenderCopyF(renderer, texture, NULL, &playerRect);
        SDL_RenderPresent(renderer);
    }

    free(playerPtr);
    SDL_DestroyTexture(texture);
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