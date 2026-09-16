#include <iostream>

#include "enemy.h"
#include <vector>
#include <cstdlib>
#pragma once

using namespace std;

class enemy_spawner{
    public:
    vector<enemy*> enemy_list;
    double spawn_refresh_time = 10, last_spawn_time = 0;
    int minimum_health = 10, maximum_health_added = 10;
    double level_up_time = 60, last_level_up_time = 0;
    double x_position, y_position, health;
    Color color;
    enemy_spawner();
    void update(double x_position, double y_position, player * player1);
    void draw();
    ~enemy_spawner();
};