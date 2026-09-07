#include "raylib.h"
#include "cmath"
#include "iostream"

using namespace std;


class cannon_ball{
    public:
    double x, y, radius = 15;
    Color color = ORANGE; 
    double cannon_ball_number;
    double circle_interval = 4, circle_power = 0, starting_number = 0;
    bool continue_circle_calc = true;
    double movement_speed = 1;
    cannon_ball(double original_x, double original_y, double cannon_ball_number);
    void update();
    bool outside_bounds();
    bool check_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height);
    void draw();
};