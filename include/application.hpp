#include <SDL2/SDL.h>
#include "npcmanager.hpp"
#pragma once

class Application
{
public:
    Application();
    ~Application();
    int windowWidth;
    int windowHeight;
    SDL_Renderer *renderer;
    NPCManager npcManager;
    void loop();

private:
    Player player;
    SDL_Window *window;
    SDL_Event event;
    void handleUserInput(float deltaTime);
    void draw();
};