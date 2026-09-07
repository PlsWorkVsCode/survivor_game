#include <cmath>
#include <iostream>
#include "raylib.h"
#pragma once

using namespace std;

class fireball{
    public:
    double x, y, radius = 10;
    double fireball_amount;
    Color color = RED;
    fireball(double fireball_amount);
    void update(double player_x, double player_y, double player_width, double player_height);
    bool check_collision(double x_position, double y_position, double width, double height);
    void draw();
};