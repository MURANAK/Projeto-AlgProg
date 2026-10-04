#include "raylib.h"
#include <string.h>
#include <stdlib.h>


#define VEL 5

int main(){
	int MonitorWidth = GetMonitorWidth(0);
	int MonitorHeight = GetMonitorHeight(0);

    InitWindow(MonitorWidth, MonitorHeight, "macaco"); //Inicializa janela, com certo tamanho e titulo
    SetTargetFPS(60);// Ajusta a janela para 60 frames por segundo

    Texture2D macaco = LoadTexture("assets/Sprite-donkey-kong.png"); //carrengando a textura da imagem
    Vector2 position = {MonitorWidth/2, MonitorHeight/2};

    float SpriteWidth = (float)macaco.width/2.0;
    float SpriteHeight = (float)macaco.height;
    Rectangle frameRec = {0.0, 0.0, SpriteWidth, SpriteHeight};

    //Este laco repete enquanto a janela nao for fechada
    //Utilizamos ele para atualizar o estado do programa / jogo
    while (!WindowShouldClose())
    {
	// Trata entrada do usuario e atualiza estado do jogo
	if (IsKeyDown(KEY_RIGHT)) {
	    position.x += VEL;
        frameRec.x = 0.0 * SpriteWidth;
	}
	if (IsKeyDown(KEY_LEFT)) {
	    position.x -= VEL;
        frameRec.x = 1.0 * SpriteHeight;
	}
	if (IsKeyDown(KEY_UP)) {
	    position.y -= VEL;
	}
	if (IsKeyDown(KEY_DOWN)) {
	    position.y += VEL;
	}

	// Atualiza o que eh mostrado na tela a partir do estado do jogo
	BeginDrawing(); //Inicia o ambiente de desenho na tela
	ClearBackground(RAYWHITE); //Limpa a tela e define cor de fundo
	DrawTextureRec(macaco, frameRec, position, WHITE); //desenhando o sprite
	EndDrawing(); //Finaliza o ambiente de desenho na tela
    }

    UnloadTexture(macaco); //limpando o sprite da memória

    CloseWindow(); // Fecha a janela
    return 0;
}