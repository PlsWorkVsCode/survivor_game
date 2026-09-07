#include "raylib.h"
#include "cmath"
#pragma once
using namespace std;

class arrow{
    public:
    double x = 620, y = 380, height = 10, angle = 40;
    Color color = PURPLE;
    double enemy_x = 620, enemy_y = 380;
    double side1x, side1y, side2x, side2y, side3x, side3y;
    arrow();
    void update();
    void move_to_enemy(double enemy_x, double enemy_y);
    void set_target_position(double enemy_x, double enemy_y);
    void draw();
    bool check_collision(double x_position, double y_position, double width, double height);
};