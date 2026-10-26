//Bibliotecas
#include "raylib.h"
#include "player.h"
#include "ambiente.h"
#include "mapa.h"
#include "obstaculos.h"
#include "sistema.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constantes
// da tela
#define LARGURA 800
#define ALTURA 450
//do jogador
#define VEL 5
#define HEIGHT 20
#define WIDTH 20
//do mapa
#define LIN 30
#define COL 30

//TODO: placar, menu de pause, menu inicial, menu final com os scores, temporizador


int main(){
    //inicializações gráficas
    InitWindow(LARGURA, ALTURA, "JOGO");
    SetTargetFPS(60);

    //importante para as funções de gerar e desenhar mapa, guarda a largura e altura da tela
    //?deixei assim em vez de usar os defines, pra no futuro ser possivel sair e entrar da tela cheia
    Vector2 ScreenSize = {GetScreenWidth(), GetScreenHeight()};

    //declaração dos objetos
    Plataforma plataformas[LIN*COL] = {0};
    Escada escadas[LIN*COL] = {0};
    Porta portas[2] = {0};
    Inimigo inimigos[LIN*COL] = {0};

    //Declarando uma matriz para ser o mapa e preenchendo com a matriz exemplo dos criterios
	char Mapa[LIN][COL] = {
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', 'F', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t', '\t', 'D', '\t', '\t'},
    {'\t', '\t', '\t', '\t', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', '\t'},
    {'\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t'},
    {'\t', '\t', '\t', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', 'E', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'D'},
    {'Z', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H'},
    {'\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H'},
    {'\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', 'S'},
    {'\t', '\t', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', 'E', '\t', '\t', '\t', '\t'},
    {'\t', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', 'Z', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', 'Z', '\t', '\t', '\t', 'S', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', 'D', '\t', '\t', '\t', '\t', 'E', 'S', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t', '\t', '\t', '\t', '\t', '\t', 'D', '\t'},
    {'\t', 'H', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'H', '\t'},
    {'\t', 'H', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'H', '\t'},
    {'\t', 'S', '\t', '\t', '\t', 'P', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', 'S', '\t'},
    {'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z', 'Z'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'},
    {'\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t', '\t'}
    };

    gerar_mapa(ScreenSize, LIN, COL, Mapa, plataformas, portas, escadas, inimigos);

    //declaracao do jogador com base na posição da porta de inicio, decidida na geração do mapa
    Player player = {{portas[0].pos.x, portas[0].pos.y}, {ScreenSize.x/COL, ScreenSize.y/LIN}, BROWN, 1};

    //loop do jogo
    while(!WindowShouldClose()){
        //movimentos
        player_move(&player, VEL);
        ficar_na_tela(&player, ScreenSize);

        //Atualização da frame
        BeginDrawing();
        desenhar_mapa(LIN, COL, Mapa, plataformas, portas, escadas, inimigos);
        DrawRectangleV(player.pos, player.size, player.cor);
        ClearBackground(GRAY);
        EndDrawing();
    }

    //Fim do programa
    CloseWindow();
    return 0;
}