#include "raylib.h"
#include "fireball.h"
#include "arrow.h"
#include "cannon_ball.h"
#pragma once

class player{
    public:
    double x = 620, y = 380, height = 40, width = 40;
    double health = 20, fireball_damage = 2, experience = 0, movement_speed = 7;
    double fireball_amount = 1, experience_amount = 1;
    double last_damage_time = 0, damage_refresh = .3;
    double push_refresh = 25, last_push_time = -25, push_time = 1, push_damage = 1;
    double dash_refresh = 20, last_dash_time = -20, dash_time = 1, dash_damage = 1, dash_speed = 25;
    bool alive = true, pushing = false, dashing = false;
    bool up = false, down = false, left = false, right = false;
    double last_up = 0, last_down = 0, last_right = 0, last_left = 0, dash_input_refresh = .25;
    double arrow_damage = 1, arrow_amount = 1, arrow_set_number = 1;
    double cannon_ball_amount = 0, cannon_ball_damage = 5, last_cannon_ball = GetTime();
    double cannon_ball_refresh = 10;
    vector<fireball*> fireball_list;
    vector<arrow*> arrow_list;
    vector<cannon_ball*> cannon_ball_list;
    Color color = WHITE;
    player();
    void update();
    void take_damage(double damage_taken);
    void push();
    void dash();
    bool check_fireball_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height);
    bool check_arrow_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height);
    bool check_cannon_ball_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height);
    void set_arrow_target_position(double enemy_x, double enemy_y, double arrow_number);
    void move_projectiles(double player_movement_x, double player_movement_y);
    void draw();
    ~player();
};