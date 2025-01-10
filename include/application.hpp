#include <SDL2/SDL.h>
// #include "player.hpp"
#include "npc.hpp"
#include "mob.hpp"
#include <list>
#pragma once

class Application
{
public:
    Application();
    ~Application();
    int windowWidth;
    int windowHeight;
    SDL_Renderer *renderer;
    void loop();

private:
    Player player;
    SDL_Window *window;
    SDL_Event event;
    void handleUserInput(float deltaTime);
    void draw();
    std::unordered_map<int, Mob> mobs;
};