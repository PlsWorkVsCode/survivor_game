#include "fireball.h"

fireball::fireball(double fireball_amount){
    this->fireball_amount = fireball_amount;
}

void fireball::update(double player_x, double player_y, double player_width, double player_height){
    this->x = player_x + (player_width / 2)  + (70 * ((int)(fireball_amount / 6 + 1))) * 
        cos(GetTime() + this->fireball_amount);
    this->y = player_y + (player_height / 2) + (70 *  ((int)(fireball_amount / 6 + 1))) * 
        sin(GetTime() + this->fireball_amount);

}

bool fireball::check_collision(double x_position, double y_position, double width, double height){
    if(CheckCollisionCircleRec(Vector2{(float)this->x, (float)this->y}, this->radius, 
    Rectangle{(float)x_position, (float)y_position, (float)width, (float)height})){
        return true;
    }
    else{
        return false;
    }
}

void fireball::draw(){
    DrawCircle(this->x, this->y, this->radius, this->color);
}