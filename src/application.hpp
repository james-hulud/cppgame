#include <SDL2/SDL.h>
#include "player.hpp"
#include "npc.hpp"
#include <list>
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
    SDL_Window *window;
    SDL_Event event;
    void handle_user_input(float delta_time);
    void draw();
    std::list<NPC> mobs;
};