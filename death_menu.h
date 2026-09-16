#include "raylib.h"
#include "button.h"
#include "player.h"
#include "enemy_spawner.h"
#pragma once

class death_menu{
    public:
    button * end_game, * restart_game;
    death_menu();
    void update(Vector2 mouse_position, player * player1, enemy_spawner * enemy_spawner1);
    void draw();
    ~death_menu();
};