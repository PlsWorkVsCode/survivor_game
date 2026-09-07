#include "upgrade_player.h"
#include <cstdlib>

upgrade_player::upgrade_player(){
    this->more_fireball_damage = new button(500, 400, 80, 30, BLUE, "More Fireball Damage", 10);
    this->button_list.push_back(this->more_fireball_damage);
    this->new_fireball = new button(650, 400, 80, 30, BLUE, "New Fireball", 10);
    this->button_list.push_back(this->new_fireball);
    this->faster_push_cooldown = new button(750, 400, 80, 30, BLUE, "Decrease Push Cooldown", 10);
    this->button_list.push_back(this->faster_push_cooldown);
    this->more_push_damage = new button(900, 400, 80, 30, BLUE, "More Push Damage", 10);
    this->button_list.push_back(this->more_push_damage);
    this->faster_dash_cooldown = new button(500, 500, 80, 30, BLUE, "Decrease Dash Cooldown", 10);
    this->button_list.push_back(faster_dash_cooldown);
    this->more_dash_damage = new button(650, 500, 80, 30, BLUE, "More Dash Damage", 10);
    this->button_list.push_back(this->more_dash_damage);
    this->new_arrow = new button(800, 500, 80, 30, BLUE, "New Arrow", 10);
    this->button_list.push_back(this->new_arrow);
    this->more_arrow_damage = new button(900, 500, 80, 30, BLUE, "More Arrow Damage", 10);
    this->button_list.push_back(this->more_arrow_damage);
    this->more_cannon_balls = new button(500, 600, 80, 30, BLUE, "More Cannon Balls", 10);
    this->button_list.push_back(this->more_cannon_balls);
    this->faster_cannon_ball_cooldown = new button(700, 600, 80, 30, BLUE, "Faster Cannon Ball Cooldown", 10);
    this->button_list.push_back(this->faster_cannon_ball_cooldown);
    srand(time(0));
    
}


void upgrade_player::update(Vector2 mouse_position, player * player1){
    if(this->more_fireball_damage->update(mouse_position)){
        player1->fireball_damage++;
        player1->experience = 0;
        player1->experience_amount++;
    }
    if(this->new_fireball->update(mouse_position)){
        player1->fireball_list.push_back(new fireball(player1->fireball_amount));
        player1->fireball_amount++;
        player1->experience = 0;
        player1->experience_amount++;
    }
    if(this->faster_push_cooldown->update(mouse_position)){
        player1->push_refresh--;
        player1->experience = 0; 
        player1->experience_amount++;
    }
    if(this->more_push_damage->update(mouse_position)){
        player1->push_damage++;
        player1->experience = 0; 
        player1->experience_amount++;
    }
    if(this->faster_dash_cooldown->update(mouse_position)){
        player1->dash_refresh--;
        player1->experience = 0; 
        player1->experience_amount++;
    }
    if(this->more_dash_damage->update(mouse_position)){
        player1->dash_damage++;
        player1->experience = 0; 
        player1->experience_amount++;
    }
    if(this->new_arrow->update(mouse_position)){
        player1->arrow_list.push_back(new arrow());
        player1->arrow_amount++;
        player1->experience = 0;
        player1->experience_amount++;
    }
    if(this->more_arrow_damage->update(mouse_position)){
        player1->arrow_damage++;
        player1->experience = 0; 
        player1->experience_amount++;
    }
    if(this->more_cannon_balls->update(mouse_position)){
        player1->cannon_ball_amount++;
        player1->experience = 0; 
        player1->experience_amount++;
    }
    if(this->faster_cannon_ball_cooldown->update(mouse_position)){
        player1->cannon_ball_refresh--;
        player1->experience = 0; 
        player1->experience_amount++;
    }
}

void upgrade_player::draw(){
    this->more_fireball_damage->draw();
    this->new_fireball->draw();
    this->faster_push_cooldown->draw();
    this->more_push_damage->draw();
    this->faster_dash_cooldown->draw();
    this->more_dash_damage->draw();
    this->new_arrow->draw();
    this->more_arrow_damage->draw();
    this->more_cannon_balls->draw();
    this->faster_cannon_ball_cooldown->draw();
}

upgrade_player::~upgrade_player(){
    delete this->more_fireball_damage;
    this->more_fireball_damage = nullptr;
    delete this->new_fireball;
    this->new_fireball = nullptr;
    delete this->faster_push_cooldown;
    this->faster_push_cooldown = nullptr;
    delete this->more_push_damage;
    this->more_push_damage = nullptr;
    delete this->faster_dash_cooldown;
    this->faster_dash_cooldown = nullptr;
    delete this->more_dash_damage;
    this->more_dash_damage = nullptr;
    delete this->new_arrow;
    this->new_arrow = nullptr;
    delete this->more_arrow_damage;
    this->more_arrow_damage = nullptr;
    delete this->more_cannon_balls;
    this->more_cannon_balls = nullptr;
    delete this->faster_cannon_ball_cooldown;
    this->faster_cannon_ball_cooldown = nullptr;
}

void upgrade_player::refresh_buttons(){
    return;
}


