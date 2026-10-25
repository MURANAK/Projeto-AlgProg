//Para structs e funções relacionadas ao mapa
#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"
#include "ambiente.h"
#include "obstaculos.h"

//TODO: mudança de fase

//Essa função "atribui tipos" para cada célula da grade da tela
void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[][col], Porta portas[], Escada escadas[][col], Inimigo inimigos[][col]);

//Essa fução desenha tudo
void desenhar_mapa(int lin, int col, char map[][col], Plataforma plats[][col], Porta portas[], Escada escadas[][col], Inimigo inimigos[][col]);

#endif