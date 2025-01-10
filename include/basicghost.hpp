#include <SDL2/SDL.h>
#include "mob.hpp"
#include "npc.hpp"

// Implements
class BasicGhost : virtual public NPC, virtual public Mob
{
public:
    BasicGhost();
    ~BasicGhost();

    void setRect(SDL_FRect npcRect) override;
    SDL_FRect *getRect() override;
    void *setSurface() override;
    SDL_Surface *getSurface() override;
    void setSprite(SDL_Texture *sprite) override;
    SDL_Texture *getSprite() override;
    bool isPlayerColliding() override;

    void trackPlayer() override;
    bool damagePlayer() override;
    void setPlayer(Player *player) override;
    void setDead(bool dead) override;
    bool isDead() override;
    void setID(int id) override;
    int getID() override;

private:
    SDL_FRect npcRect;
    SDL_Surface *spriteImage;
    SDL_Texture *sprite;
    Player *player;
    bool isDead;
    int id;
};