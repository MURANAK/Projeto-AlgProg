//Para structs e funções relacionadas ao jogador(movimento, gravidade, etc)
#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

//TODO: fazer que ele morra, suba/desça escadas

typedef struct Player{
    Vector2 pos;
    Vector2 size;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
    int vida;
}Player;

void player_move(Player *player, int vel);

#endif