#include <SDL2/SDL.h>
#include "npcmanager.hpp"
#pragma once

class Game
{
public:
    Game();
    ~Game();

    int WINDOW_WIDTH;
    int WINDOW_HEIGHT;

    void loop();
    void update();
    void render();
    void init(std::string title, int xpos, int ypos, int width, int height, bool fullscreen);

private:
    bool isRunning;
    Player player;
    SDL_Window *window;
    SDL_Event event;
    SDL_Renderer *renderer;
    NPCManager npcManager;
    static SDL_Rect camera;
    void handleUserInput(float deltaTime);
    void handleEvents(float deltaTime);
};