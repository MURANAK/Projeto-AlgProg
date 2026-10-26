//Para structs e funções relacionadas ao jogador(movimento, gravidade, etc)
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

//TODO: fazer que ele morra, suba/desça escadas

typedef struct Player{
    Rectangle hitbox;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
    int vida;
}Player;

void player_move_hor(Player *player, float vel, float dt);
void player_move_ver(Player *player, float vel, float dt);
void player_jump(Player *player, float vel, float grav);

#endif