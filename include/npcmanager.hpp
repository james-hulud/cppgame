#include <iostream>
#include <SDL2/SDL.h>
#include "gameobject.hpp"
#include "npc.hpp"
#pragma once

/*
Responsible for managing all NPCs,
initialising individual NPC properties,
handling NPC states, spawning NPCs,
*/
class NPCManager
{
public:
    NPCManager();
    ~NPCManager();
    void initNPC();
    void setRenderer(SDL_Renderer *renderer);
    void renderNPCS();
    void executeNPCActions();
    void setPlayer(GameObject *player);

private:
    std::unordered_map<uintptr_t, NPC *> mobs;
    std::vector<uintptr_t> idsToRemove;
    GameObject *player;
    SDL_Renderer *renderer = NULL;
    void handleDeadNPCS();
};