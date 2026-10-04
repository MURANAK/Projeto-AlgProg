#include "raylib.h"
#include <string.h>
#include <stdlib.h>


#define LARGURA 800
#define ALTURA 700
#define VEL 5

int main(){
    int pos[2] = {LARGURA/2, ALTURA/2};


    InitWindow(LARGURA, ALTURA, "macaco"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

    Texture2D macaco = LoadTexture("assets/openclipart-vectors-deity-1296955_1280.png"); //carrengando a textura da imagem

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	// Trata entrada do usuario e atualiza estado do jogo
	if (IsKeyDown(KEY_RIGHT)) {
	    pos[0] += VEL;
	}
	if (IsKeyDown(KEY_LEFT)) {
	    pos[0] -= VEL;
	}
	if (IsKeyDown(KEY_UP)) {
	    pos[1] -= VEL;
	}
	if (IsKeyDown(KEY_DOWN)) {
	    pos[1] += VEL;
	}

	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela
	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
	DrawTexture(macaco, pos[0], pos[1], WHITE); //desenhando o sprite
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    UnloadTexture(macaco); //limpando o sprite da memória

    CloseWindow(); // Fecha a janela
    return 0;
}