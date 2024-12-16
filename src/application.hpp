#include <SDL2/SDL.h>

class Application
{
    Application();
    ~Application();

public:
    int window_width;
    int window_height;
    void loop();

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
    void draw();
};