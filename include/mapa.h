//Para structs e funções relacionadas ao mapa
#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"
#include "ambiente.h"
#include "obstaculos.h"

//TODO: mudança de fase

//!WIP
//Essa função mede as dimensões do mapa
void medir_mapa(const char *texto, int *lin, int *col);
//Essa ???
void preencher_mapa(const char *texto, int lin, int col, char mapa[][col]);

//Essa função "atribui tipos" para cada célula da grade da tela
void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[], Vector2 *celula);
//Essa fução desenha tudo
void desenhar_mapa(int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[]);

#endif