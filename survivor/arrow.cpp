#include "arrow.h"

arrow::arrow(){
    this->x = 620;
    this->y = 380;
}

void arrow::update(){
    this->angle = atan2((this->y - enemy_y),(enemy_x - this->x));
    side1x = this->x + this->height * cos(this->angle);
    side1y = this->y - this->height * sin(this->angle);
    side2x = this->x + this->height * cos(this->angle + (3 * PI)/4);
    side2y = this->y - this->height * sin(this->angle + (3 * PI)/4);
    side3x = this->x + this->height * cos(this->angle - (3 * PI)/4);
    side3y = this->y - this->height * sin(this->angle - (3 * PI)/4);
    move_to_enemy(this->enemy_x, this->enemy_y);
    
}

void arrow::move_to_enemy(double enemy_x, double enemy_y){
    if(this->x > enemy_x){
        this->x -= 3;
    }
    if(this->x < enemy_x){
        this->x += 3;
    }
    if(this->y < enemy_y){
        this->y += 3;
    }
    if(this->y > enemy_y){
        this->y -= 3;
    }
}

void arrow::set_target_position(double enemy_x, double enemy_y){
    this->enemy_x = enemy_x;
    this->enemy_y = enemy_y;
}

bool arrow::check_collision(double x_position, double y_position, double width, double height){
    if(CheckCollisionPointRec(Vector2{(float)this->side1x, (float)this->side1y}, 
    Rectangle{(float)x_position, (float)y_position, (float)width, (float)height})){
        return true;
    }
    return false;
}

void arrow::draw(){
    DrawTriangle(Vector2{(float)this->side1x, (float)this->side1y}, Vector2{(float)this->side2x, (float)this->side2y}, 
        Vector2{(float)this->side3x, (float)this->side3y}, this->color);
}