//Para funções relacionadas ao jogador(movimento, gravidade, etc)
#include "raylib.h"
#include "player.h"

void player_move(Player *player, int vel){
    if (IsKeyDown(KEY_LEFT))
        player->hitbox.x -= vel;
    if (IsKeyDown(KEY_RIGHT))
        player->hitbox.x += vel;
    if (IsKeyDown(KEY_UP))
        player->hitbox.y -= vel;
    if (IsKeyDown(KEY_DOWN))
        player->hitbox.y += vel;
}