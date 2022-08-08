#pragma once
#include <SDL2/SDL.h>
#include "Player.hpp"

class Game
{
private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Player *player;

public:
    Game();
    void init_window(const char* title, int x_window_pos, int y_window_pos, int width, int height, bool full_screen);
    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();
    void set_player(Player *player);
};