#pragma once
#include <SDL2/SDL.h>
#include "Game.hpp"
#include "Player.hpp"

class Window
{
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    Game *game;

    void render_player(Player *player);

public:
    Window(const char* title, int x_window_pos, int y_window_pos, int width, int height, bool full_screen);
    void set_game(Game *game);
    void render();
    void destroy();
};