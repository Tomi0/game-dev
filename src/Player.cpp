#include "Player.hpp"
#include <SDL2/SDL.h>
#include <iostream>

Player::Player() {
    this->x_pos = 0;
    this->y_pos = 0;
}

Player::Player(int x_pos, int y_pos) {
    this->x_pos = x_pos;
    this->y_pos = y_pos;
}

void Player::render(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_Rect sdl_rect;
    sdl_rect.y = this->y_pos;
    sdl_rect.x = this->x_pos;
    sdl_rect.h = this->height;
    sdl_rect.w = this->width;
    SDL_RenderDrawRect(renderer, &sdl_rect);
    SDL_RenderFillRect(renderer, &sdl_rect);
}

void Player::moving_left(bool is_moving) {
    if (is_moving) {
        this->x_movement = -this->movement_multiplier;
    } else {
        this->x_movement = 0;
    }
}

void Player::moving_right(bool is_moving) {
    if (is_moving) {
        this->x_movement = this->movement_multiplier;
    } else {
        this->x_movement = 0;
    }
}

void Player::moving_up(bool is_moving) {
    if (is_moving) {
        this->y_movement = -this->movement_multiplier;
    } else {
        this->y_movement = 0;
    }
}

void Player::moving_down(bool is_moving) {
    if (is_moving) {
        this->y_movement = this->movement_multiplier;
    } else {
        this->y_movement = 0;
    }
}

void Player::move() {
    this->x_pos += this->x_movement;
    this->y_pos += this->y_movement;
}