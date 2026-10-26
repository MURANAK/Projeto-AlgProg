//Para funções relacionadas ao jogador(movimento, gravidade, etc)
#include "raylib.h"
#include "player.h"

void player_move_hor(Player *player, float vel, float dt){
    if (IsKeyDown(KEY_LEFT))
        player->hitbox.x -= vel*dt;
    if (IsKeyDown(KEY_RIGHT))
        player->hitbox.x += vel*dt;
}

void player_move_ver(Player *player, float vel, float dt){
    if (IsKeyDown(KEY_UP))
        player->hitbox.y -= vel*dt;
    if (IsKeyDown(KEY_DOWN))
        player->hitbox.y += vel*dt;
}
