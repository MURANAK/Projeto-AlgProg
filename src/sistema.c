//Para funções relacionadas ao sistema (tela, etc)

#include "sistema.h"
#include "raylib.h"
#include "player.h"

void ficar_na_tela(Player *player, Vector2 tela){
    //Para teletransportar o jogador para o lado oposto ao sair totalmente da tela
	if((player->pos.x+player->size.x)<0)
		player->pos.x = tela.x;
	if((player->pos.y+player->size.y)<0)
		player->pos.y = tela.y;
	if(player->pos.x>tela.x)
		player->pos.x = 0;
	if(player->pos.y>tela.y)
		player->pos.y = 0;

}