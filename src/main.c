#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LIN 4
#define COL 5
#define TAM 20 //tamanho dos blocos coloridos


int main(){

    InitWindow(20, 20, "Teste de leitura de matriz"); //Inicializa janela, com tamanho aleatório e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo


	ToggleFullscreen(); //para colocar em tela cheia

	//definindo a altura e largura da tela
	float ScreenH = GetScreenHeight();
	float ScreenW = GetScreenWidth();

	//Declarando uma matriz para ser o mapa e preenchendo ela com valores em [1, 4]
	int Mapa[LIN][COL] = {0};

	const int MAX = 4, MIN = 1;
	srand(time(NULL));

	for(int i = 0; i<LIN; i++){
		for(int j = 0; j<COL; j++)
			Mapa[i][j] = MIN + (rand()%(MAX+MIN-1));
	}


	//Divindo o mapa em blocos
	float BlocoY = ScreenH / (float)LIN;
	float BlocoX = ScreenW / (float)COL;

	//Definindo o centro dos blocos
	float C_BlocoY = BlocoY/2;
	float C_BlocoX = BlocoX/2;
	

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	 

	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela
	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
	for(int y=0, posy = 1; y<LIN; y++){
		for(int x=0, posx = 1; x<COL; x++){
			/*
			*Sabendo que a posicao de um objeto eh definida a partir de seu canto superior esquerdo
			*Eu calculo onde o bloco deve estar multiplicando o seu indice pelo tamanho correspondente
			*do bloco e adiciono mais a metade desse tamanho para centralizar o bloco e diminuo a
			*metade do tamanho correspondente do retangulo
			*/

			posx = (x*BlocoX) + C_BlocoX - (TAM/2);
			posy = (y*BlocoY) + C_BlocoY - (TAM/2);

			//? sera que precisa saber o centro do sprite para centralizar, ja que o sprite eh irregular

			if(Mapa[y][x] == 1) //1 eh verde
				DrawRectangle(posx, posy, TAM, TAM, GREEN);
			else if(Mapa[y][x] == 2) //2 eh vermelho
				DrawRectangle(posx, posy, TAM, TAM, RED);
			else if(Mapa[y][x] == 3) //3 eh azul
				DrawRectangle(posx, posy, TAM, TAM, BLUE);
			else //4 eh amarelo
				DrawRectangle(posx, posy, TAM, TAM, GOLD);
			
			//Para demarcar o centro dos blocos da grid
			DrawCircle((x*BlocoX) + C_BlocoX, (y*BlocoY) + C_BlocoY, 5, BLACK);
		}
	}
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}