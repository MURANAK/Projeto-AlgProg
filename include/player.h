//Para structs e funções relacionadas ao jogador(movimento, gravidade, etc)
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"


//TODO: fazer que ele morra

typedef struct Player{
    Rectangle hitbox;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
    int vida;
    int mov_hor, subida, descida; //flags para ver qual tipo de movimento o jogador pode realizar, 1 é verdadeiro, 0 é falso
    int is_on_ground; //se o jogador está no chão, 1 é verdadeiro, 0 é falso
    int is_on_stair; //se o jogador está em uma escada, 1 é verdadeiro, 0 é falso
    float acel_vertical; //quando esta no chão a aceleração é 0, quando está caindo a aceleração vai aumentando
}Player;

typedef struct Plataforma Plataforma;
typedef struct Escada Escada;
void player_move(Player *player, float vel, float dt, float jump_pow, float grav, Plataforma *plataformas, Escada *escadas);
void player_move_hor(Player *player, float vel, float dt);
void player_jump(Player *player, float jump_pow, float grav, float dt, Plataforma *plataformas);
void player_climb(Player *player, float vel, float dt, Escada *escadas);

#endif