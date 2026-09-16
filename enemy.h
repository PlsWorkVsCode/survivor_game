#include "raylib.h"
#include "player.h"
#include <iostream>
#pragma once

using namespace std;

class enemy{
    public:
    double x, y, height = 40, width = 40;
    double health = 20, damage = 2;
    double last_damage_time, damage_refresh = .3;
    bool up, down, left, right;
    Color color = WHITE, original_color = WHITE;
    enemy(double x, double y, double health, Color original_color);
    void update(double x_position, double y_position);
    void take_damage(double damage_taken);
    void follow_player(double x_position, double y_position);
    void follow_player_movement(double player_movement_x, double player_movement_y);
    void push();
    void draw();
};