#include "enemy.h"

enemy::enemy(double x, double y, double health, Color color){
    this->x = x;
    this->y = y;
    this->health = health;
    this->original_color = color;
}

void enemy::update(double x_position, double y_position){
    follow_player(x_position, y_position);
    if(this->health < 30) this->original_color = BLUE;
    else if(this->health < 50) this->original_color = ORANGE;
    else if(this->health < 70) this->original_color = YELLOW;
    else this->original_color = GREEN;
    if(GetTime() - this->last_damage_time > this->damage_refresh){
        this->color = this->original_color;
    }
}

void enemy::take_damage(double damage_taken){
    if(GetTime() - this->last_damage_time > this->damage_refresh){
        this->health -= damage_taken;
        this->last_damage_time = GetTime();
        this->color = RED;
    }
}

void enemy::follow_player(double x_position, double y_position){
    this->up = this->down = this->left = this->right = false;
    if(this->x > x_position){
        this->x -= 1;
        this->left = true;
    }
    if(this->x < x_position){
        this->x += 1;
        this->right = true;
    }
    if(this->y < y_position){
        this->y += 1;
        this->down = true;
    }
    if(this->y > y_position){
        this->y -= 1;
        this->up = true;
    }

}

void enemy::follow_player_movement(double player_movement_x, double player_movement_y){
    this->x += player_movement_x;
    this->y += player_movement_y;
}

void enemy::push(){
    if(this->up){
        this->y += 3;
    }
    if(this->down){
        this->y -= 3;
    }
    if(this->right){
        this->x -= 3;
    }
    if(this->left){
        this->x += 3;
    }
}


void enemy::draw(){
    DrawRectangle(this->x, this->y, this->width, this->height, this->color);
    DrawText(TextFormat("Health : %i" ,(int)this->health), this->x, this->y - 10, 10, WHITE);
}

