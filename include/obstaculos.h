//Para structs e funções relacionadas à coisas que podem machucar o jogador(inimigos, projéteis, etc)
#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include "raylib.h"
#include "ambiente.h"

//TODO: movimento dos inimigos, fazer que eles matem o player

typedef struct Inimigo{
    Rectangle hitbox;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
}Inimigo;

void enemy_move(Inimigo inimigos[], Plataforma plataformas[], float dt);

#endif