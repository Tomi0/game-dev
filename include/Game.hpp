#pragma once
#include <SDL2/SDL.h>
#include "Player.hpp"

class Game
{
private:
    bool isRunning;
    Player *player;

public:
    Game();
    void handleEvents();
    void update();
    bool running();
    void set_player(Player *player);
    Player* get_player();
};