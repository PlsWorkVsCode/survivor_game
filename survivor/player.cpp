#include "player.h"

player::player(){
    this->fireball_list.push_back(new fireball(0));
    // this->arrow_list.push_back(new arrow());
    // this->cannon_ball_list.push_back(new cannon_ball(this->x, this->y, 0));
}

void player::update(){
    for(int i = 0; i < this->fireball_list.size(); i++){
        if(this->fireball_list[i]) this->fireball_list[i]->update(this->x, this->y, this->width, this->height);
    }
    for(int j = 0; j < this->arrow_list.size(); j++){
        if(this->arrow_list[j]) this->arrow_list[j]->update();
    }
    for(int x = 0; x < this->cannon_ball_list.size(); x++){
        if(this->cannon_ball_list[x]){
            this->cannon_ball_list[x]->update();
            if(this->cannon_ball_list[x]->outside_bounds()){
                delete this->cannon_ball_list[x];
                this->cannon_ball_list[x] = nullptr;
            }
        }
    }
    if(GetTime() - this->last_cannon_ball > this->cannon_ball_refresh){
        for(int y = 0; y < this->cannon_ball_amount; y++){
            this->cannon_ball_list.push_back(new cannon_ball(this->x, this->y, y));
        }
        this->last_cannon_ball = GetTime();
    }
    if(GetTime() - this->last_damage_time > this->damage_refresh){
        this->color = WHITE;
    }
    if(GetTime() - this->last_push_time > this->push_time){
        this->pushing = false;
    }
    if(GetTime() - this->last_dash_time > this->dash_time){
        this->dashing = false;
    }
    if(GetTime() - this->last_up > this->dash_input_refresh){
        this->up = false;
    }
    if(GetTime() - this->last_down > this->dash_input_refresh){
        this->down = false;
    }
    if(GetTime() - this->last_right > this->dash_input_refresh){
        this->right = false;
    }
    if(GetTime() - this->last_left > this->dash_input_refresh){
        this->left = false;
    }
        
}

void player::take_damage(double damage_taken){
    if(GetTime() - this->last_damage_time > this->damage_refresh){
        this->health -= damage_taken;
        this->last_damage_time = GetTime();
        this->color = RED;
    }
}

void player::push(){
    if(GetTime() - this->last_push_time > this->push_refresh){
        this->last_push_time = GetTime();
        this->pushing = true;
    }
}

void player::dash(){
    if(GetTime() - this->last_dash_time > this->dash_refresh){
        this->dashing = true;
        this->last_dash_time = GetTime();
    }
    if(this->dashing){
        if(this->up){
            this->y -= this->dash_speed;
        }
        if(this->down){
            this->y += this->dash_speed;
        }
        if(this->left){
            this->x -= this->dash_speed;
        }
        if(this->right){
            this->x += this->dash_speed;
        }
    }
}

bool player::check_fireball_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height){
    for(int i = 0; i < fireball_list.size(); i++){
        if(this->fireball_list[i]){
            if(this->fireball_list[i]->check_collision(enemy_x, enemy_y, enemy_width, enemy_height)){
                return true;
            }
        }
    }
    return false;
}

bool player::check_arrow_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height){
    for(int i = 0; i < arrow_list.size(); i++){
        if(this->arrow_list[i]){
            if(this->arrow_list[i]->check_collision(enemy_x, enemy_y, enemy_width, enemy_height)){
                return true;
            }
        }
    }
    return false;
}

bool player::check_cannon_ball_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height){
    for(int i = 0; i < cannon_ball_list.size(); i++){
        if(this->cannon_ball_list[i]){
            if(this->cannon_ball_list[i]->check_collision(enemy_x, enemy_y, enemy_width, enemy_height)){
                return true;
            }
        }
    }
    return false;
}

void player::set_arrow_target_position(double enemy_x, double enemy_y, double arrow_number){
    for(int i = 0; i < arrow_list.size(); i++){
        if(arrow_list[i]){
            if(this->arrow_set_number == arrow_number){
                this->arrow_list[i]->set_target_position(enemy_x, enemy_y);
            }
            else{
                this->arrow_set_number++;
            }
        }
    }
    this->arrow_set_number = 1;
}

void player::move_projectiles(double player_movement_x, double player_movement_y){
    for(int i = 0; i < this->arrow_list.size(); i++){
        if(this->arrow_list[i]){
            this->arrow_list[i]->x += player_movement_x;
            this->arrow_list[i]->y += player_movement_y;
        }
    }
    for(int j = 0; j < this->cannon_ball_list.size(); j++){
        if(this->cannon_ball_list[j]){
            this->cannon_ball_list[j]->x += player_movement_x;
            this->cannon_ball_list[j]->y += player_movement_y;
        }
    }
}

void player::draw(){
    if(this->alive) DrawRectangle(this->x, this->y, this->width, this->height, this->color);
    for(int i = 0; i < fireball_list.size(); i++){
        if(fireball_list[i]) this->fireball_list[i]->draw();
    }
    for(int j = 0; j < arrow_list.size(); j++){
        if(arrow_list[j]){
            this->arrow_list[j]->draw();
        }
    }
    for(int x = 0; x < this->cannon_ball_list.size(); x++){
        if(this->cannon_ball_list[x]){
            this->cannon_ball_list[x]->draw();
        }
    }
    DrawText(TextFormat("Health : %i" ,(int)this->health), this->x, this->y - 10, 10, WHITE);
    DrawText(TextFormat("%i/%i" ,(int)this->experience, (int)this->experience_amount), this->x, this->y, 10, BLACK);
    DrawText(TextFormat("Push: %i/%i" ,(int)(GetTime() - this->last_push_time), (int)this->push_refresh), this->x, this->y + 
        this->height + 10, 10, WHITE);
    DrawText(TextFormat("Dash: %i/%i" ,(int)(GetTime() - this->last_dash_time), (int)this->dash_refresh), this->x, this->y + 
        this->height + 20, 10, WHITE);
}

player::~player(){
    for(int i = 0; i < fireball_list.size(); i++){
        delete this->fireball_list[i];
        this->fireball_list[i] = nullptr;
    }
    for(int j = 0; j < arrow_list.size(); j++){
        delete this->arrow_list[j];
        this->arrow_list[j] = nullptr;
    }
    for(int x = 0; x < this->cannon_ball_list.size(); x++){
        delete this->cannon_ball_list[x];
        this->cannon_ball_list[x] = nullptr;
    }
}