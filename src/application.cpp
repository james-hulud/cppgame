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
    SDL_GetWindowSize(window, &window_width, &window_height);

    // Init renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (!renderer)
    {
        std::cout << "Could not initialise renderer: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Event event;

    // player = Player(renderer);
    player_sprite = SDL_CreateTextureFromSurface(renderer, player.sprite_image);
}

Application::~Application()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

void Application::loop()
{
    Uint32 last_time = SDL_GetTicks();

    bool quit = false;
    float delta_time = 0.0f;
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    while (!quit)
    {
        Uint32 current_time = SDL_GetTicks();

        delta_time = (current_time - last_time) / 1000.0f; // Bases deltaTime on the time the game has been running instead of the frame rate / loop iterations
        last_time = current_time;

        while (SDL_PollEvent(&event) != 0)
        {

            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            }
        }

        handle_user_input(delta_time);
        draw();
    }
}

void Application::handle_user_input(float delta_time)
{
    // keyState works with continous presses
    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    // Array of input keys. up, w, down, a, left, s, right, d
    SDL_Scancode movement_keys[] = {SDL_SCANCODE_UP, SDL_SCANCODE_W, SDL_SCANCODE_LEFT, SDL_SCANCODE_A, SDL_SCANCODE_DOWN, SDL_SCANCODE_S, SDL_SCANCODE_RIGHT, SDL_SCANCODE_D};

    // Check if keys are pressed
    bool is_moving = false;
    for (int i = 0; i < sizeof(movement_keys) / sizeof(movement_keys[0]); i++)
    {
        if (key_state[movement_keys[i]])
        {
            is_moving = true;
            break;
        }
    }

    player.move(delta_time);
}

void Application::draw()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderCopyF(renderer, player_sprite, NULL, &player.player_rect);
    SDL_RenderPresent(renderer);
}