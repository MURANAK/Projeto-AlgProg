//Para structs e funções relacionadas à coisas que podem machucar o jogador(inimigos, projéteis, etc)
#ifndef OBSTACULOS_H
#define OBSTACULOS_H

#include "raylib.h"

//TODO: movimento dos inimigos, fazer que eles matem o player

typedef struct{
    Vector2 pos;
    Vector2 size;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
}Inimigo;

#endif