//Para structs e funções relacionadas ao sistema (tela, etc)
#ifndef SISTEMA_H
#define SISTEMA_H

#include "raylib.h"
#include "player.h"
#include "obstaculos.h"
#include "ambiente.h"

void ficar_na_tela(Player *player, Vector2 tela);
void game_over(Player *player, Inimigo inimigos[], Porta portas[]);
void timer();

#endif