//Bibliotecas
#include "raylib.h"
#include "player.h"
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



int main(){
    //inicializações gráficas
    InitWindow(LARGURA, ALTURA, "JOGO");
    SetTargetFPS(60);

    //declaração dos assets
    Player player = {{LARGURA/2, ALTURA/2}, {WIDTH, HEIGHT}, 1};

    //loop do jogo
    while(!WindowShouldClose()){
        player_move(&player, VEL);

        //Atualização da frame
        BeginDrawing();
        DrawRectangleV(player.pos, player.size, BLACK);
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    //Fim do programa
    CloseWindow();
    return 0;
}