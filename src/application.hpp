#include <SDL2/SDL.h>
#include "player.hpp"
#pragma once

class Application
{
public:
    Application();
    ~Application();
    int window_width;
    int window_height;
    SDL_Renderer *renderer;
    void loop();

private:
    Player player;
    SDL_Texture *player_sprite;
    SDL_Window *window;
    SDL_Event event;
    void handle_user_input(float delta_time);
    void draw();

    SDL_Texture *npc_sprite;
};