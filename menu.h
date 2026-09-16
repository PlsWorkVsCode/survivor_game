#include "player.h"
#include "upgrade_player.h"
#include "enemy_spawner.h"
#include "death_menu.h"
#pragma once

static upgrade_player * upgrade_player1 = new upgrade_player();
static death_menu * death_menu1 = new death_menu();
static bool first_upgrade_refresh = true;

void menu(Vector2 mouse_position, player * player1, bool * menu_on, enemy_spawner * enemy_spawner1);