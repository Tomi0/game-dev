#include <SDL2/SDL.h>

#include "Game.hpp"

int main()
{
    Game *game = new Game();

    game->init_window("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, false);

    while (game->running())
    {
        game->handleEvents();
        game->update();
        game->render();
    }

    game->clean();
  
    return 0;
}