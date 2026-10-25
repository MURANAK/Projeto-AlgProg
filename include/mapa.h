#ifndef MAPA_H
#define MAPA_H

#include "raylib.h"
#include "ambiente.h"
#include "obstaculos.h"


void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[][col], Porta portas[], Escada escadas[][col], Inimigo inimigos[][col]);

void desenhar_mapa(int lin, int col, char map[][col], Plataforma plats[][col], Porta portas[], Escada escadas[][col], Inimigo inimigos[][col]);

#endif