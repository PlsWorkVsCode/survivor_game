//g++ *.cpp -lraylib -framework IOKit -framework Cocoa -framework OpenGL


#include "raylib.h"
#include <iostream>
#include <cmath>
#include "player.h"
#include "combat.h"
#include "menu.h"

using namespace std;

const int screen_width = 1280;
const int screen_height = 800;

player player1;
enemy_spawner enemy_spawner1;

bool menu_on = false;


void keyboard();

int main(){
    InitWindow(screen_width, screen_height, "My Pong Game!");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        Vector2 mouse_position = GetMousePosition();
        if(menu_on){
            menu(mouse_position, &player1, &menu_on, &enemy_spawner1);
        }
        else{
            combat(&player1, &enemy_spawner1);
            menu(mouse_position, &player1, &menu_on, &enemy_spawner1);
            player1.update();
            player1.draw();
            enemy_spawner1.draw();
        }
        keyboard();
        ClearBackground(BLACK);
        EndDrawing();

    }
    CloseWindow();
    return 0;
}

void keyboard(){
    if(IsKeyDown(KEY_W)){
        if(player1.alive){
            player1.y -= player1.movement_speed;
            player1.up = true;
        }
    }
    if(IsKeyDown(KEY_A)){
        if(player1.alive){
            player1.x -= player1.movement_speed;
            player1.left = true;
        }
    }
    if(IsKeyDown(KEY_S)){
        if(player1.alive){
            player1.y += player1.movement_speed;
            player1.down = true;
        }
    }
    if(IsKeyDown(KEY_D)){
        if(player1.alive){
            player1.x += player1.movement_speed;
            player1.right = true;
        }
    }
    if(IsKeyPressed(KEY_C)){
        if(player1.alive) player1.push();
    }
    if(IsKeyPressed(KEY_LEFT_SHIFT)){
        if(player1.alive) player1.dash();
    }
}