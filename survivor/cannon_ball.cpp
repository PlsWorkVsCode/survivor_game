#include "cannon_ball.h"

cannon_ball::cannon_ball(double original_x, double original_y, double cannon_ball_number){
    this->x = original_x + 20;
    this->y = original_y + 20;
    this->cannon_ball_number = cannon_ball_number;
    double cannon_ball_number1 = this->cannon_ball_number;
    while(this->continue_circle_calc){
        cannon_ball_number1 -= 2 * pow(2, circle_power);
        if(cannon_ball_number1 >= 0){
            this->circle_interval *= 2;
            this->circle_power++;
        }
        else{
            this->continue_circle_calc = false;
        }
    }
}

void cannon_ball::update(){
    this->x += cos(((2*PI)/this->circle_interval) * ((this->cannon_ball_number - pow(2, circle_power)) * 2 + 1)) * this->movement_speed;
    this->y += sin(((2*PI)/this->circle_interval) * ((this->cannon_ball_number - pow(2, circle_power)) * 2 + 1)) * this->movement_speed;
}

bool cannon_ball::outside_bounds(){
    if(this->x - this->radius >= 1280 || this->x + this->radius <= 0) return true;
    else if(this->y + this->radius <= 0 || this->y - this->radius >= 800) return true;
    return false;
}

bool cannon_ball::check_collision(double enemy_x, double enemy_y, double enemy_width, double enemy_height){
    if(CheckCollisionCircleRec(Vector2{(float)this->x, (float)this->y}, (float)this->radius, 
    Rectangle{(float)enemy_x, (float)enemy_y, (float)enemy_width, (float)enemy_height})){
        return true;
    }
    return false;
}

void cannon_ball::draw(){
    DrawCircle(this->x, this->y, this->radius, this->color);
}