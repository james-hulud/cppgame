#include <SDL2/SDL.h>
#include "npc.hpp"
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
    std::unordered_map<int, NPC *> mobs;
    std::vector<int> idsToRemove;

    void handleDeadEnemies();
};