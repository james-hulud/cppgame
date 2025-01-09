#include <iostream>
#include "application.hpp"
#include "player.hpp"

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
        std::cout << "Could not initialise window: " << SDL_GetError() << std::endl;
        return;
    }

    // Set the window width and height
    SDL_GetWindowSize(window, &windowWidth, &windowHeight);

    // Init renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Could not initialise renderer: " << SDL_GetError() << std::endl;
        return;
    }

    // Init sprite here with renderer
    player.setSprite(SDL_CreateTextureFromSurface(renderer, player.getSpriteImage()));

    // Init NPC
    for (int i = 0; i < 10; i++)
    {
        NPC enemy = NPC();
        enemy.setPlayer(&player);
        enemy.sprite = SDL_CreateTextureFromSurface(renderer, enemy.spriteImage);
        mobs.emplace_back(enemy);
    }
}

Application::~Application()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(player.getSprite());
    for (NPC &mob : mobs)
    {
        SDL_DestroyTexture(mob.sprite);
    }
}

void Application::loop()
{
    Uint32 lastTime = SDL_GetTicks();

    bool quit = false;
    float deltaTime = 0.0f;

    while (!quit)
    {
        Uint32 currentTime = SDL_GetTicks();

        deltaTime = (currentTime - lastTime) / 1000.0f; // Bases deltaTime on the time the game has been running instead of the frame rate / loop iterations
        lastTime = currentTime;

        while (SDL_PollEvent(&event) != 0)
        {

            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        handleUserInput(deltaTime);
        std::list<NPC>::iterator i = mobs.begin();
        bool isColliding = false;
        while (i != mobs.end())
        {
            // Track the player
            i->trackPlayer();
            // if (i->damagePlayer())
            // {
            //     isColliding = true;
            // }
            i++;
        }

        if (isColliding)
            mobs.pop_back();

        draw();
    }
}

void Application::handleUserInput(float deltaTime)
{
    // keyState works with continous presses
    const Uint8 *keyState = SDL_GetKeyboardState(NULL);

    // Array of input keys. up, w, down, a, left, s, right, d
    SDL_Scancode movementKeys[] = {SDL_SCANCODE_UP, SDL_SCANCODE_W, SDL_SCANCODE_LEFT, SDL_SCANCODE_A, SDL_SCANCODE_DOWN, SDL_SCANCODE_S, SDL_SCANCODE_RIGHT, SDL_SCANCODE_D};

    // Check if keys are pressed
    for (std::size_t i = 0; i < sizeof(movementKeys) / sizeof(movementKeys[0]); i++)
    {
        if (keyState[movementKeys[i]])
        {
            player.move(deltaTime);
            break;
        }
    }
}

void Application::draw()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // Render player
    SDL_RenderCopyF(renderer, player.getSprite(), NULL, player.getPlayerRect());

    // Render enemies
    for (NPC &mob : mobs)
        SDL_RenderCopyF(renderer, mob.sprite, NULL, &mob.npcRect);

    SDL_RenderPresent(renderer);
}