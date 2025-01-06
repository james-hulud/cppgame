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

    // Init sprite here with renderer
    player.sprite = SDL_CreateTextureFromSurface(renderer, player.sprite_image);

    // Init NPC
    for (int i = 0; i < 5; i++)
    {
        NPC enemy = NPC();
        enemy.sprite = SDL_CreateTextureFromSurface(renderer, enemy.sprite_image);
        mobs.emplace_back(enemy);
    }
}

Application::~Application()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyTexture(player.sprite);
    for (NPC &mob : mobs)
    {
        SDL_DestroyTexture(mob.sprite);
    }
}

void Application::loop()
{
    Uint32 last_time = SDL_GetTicks();

    bool quit = false;
    float delta_time = 0.0f;

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
        for (NPC &mob : mobs)
            mob.track_player(player.player_rect);
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
    for (std::size_t i = 0; i < sizeof(movement_keys) / sizeof(movement_keys[0]); i++)
    {
        if (key_state[movement_keys[i]])
        {
            player.move(delta_time);
            break;
        }
    }
}

void Application::draw()
{
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // Render player
    SDL_RenderCopyF(renderer, player.sprite, NULL, &player.player_rect);

    // Render enemies
    for (NPC &mob : mobs)
        SDL_RenderCopyF(renderer, mob.sprite, NULL, &mob.npc_rect);

    SDL_RenderPresent(renderer);
}