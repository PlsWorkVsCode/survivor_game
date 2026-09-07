#include "enemy_spawner.h"

enemy_spawner::enemy_spawner(){
    this->enemy_list.push_back(new enemy(1200, 800, 10, BLUE));
    srand(time(0));
}

void enemy_spawner::update(double x_position, double y_position, player * player1){
    if(GetTime() - this->last_level_up_time > this->level_up_time){
        this->maximum_health_added += 10;
        this->last_level_up_time = GetTime();
    }
    if(GetTime() - this->last_spawn_time > this->spawn_refresh_time){
        this->x_position = rand() % 1280 + 120;
        this->y_position = 850 * (rand() % 2) - 50;
        this->health = rand() % this->maximum_health_added + this->minimum_health;
        this->color = BLUE;
        this->enemy_list.push_back(new enemy(this->x_position, this->y_position, this->health, this->color));
        if(this->spawn_refresh_time > 1){
            this->spawn_refresh_time--;
        }
        this->last_spawn_time = GetTime();


    }
    for(int i = 0; i < this->enemy_list.size(); i++){
        if(this->enemy_list[i]){
            this->enemy_list[i]->update(x_position, y_position);
        }
    }
}

void enemy_spawner::draw(){
    for(int i = 0; i < this->enemy_list.size(); i++){
        if(this->enemy_list[i]){
            this->enemy_list[i]->draw();
        }
    }
}

enemy_spawner::~enemy_spawner(){
    for(int i = 0; i < this->enemy_list.size(); i++){
        if(this->enemy_list[i]){
            delete this->enemy_list[i];
            this->enemy_list[i] = nullptr;
        }
    }
}