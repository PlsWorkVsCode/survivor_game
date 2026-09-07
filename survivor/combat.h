#include "player.h"
#include "enemy_spawner.h"
#pragma once

void combat(player * player1, enemy_spawner *enemy_spawner1);

void enemy_collisions(enemy_spawner *enemy_spawner1);

void two_enemy_collisions(enemy * enemy1, enemy * enemy2);