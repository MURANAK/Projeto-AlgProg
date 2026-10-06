#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LIN 30
#define COL 30
#define TAM 5 //tamanho dos blocos coloridos


int main(){

    InitWindow(800, 600, "Teste de leitura de matriz"); //Inicializa janela, com tamanho aleatório e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo


	ToggleFullscreen(); //para colocar em tela cheia

	//definindo a altura e largura da tela
	float ScreenH = GetScreenHeight();
	float ScreenW = GetScreenWidth();

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
	for(int y=0; y<LIN; y++){
		for(int x=0; x<COL; x++){
			/*
			*Sabendo que a posicao de um objeto eh definida a partir de seu canto superior esquerdo
			*Eu calculo onde o objeto deve estar multiplicando o seu indice de linha (x) pelo
			*comprimento do bloco da grade formada (BlocoX) e o seu indice de coluna (y) pela
			*altura do bloco (BlocoY)
			*/

			//! Os objetos nao estao centralizados, pois tem o mesmo tamanho dos blocos
			//! Foi usado o struct Vector2, pois seus argumentos sao do tipo float
			//! Foi usado o DrawRectangleV, pois seus paramametros sao do tipo float

			Vector2 pos;
			pos.x = (x*BlocoX);
			pos.y = (y*BlocoY);

			Vector2 size;
			size.x = BlocoX;
			size.y = BlocoY;

			//? sera que eh possivel mudar o tamanho do sprite de acordo com o tamanho dos blocos?
			//? sera que precisa de mais de um bloco para desenhar um unico sprite?

			if(Mapa[y][x] == 'Z') //caractere 'Z' na tabela eh plataforma, aqui em preto
				DrawRectangleV(pos, size, BLACK);
			else if(Mapa[y][x] == 'S') //caractere 'S' na tabela eh subida de escada, aqui em azul escuro
				DrawRectangleV(pos, size, DARKBLUE);
			else if(Mapa[y][x] == 'D') //caractere 'D' na tabela eh descida de escada, aqui em azul claro
				DrawRectangleV(pos, size, SKYBLUE);
			else if(Mapa[y][x] == 'H') //caractere 'H' na tabela eh escada para efeito visual, aqui em roxo
				DrawRectangleV(pos, size, PURPLE);
			else if(Mapa[y][x] == 'P') //caractere 'P' na tabela eh a posicao inicial do jogador, aqui em verde
				DrawRectangleV(pos, size, GREEN);
			else if(Mapa[y][x] == 'F') //caractere 'F' na tabela eh o final da fase, aqui em dourado
				DrawRectangleV(pos, size, GOLD);
			else if(Mapa[y][x] == 'E') //caractere ´E´ na tabela eh inimigo, aqui em vermelho
				DrawRectangleV(pos, size, RED);
			else //o resto sao espacos vazios, aqui em cinza claro
				DrawRectangleV(pos, size, LIGHTGRAY);
			
			//Para demarcar o centro dos blocos da grid
			//DrawCircle((x*BlocoX) + C_BlocoX, (y*BlocoY) + C_BlocoY, 5, BLACK);
		}
	}
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}