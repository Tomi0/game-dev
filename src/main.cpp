#include <SDL2/SDL.h>

#include "Game.hpp"
#include "Player.hpp"
#include "Window.hpp"

int main()
{
    Window *window = new Window("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
    Game *game = new Game();
    window->set_game(game);

    Uint64 start;
    Uint64 end;
    float elapsedMS;

    while (game->running()) {
        start = SDL_GetPerformanceCounter();
        
        game->handleEvents();
        game->update();
        window->render();

        end = SDL_GetPerformanceCounter();

        elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;

	    // Cap to 60 FPS
	    SDL_Delay(floor(16.666f - elapsedMS));
    }

    window->destroy();

    delete window;
    delete game;
  
    return 0;
}