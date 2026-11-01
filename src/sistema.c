//Para funções relacionadas ao sistema (tela, etc)

#include "sistema.h"
#include "raylib.h"
#include "player.h"
#include "obstaculos.h"
#include "ambiente.h"
#include <math.h>

void ficar_na_tela(Player *player, Vector2 tela){
    //Para teletransportar o jogador para o lado oposto ao sair totalmente da tela
	if((player->hitbox.x+player->hitbox.width)>tela.x)
		player->hitbox.x = tela.x - player->hitbox.width;
	if((player->hitbox.y+player->hitbox.height)>tela.y)
		player->hitbox.y = tela.y - player->hitbox.height;
	if(player->hitbox.x<0)
		player->hitbox.x = 0;
	if(player->hitbox.y<0)
		player->hitbox.y = 0;

}

void game_over(Player *player, Inimigo inimigos[], Porta portas[]){
	int game_over = 0;

	//verifica se o jogador ainda está vivo
	if(player->vida == 0)
		game_over = 1;
	//o que acontece quando é game over
	if(game_over){
		player->cor = DARKPURPLE;
	}

}