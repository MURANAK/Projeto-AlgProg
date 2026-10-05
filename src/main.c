#include "raylib.h"
#include <string.h>
#include <stdlib.h>

#define LIN 4
#define COL 5


int main(){

    InitWindow(20, 20, "Teste de leitura de matriz"); //Inicializa janela, com tamanho aleatório e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo


	ToggleFullscreen(); //para colocar em tela cheia

	//definindo a altura e largura da tela
	float ScreenH = GetScreenHeight();
	float ScreenW = GetScreenWidth();

	//Declarando uma matriz para ser o mapa
	int Mapa[LIN][COL] = {1, 2, 3 , 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

	//Divindo o mapa em blocos
	float BlocoH = ScreenH / (float)LIN;
	float BlocoW = ScreenW / (float)COL;
	

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	 

	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela
	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
	for(int i=0; i<LIN; i++){
		for(int j=0; j<COL; j++){
			/*
			Sabendo que a posicao de um objeto eh definida a partir de seu canto superior esquerdo
			Eu calculo onde o bloco deve estar multiplicando o seu indice pelo tamanho correspondente
			do bloco e adiciono mais a metade desse tamanho para centralizar o bloco
			*/

			if(Mapa[i][j] == 1) //1 eh verde
				DrawRectangle(((j*BlocoW)+(BlocoW/2)), ((i*BlocoH)+(BlocoH/2)), 20, 20, GREEN);
			else if(Mapa[i][j] == 2) //2 eh vermelho
				DrawRectangle(((j*BlocoW)+(BlocoW/2)), ((i*BlocoH)+(BlocoH/2)), 20, 20, RED);
			else if(Mapa[i][j] == 3) //3 eh azul
				DrawRectangle(((j*BlocoW)+(BlocoW/2)), ((i*BlocoH)+(BlocoH/2)), 20, 20, BLUE);
			else //4 eh amarelo
				DrawRectangle(((j*BlocoW)+(BlocoW/2)), ((i*BlocoH)+(BlocoH/2)), 20, 20, GOLD);
		}
	}
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}