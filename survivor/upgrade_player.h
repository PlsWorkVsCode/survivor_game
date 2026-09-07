#include "button.h"
#include "player.h"
#pragma once

class upgrade_player{
    public:
    button * new_fireball, * more_fireball_damage, * faster_push_cooldown, * more_push_damage,
        * faster_dash_cooldown, * more_dash_damage, * new_arrow, * more_arrow_damage,
        * more_cannon_balls, * faster_cannon_ball_cooldown;
    vector<button*> button_list;
    int first_button, second_button, third_button;
    upgrade_player();
    void update(Vector2 mouse_position, player * player1);
    void refresh_buttons();
    void draw();
    ~upgrade_player();
};