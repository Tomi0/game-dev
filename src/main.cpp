#include <SDL2/SDL.h>

#include "Game.hpp"
#include "Player.hpp"

int main()
{
    Game *game = new Game();
    Player *player = new Player(50, 50);

    game->set_player(player);
    game->init_window("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    Uint64 start;
    Uint64 end;

    while (game->running())
    {
        start = SDL_GetPerformanceCounter();
        
        game->handleEvents();
        game->update();
        game->render();

        end = SDL_GetPerformanceCounter();

        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

	    // Cap to 60 FPS
	    SDL_Delay(floor(16.666f - elapsedMS));
    }

    game->clean();
  
    return 0;
}