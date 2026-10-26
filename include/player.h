//Para structs e funções relacionadas ao jogador(movimento, gravidade, etc)
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"


//TODO: fazer que ele morra, suba/desça escadas

typedef struct Player{
    Rectangle hitbox;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
    int vida;
    int is_on_ground; //se o jogador está no chão, 1 é verdadeiro, 0 é falso
    float acel_vertical; //quando esta no chão a aceleração é 0, quando está caindo a aceleração vai aumentando
}Player;

void player_move_hor(Player *player, float vel, float dt);
void player_move_ver(Player *player, float vel, float dt);
typedef struct Plataforma Plataforma;
void player_jump(Player *player, float jump_pow, float grav, float dt, Plataforma *plataformas);

#endif