#include "raylib.h"
#include <string.h>
#include <stdlib.h>


#define TAM 128

int main(){

    InitWindow(20, 20, "Teste"); //Inicializa janela, com tamanho aleatório e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo


	ToggleFullscreen(); //para colocar em tela cheia

	Color cor = (Color){ 0, 0, 0, 255 }; //definindo a cor da plataforma como preto

	//Pegando os tamanhos da tela
	int Screen_width = GetScreenWidth();
	int Screen_height = GetScreenHeight();

	//Inicializando o jogador como um struct de retangulo centralizado na tela e pegando o centro dele
	Rectangle player = {(float)Screen_width/2.0, (float)Screen_height/2.0, (float)TAM, (float)TAM};
	Vector2 centro_player = {player.x+(player.width/2), player.y+(player.height/2)};
	
	//Inicializando uma plataforma e pehando o centro dela
	Rectangle plataforma = {centro_player.x, centro_player.y+50.0, 200.0, 50.0};
	Vector2 centro_plataforma = {plataforma.x+(plataforma.width/2), plataforma.y+(plataforma.height/2)};

	float vel = 5; //definindo a velocinade do jogador

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	// Trata entrada do usuario e atualiza estado do jogo
	if (IsKeyDown(KEY_RIGHT)) {
	    player.x += vel;
	}
	if (IsKeyDown(KEY_LEFT)) {
	    player.x -= vel;
	}
	if (IsKeyDown(KEY_UP)) {
	    player.y -= vel;
	}
	if (IsKeyDown(KEY_DOWN)) {
	    player.y += vel;
	}

	// atualizando a posicao do centro do jogador
	centro_player.x = player.x+(player.width/2);
	centro_player.y = player.y+(player.height/2);

	if(CheckCollisionRecs(player, plataforma)){ //so ve se os cantos superiores esquerdos de cada retangulo estao sobrepostos
		if(player.x + player.width > plataforma.x){ //condicao de colisao em todos os lados
			cor = (Color){ 230, 41, 55, 255 };  //plataforma fica vermelha quando ha sobreposicao

			if(centro_player.y<centro_plataforma.y){ //vindo de cima
				player.y = plataforma.y - player.height;
			}
			if(centro_player.y>centro_plataforma.y){ //vindo de baixo
				player.y = plataforma.y + plataforma.height;
			}
		}
	}

	if(!CheckCollisionRecs(player, plataforma)) cor = (Color){ 0, 0, 0, 255 }; //plataforma fica preta quando nao ha colisao

	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela
	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
	DrawRectangleRec(player, GREEN); //desenhando o jogador
	DrawRectangleRec(plataforma, cor);//desenhando a plataforma
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    CloseWindow(); // Fecha a janela
    return 0;
}