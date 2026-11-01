//Para structs e funções relacionadas ao sistema (tela, etc)
#ifndef SISTEMA_H
#define SISTEMA_H

#include "raylib.h"
#include "player.h"
#include "obstaculos.h"
#include "ambiente.h"
#include <time.h>

typedef struct Placar { 
    char nome[20]; 
    double fases[10]; //os tempos de cada fase
} Placar;

//ja está mais ou menos estruturado para ser possível pausar e retomar
typedef struct Cronometro{
    double tempo_acumulado;
    double tempo_atual;
    double tempo_inicial;
    int minutos, segundos, centesimos;
    int rodando; //ve se o timer já foi iniciado
}Cronometro;

void ficar_na_tela(Player *player, Vector2 tela);
void phase_begin(Cronometro *timer, int *fase_rodando);
void game_over(Player *player, Inimigo inimigos[], Porta portas[], Placar *placar, int fase_atual, Cronometro *timer, int *fase_rodando);
void phase_end(Player *player, Porta portas[], Placar *placar, int *fase_atual, Cronometro *timer, int *fase_rodando);
void timer_func(Cronometro *timer);

#endif