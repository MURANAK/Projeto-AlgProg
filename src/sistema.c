//Para funções relacionadas ao sistema (tela, etc)

#include "sistema.h"
#include "raylib.h"
#include "player.h"

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