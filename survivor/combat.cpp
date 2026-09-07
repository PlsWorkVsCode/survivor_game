#include "combat.h"

void combat(player * player1, enemy_spawner *enemy_spawner1){
    enemy_spawner1->update(player1->x, player1->y, player1);
    double arrow_number = 1;
//
    double player_movement_x = 0, player_movement_y = 0;
    if(player1->dashing){
        player1->dash();
    }
    if(player1->x < 620){
        player1->x = 620;
        if(player1->dashing){
            player_movement_x = player1->dash_speed;
        }
        else{
            player_movement_x = player1->movement_speed;
        }
    }
    if(player1->x > 620){
        player1->x = 620;
        if(player1->dashing){
            player_movement_x = -player1->dash_speed;
        }
        else{
            player_movement_x = -player1->movement_speed;
        }
    }
    if(player1->y > 380){
        player1->y = 380;
        if(player1->dashing){
            player_movement_y = -player1->dash_speed;
        }
        else{
            player_movement_y = -player1->movement_speed;
        }
    }
    if(player1->y < 380){
        player1->y = 380;
        if(player1->dashing){
            player_movement_y = player1->dash_speed;
        }
        else{
            player_movement_y = player1->movement_speed;
        }
    }
    player1->move_projectiles(player_movement_x, player_movement_y);
//
    for(int i = 0; i < enemy_spawner1->enemy_list.size(); i++){
        if(enemy_spawner1->enemy_list[i]){
            enemy * enemy1 = enemy_spawner1->enemy_list[i];
            if(player1->check_fireball_collision(enemy1->x, enemy1->y, enemy1->width, enemy1->height)){
                enemy1->take_damage(player1->fireball_damage);
            }
            if(CheckCollisionRecs(Rectangle{(float)enemy1->x, (float)enemy1->y, (float)enemy1->width, 
            (float)enemy1->height},Rectangle{(float)player1->x, (float)player1->y, (float)player1->width, 
            (float)player1->height})){
                if(!player1->dashing) player1->take_damage(enemy1->damage);
                else enemy1->take_damage(player1->dash_damage);
            }
            if(player1->pushing){
                enemy1->push();
                enemy1->take_damage(player1->push_damage);
            }
            enemy1->follow_player_movement(player_movement_x, player_movement_y);
            if(arrow_number <= player1->arrow_amount){
                player1->set_arrow_target_position(enemy1->x + 15, enemy1->y + 15, arrow_number);
                arrow_number++;
                if(player1->check_arrow_collision(enemy1->x, enemy1->y, enemy1->width, enemy1->height)){
                    enemy1->take_damage(player1->arrow_damage);
                }
            }
            if(player1->check_cannon_ball_collision(enemy1->x, enemy1->y, enemy1->width, enemy1->height)){
                enemy1->take_damage(player1->cannon_ball_damage);
            }
            if(enemy1->health <= 0){
                delete enemy_spawner1->enemy_list[i];
                enemy_spawner1->enemy_list[i] = nullptr;
                player1->experience += 1;
            }

        }
    }
    enemy_collisions(enemy_spawner1);
}

void enemy_collisions(enemy_spawner *enemy_spawner1){
    for(int i = 0; i < enemy_spawner1->enemy_list.size() - 1; i++){
        if(enemy_spawner1->enemy_list[i]){
            enemy * enemy1 = enemy_spawner1->enemy_list[i];
            for(int j = i + 1; j < enemy_spawner1->enemy_list.size(); j++){
                if(enemy_spawner1->enemy_list[j]){
                    enemy * enemy2 = enemy_spawner1->enemy_list[j];
                    two_enemy_collisions(enemy1, enemy2);
                }
            }
        }
    }

}

void two_enemy_collisions(enemy * enemy1, enemy * enemy2){
    if(CheckCollisionRecs(Rectangle{(float)enemy1->x, (float)enemy1->y, (float)enemy1->width, (float)enemy1->height},
    Rectangle{(float)enemy2->x, (float)enemy2->y, (float)enemy2->width, (float)enemy2->height})){
        if(enemy1->x == enemy2->x){
            if(enemy1->y > enemy2->y){
                enemy1->y += enemy2->y + enemy2->height - enemy1->y;
            }
            if(enemy1->y < enemy2->y){
                enemy1->y -= enemy1->y + enemy1->height - enemy2->y;
            }
        }
        if(enemy1->y == enemy2->y){
            if(enemy1->x > enemy2->x){
                enemy1->x += enemy2->x + enemy2->width - enemy1->x;
            }
            if(enemy1->x < enemy2->x){
                enemy1->x -= enemy1->x + enemy1->width - enemy2->x;
            }
        }
        if(enemy1->x > enemy2->x){
            if(enemy1->y < enemy2->y){
                if(enemy1->y + enemy1->height - enemy2->y > enemy2->x + enemy2->width - enemy1->x){
                    enemy1->x += enemy2->x + enemy2->width - enemy1->x;
                    
                }
                else{
                   
                    enemy1->y -= enemy1->y + enemy1->height - enemy2->y;
                }
            }
        
            else{
                if(enemy2->y + enemy2->height - enemy1->y > enemy2->x + enemy2->width - enemy1->x){
                    enemy1->x += enemy2->x + enemy2->width - enemy1->x;
                   
                }
                else{
                    
                    enemy1->y += enemy2->y + enemy2->height - enemy1->y;
                }
            }
        }
        else{
            if(enemy1->y < enemy2->y){
                if(enemy1->y + enemy1->height - enemy2->y > enemy1->x + enemy1->width - enemy2->x){
                    enemy1->x -= enemy1->x + enemy1->width - enemy2->x;
                }
                else{
                    enemy1->y -= enemy1->y + enemy1->height - enemy2->y;
                }

            }
            else{
                if(enemy2->y + enemy2->height - enemy1->y > enemy1->x + enemy1->width - enemy2->x){
                    enemy1->x -= enemy1->x + enemy1->width - enemy2->x;
                }
                else{
                    enemy1->y += enemy2->y + enemy2->height - enemy1->y;
                }
            }
        }
    }
}

