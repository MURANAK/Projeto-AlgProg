//Para funções relacionadas ao sistema (tela, etc)

#include "sistema.h"
#include "raylib.h"
#include "player.h"

void ficar_na_tela(Player *player, Vector2 tela){
    //Para teletransportar o jogador para o lado oposto ao sair totalmente da tela
	if((player->hitbox.x+player->hitbox.width)<0)
		player->hitbox.x = tela.x;
	if((player->hitbox.y+player->hitbox.height)<0)
		player->hitbox.y = tela.y;
	if(player->hitbox.x>tela.x)
		player->hitbox.x = 0;
	if(player->hitbox.y>tela.y)
		player->hitbox.y = 0;

}