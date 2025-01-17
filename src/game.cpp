#include <iostream>
#include "game.hpp"
#include "player.hpp"
#include "basicghost.hpp"

SDL_Rect Game::camera = {0, 0, 500, 500};

Game::Game()
{
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(player.getSprite());
}

void Game::init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;

    if (fullscreen)
        flags = SDL_WINDOW_FULLSCREEN;

    window = SDL_CreateWindow(
        title.c_str(),
        xpos,
        ypos,
        width,
        height,
        flags);

    if (!window)
    {
        std::cout << "Could not initialise window: " << SDL_GetError() << std::endl;
        return;
    }

    // Set the window width and height
    SDL_GetWindowSize(window, &WINDOW_WIDTH, &WINDOW_HEIGHT);

    // Init renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Could not initialise renderer: " << SDL_GetError() << std::endl;
        return;
    }

    // Init sprite here with renderer
    player.setSprite(SDL_CreateTextureFromSurface(renderer, player.getSpriteImage()));
    npcManager.setRenderer(renderer);
    npcManager.setPlayer(&player);

    for (int i = 0; i < 5; i++)
    {
        npcManager.initNPC();
    }

    isRunning = true;
}

void Game::loop()
{
    Uint32 lastTime = SDL_GetTicks();

    const int FPS = 60;
    float deltaTime;

    while (isRunning)
    {
        // Start of frame
        Uint32 start = SDL_GetTicks();
        deltaTime = (start - lastTime) / 1000.0f; // Bases deltaTime on the time the game has been running instead of the frame rate / loop iterations
        lastTime = start;

        handleEvents(deltaTime);
        update();
        render();

        // End of frame
        if (1000 / FPS > lastTime - start)
            SDL_Delay(1000 / FPS - (lastTime - start));
    }

    std::cout << "Game terminated successfully." << std::endl;
}

void Game::handleUserInput(float deltaTime)
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

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // Render player
    SDL_RenderCopyF(renderer, player.getSprite(), NULL, player.getPlayerRect());

    // Renders all NPCs
    npcManager.renderNPCS();
    SDL_RenderPresent(renderer);
}

void Game::handleEvents(float deltaTime)
{
    while (SDL_PollEvent(&event) != 0)
    {
        switch (event.type)
        {
        case SDL_QUIT:
            isRunning = false;
            break;
        }
    }
    handleUserInput(deltaTime);
}

void Game::update()
{
    npcManager.executeNPCActions();
}