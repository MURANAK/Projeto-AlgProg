//Para funções relacionadas ao jogador(movimento, gravidade, etc)
#include "raylib.h"
#include "player.h"
#include "ambiente.h"

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

void player_jump(Player *player, float jump_pow, float grav, float dt, Plataforma *plataformas){
    //vendo se o jogador está no chão
    player->is_on_ground = 0;
    for(int i=0; plataformas[i].hitbox.height != 0 && plataformas[i].hitbox.width != 0; i++){
        if(ha_encosto_inferior(player->hitbox, plataformas[i].hitbox))
            player->is_on_ground = 1;
    }

    if(player->is_on_ground && IsKeyPressed(KEY_SPACE)){
        player->is_on_ground = 0;
        player->acel_vertical = jump_pow;
    }

    if(!(player->is_on_ground)){
        player->acel_vertical += grav*dt;
        player->hitbox.y += (player->acel_vertical)*dt;
    }
}
