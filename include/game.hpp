#include <SDL2/SDL.h>
#include "gameobject.hpp"
#include "npcmanager.hpp"
#include <iostream>
#pragma once

class Game
{
public:
    Game();
    ~Game();

    bool isRunning;

    void init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen);
    void handleEvents(float deltaTime);
    void update();
    void render();

private:
    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;
    GameObject *player;
    SDL_Window *window;
    SDL_Event event;
    SDL_Renderer *renderer;
    NPCManager npcManager;
    static SDL_Rect camera;
    void handleUserInput(float deltaTime);
};