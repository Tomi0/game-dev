#pragma once

#include <SDL2/SDL.h>

class Player
{
private:
    const int movement_multiplier = 1;
    int x_movement;
    int y_movement;
    int x_pos;
    int y_pos;
    const int width = 10;
    const int height = 10;

public:
    Player();
    Player(int x_pos, int y_pos);
    void render(SDL_Renderer *renderer);
    void moving_left(bool is_moving);
    void moving_right(bool is_moving);
    void moving_up(bool is_moving);
    void moving_down(bool is_moving);
    void move();
};