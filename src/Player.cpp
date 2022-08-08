#include "Player.hpp"
#include <iostream>

Player::Player() {
    this->x_pos = 0;
    this->y_pos = 0;
}

Player::Player(int x_pos, int y_pos) {
    this->x_pos = x_pos;
    this->y_pos = y_pos;
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

int Player::get_x_pos() { return this->x_pos; }
int Player::get_y_pos() { return this->y_pos; }
int Player::get_height() { return this->height; }
int Player::get_width() { return this->width; }