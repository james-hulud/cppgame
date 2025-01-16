#include <iostream>
#include <SDL2/SDL.h>
#include "npc.hpp"

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
    void setPlayer(Player *player);

private:
    std::unordered_map<uintptr_t, NPC *> mobs;
    std::vector<uintptr_t> idsToRemove;
    Player *player;
    SDL_Renderer *renderer = NULL;
    void handleDeadNPCS();
};