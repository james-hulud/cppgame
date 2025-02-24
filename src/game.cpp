#include "game.hpp"

SDL_Rect Game::camera = {0, 0, 500, 500};

Game::Game()
{
}

Game::~Game()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
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

    player = new GameObject("/Users/james/repos/cppgame/imgs/john-snow.svg", renderer, 0, 0);
    npcManager.setRenderer(renderer);
    npcManager.setPlayer(player);

    for (int i = 0; i < 5; i++)
    {
        npcManager.initNPC();
    }

    isRunning = true;
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
            std::cout << "player moving" << std::endl;
            player->move(deltaTime);
            break;
        }
    }
}

void Game::render()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    player->render();

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
    player->update();
    npcManager.executeNPCActions();
}