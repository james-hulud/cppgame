#include "npcmanager.hpp"
#include "basicghost.hpp"

NPCManager::NPCManager()
{
}

NPCManager::~NPCManager()
{
    for (auto &i : mobs)
    {
        SDL_DestroyTexture(i.second->getSprite());
    }
}

/*
Creates a new NPC object.
Sets the player object,
the NPC unique id,
and the NPC sprite.
Stores the NPC object in the mobs map.
*/
void NPCManager::initNPC()
{
    if (renderer == NULL)
    {
        std::cout << "Renderer not initialised: " << SDL_GetError() << std::endl;
        return;
    }

    BasicGhost *ghost = new BasicGhost();
    uintptr_t id = reinterpret_cast<uintptr_t>(ghost);
    ghost->setPlayer(player);                                                      // Set player to track
    ghost->setID(id);                                                              // set mob ID
    ghost->setSprite(SDL_CreateTextureFromSurface(renderer, ghost->getSurface())); // create sprite
    mobs[id] = ghost;
}

void NPCManager::handleDeadNPCS()
{
    for (auto id : idsToRemove)
    {
        std::cout << id << std::endl;
        std::cout << mobs[id] << std::endl;
        mobs.erase(id);
    }

    idsToRemove.clear();
}

void NPCManager::setRenderer(SDL_Renderer *renderer)
{
    this->renderer = renderer;
}

void NPCManager::renderNPCS()
{
    // Render enemies
    for (auto &i : mobs)
    {
        if (!i.second->isDead())
            SDL_RenderCopyF(renderer, i.second->getSprite(), NULL, i.second->getRect());
    }
}

void NPCManager::executeNPCActions()
{
    // Execute all actions for each NPC
    for (auto &i : mobs)
    {
        i.second->trackPlayer(); // Track player location

        if (i.second->damagePlayer())
        {
            i.second->setDead(true);
            idsToRemove.emplace_back(i.second->getID());
        }
    }

    // Remove dead enemies from map
    handleDeadNPCS();

    std::cout << mobs.size() << std::endl;
}

void NPCManager::setPlayer(Player *player)
{
    this->player = player;
}