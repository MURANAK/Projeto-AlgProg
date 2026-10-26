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
#define VEL 100.0f
#define G 2.0f
#define JUMP_POWER 2.0f
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
    Plataforma plataformas[LIN] = {0};
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
    //já que esse jogo é só de computador, então a tela sempre será mais larga que alta, então da para deixar o jogador na vertical
    Player player = {{portas[0].hitbox.x, portas[0].hitbox.y, ScreenSize.y/LIN, ScreenSize.y/LIN}, BROWN, 1};
    Vector2 pos_p, size_p = {player.hitbox.width, player.hitbox.height};

    //loop do jogo
    while(!WindowShouldClose()){
        //movimentos
        float dt = GetFrameTime(); //para a velocidade do jogador ser a mesma independente do refresh rate
        player_move_hor(&player, VEL, dt);
        player_move_ver(&player, VEL, dt);
        ficar_na_tela(&player, ScreenSize);

        //Fazendo checagens
        colisao_plataformas(&player, plataformas);

        //Atualização da frame
        pos_p.x = player.hitbox.x;
        pos_p.y = player.hitbox.y;
        BeginDrawing();
        desenhar_mapa(LIN, COL, Mapa, plataformas, portas, escadas, inimigos);
        DrawRectangleV(pos_p, size_p, player.cor);
        ClearBackground(GRAY);
        EndDrawing();
    }

    //Fim do programa
    CloseWindow();
    return 0;
}