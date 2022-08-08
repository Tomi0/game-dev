#include <SDL2/SDL.h>
#include <iostream>
#include "Window.hpp"
#include "Player.hpp"

Window::Window(const char* title, int x_window_pos, int y_window_pos, int width, int height, bool full_screen) {
    int flags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Unable to init SDL!" << std::endl;
        throw std::exception();
    }

    if (full_screen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, x_window_pos, y_window_pos, width, height, flags);
    if (!window) {
        std::cout << "Unable to create window" << std::endl;
        throw std::exception();
    }
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "Unable to create renderer" << std::endl;
        throw std::exception();
    }
}

void Window::set_game(Game *game) {
    this->game = game;
}

void Window::render() {
    SDL_RenderClear(renderer);
    this->Window::render_player(this->game->get_player());
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Window::render_player(Player *player) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect sdl_rect;
    sdl_rect.y = player->get_y_pos();
    sdl_rect.x = player->get_x_pos();
    sdl_rect.h = player->get_height();
    sdl_rect.w = player->get_width();
    SDL_RenderDrawRect(renderer, &sdl_rect);
    SDL_RenderFillRect(renderer, &sdl_rect);
}

void Window::destroy() {
    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL cleaned" << std::endl;
}