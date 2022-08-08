#include "Game.hpp"
#include <stdexcept>
#include <iostream>

Game::Game() {}

void Game::init_window(const char* title, int x_window_pos, int y_window_pos, int width, int height, bool full_screen) {
    int flags = 0;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Unable to init SDL!" << std::endl;
        throw std::exception();
    }
    std::cout << "SDL initialised" << std::endl;

    if (full_screen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    window = SDL_CreateWindow(title, x_window_pos, y_window_pos, width, height, flags);
    if (!window) {
        std::cout << "Unable to create window" << std::endl;
        throw std::exception();
    }
    std::cout << "Window created" << std::endl;
    
    renderer = SDL_CreateRenderer(window, -1, 0);
    if (!renderer) {
        std::cout << "Unable to create renderer" << std::endl;
        throw std::exception();
    }
    std::cout << "Renderer created" << std::endl;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    isRunning = true;
}

void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                isRunning = false;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        this->player->moving_left(true);
                        break;
                    case SDLK_RIGHT:
                        this->player->moving_right(true);
                        break;
                    case SDLK_UP:
                        this->player->moving_up(true);
                        break;
                    case SDLK_DOWN:
                        this->player->moving_down(true);
                        break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        this->player->moving_left(false);
                        break;
                    case SDLK_RIGHT:
                        this->player->moving_right(false);
                        break;
                    case SDLK_UP:
                        this->player->moving_up(false);
                        break;
                    case SDLK_DOWN:
                        this->player->moving_down(false);
                        break;
                }
                break;
            default:
                break;
        }
    }
}

void Game::update() {
    this->player->move();
}

void Game::render() {
    SDL_RenderClear(renderer);
    this->player->render(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}

void Game::clean() {
    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    std::cout << "SDL cleaned" << std::endl;
}

bool Game::running() { return isRunning; }

void Game::set_player(Player *player) {
    this->player = player;
}