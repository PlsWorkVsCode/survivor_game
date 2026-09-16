#include "death_menu.h"

death_menu::death_menu(){
    this->end_game = new button(500, 400, 80, 30, BLUE, "End Game", 10);
    this->restart_game = new button(600, 400, 80, 30, BLUE, "Restart Game", 10);
}

void death_menu::update(Vector2 mouse_position, player * player1, enemy_spawner * enemy_spawner1){
    if(this->end_game->update(mouse_position)){
        CloseWindow();
    }
    if(this->restart_game->update(mouse_position)){
        player1->x = 40;
        player1->y = 40;
        player1->health = 20;
        player1->fireball_damage = 2;
        player1->experience = 0;
        player1->fireball_amount = 1;
        player1->experience_amount = 1;
        player1->push_refresh = 25;
        player1->last_push_time = GetTime() - player1->push_refresh;
        player1->push_damage = 1;
        player1->dash_damage = 1;
        player1->dash_refresh = 20;
        player1->last_dash_time = GetTime() - player1->dash_refresh;
        player1->arrow_damage = 1;
        player1->arrow_amount = 1;
        enemy_spawner1->spawn_refresh_time = 10;
        enemy_spawner1->maximum_health_added = 10;
        for(int i = 0; i < enemy_spawner1->enemy_list.size(); i++){
            if(enemy_spawner1->enemy_list[i]){
                delete enemy_spawner1->enemy_list[i];
                enemy_spawner1->enemy_list[i] = nullptr;
            }
        }
        for(int j = 1; j < player1->fireball_list.size(); j++){
            if(player1->fireball_list[j]){
                delete player1->fireball_list[j];
                player1->fireball_list[j] = nullptr;
            }
        }
        for(int h = 1; h < player1->arrow_list.size(); h++){
            if(player1->arrow_list[h]){
                delete player1->arrow_list[h];
                player1->arrow_list[h] = nullptr;
            }
        }
    }
}

void death_menu::draw(){
    this->end_game->draw();
    this->restart_game->draw();
}

death_menu::~death_menu(){
    delete this->end_game;
    this->end_game = nullptr;
    delete this->restart_game;
    this->restart_game = nullptr;
}
