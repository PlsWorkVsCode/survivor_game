#include "menu.h"

void menu(Vector2 mouse_position, player * player1, bool * menu_on, enemy_spawner * enemy_spawner1){
    if(player1->experience >= player1->experience_amount){
        upgrade_player1->update(mouse_position, player1);
        upgrade_player1->draw();
        *menu_on = true;
        if(first_upgrade_refresh){
            upgrade_player1->refresh_buttons();
            first_upgrade_refresh = false;
        }
    }
    else if(player1->health <= 0){
        death_menu1->update(mouse_position, player1, enemy_spawner1);
        death_menu1->draw();
        *menu_on = true;
    }
    else{
        first_upgrade_refresh = true;
        *menu_on = false;
    }
}