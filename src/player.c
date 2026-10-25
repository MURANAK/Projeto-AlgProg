//Para funções relacionadas ao jogador(movimento, gravidade, etc)
#include "raylib.h"
#include "player.h"

void player_move(Player *player, int vel){
    if (IsKeyDown(KEY_LEFT))
        player->pos.x -= vel;
    if (IsKeyDown(KEY_RIGHT))
        player->pos.x += vel;
}