#include "Game.hpp"
#include <iostream>

Game::Game() {
    isRunning = true;
    player = new Player(20, 20);
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

bool Game::running() { return isRunning; }

Player* Game::get_player() {
    return player;
}