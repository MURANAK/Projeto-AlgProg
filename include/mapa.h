//Para structs e funções relacionadas ao mapa
#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"
#include "ambiente.h"
#include "obstaculos.h"

//TODO: mudança de fase

//Essa função "atribui tipos" para cada célula da grade da tela
void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[]);
//Essa fução desenha tudo
void desenhar_mapa(int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[]);

#endif