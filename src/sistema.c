//Para funções relacionadas ao sistema (tela, etc)

#include "sistema.h"
#include "raylib.h"
#include "player.h"
#include "obstaculos.h"
#include "ambiente.h"
#include <time.h>

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

void phase_begin(Cronometro *timer, int *fase_rodando){
	timer->rodando = 1;
	timer->tempo_inicial = 0.0;
	*fase_rodando = 1;
}

void game_over(Player *player, Inimigo inimigos[], Porta portas[], Placar *placar, int fase_atual, Cronometro *timer, int *fase_rodando){
	int game_over = 0;

	//verifica se o jogador ainda está vivo
	if(player->vida == 0)
		game_over = 1;
	//o que acontece quando é game over
	if(game_over){
		player->cor = DARKPURPLE;
		timer->rodando = 0;
		placar->fases[fase_atual-1] = timer->tempo_acumulado;
		*fase_rodando = 0;
	}

}

void phase_end(Player *player, Porta portas[], Placar *placar, int *fase_atual, Cronometro *timer, int *fase_rodando){
	if(ha_sobreposicao(player->hitbox, portas[1].hitbox)){
		timer->rodando = 0;
		placar->fases[*fase_atual-1] = timer->tempo_acumulado;
		*fase_atual++;
		*fase_rodando = 0;
	}
}

void timer_func(Cronometro *timer){
	timer->tempo_atual = timer->tempo_acumulado;
	if(timer->rodando)
		timer->tempo_atual += GetTime() - timer->tempo_inicial;

	int totalCentesimos = (int)(timer->tempo_atual * 100.0);
        timer->minutos   = (totalCentesimos / 6000) % 60;
        timer->segundos  = (totalCentesimos / 100) % 60;
        timer->centesimos = totalCentesimos % 100;
}