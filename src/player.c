//Para funções relacionadas ao jogador(movimento, gravidade, etc)
#include "raylib.h"
#include "player.h"
#include "ambiente.h"

//Para condensar tudo de movimento de jogador em uma única função
void player_move(Player *player, float vel, float dt, float jump_pow, float grav, Plataforma *plataformas, Escada *escadas){
    player_climb(player, vel, dt, escadas);
    if(player->mov_hor)
        player_move_hor(player, vel, dt);
    if(player->subida){
        if (IsKeyDown(KEY_UP))
            player->hitbox.y -= vel*dt;
    }
    if(player->descida){
        if (IsKeyDown(KEY_DOWN))
            player->hitbox.y += vel*dt;
    }
    player_jump(player, jump_pow, grav, dt, plataformas);
}

void player_move_hor(Player *player, float vel, float dt){
    if (IsKeyDown(KEY_LEFT))
        player->hitbox.x -= vel*dt;
    if (IsKeyDown(KEY_RIGHT))
        player->hitbox.x += vel*dt;
}

void player_jump(Player *player, float jump_pow, float grav, float dt, Plataforma *plataformas){
    player->is_on_ground = 0; //assume-se que o jogador não está no chão

    //vendo se o jogador está no chão
    for(int i=0; plataformas[i].hitbox.height != 0 && plataformas[i].hitbox.width != 0; i++){
        if(ha_encosto_inferior(player->hitbox, plataformas[i].hitbox))
            player->is_on_ground = 1;
    }

    //jogador pula com espaço, só quando estiver no chão, não conta estar em escadas
    if(player->is_on_ground && IsKeyPressed(KEY_SPACE) && !(player->is_on_stair)){
        player->is_on_ground = 0;
        player->acel_vertical = jump_pow;
    }

    //escadas são mágicas, gravidade não se aplica nelas, mas se o jogador estiver fora de uma escada e não estiver no chão, existe gravidade
    if(!(player->is_on_ground) && !(player->is_on_stair)){
        player->acel_vertical += grav*dt;
        player->hitbox.y += (player->acel_vertical)*dt;
    }
}

void player_climb(Player *player, float vel, float dt, Escada *escadas){
    player->is_on_stair = 0;//assume-se que o jogador não está na escada

    /*
    Ve se o jogador está em algum tipo de escada, quando achar em que situação o jogador se encontra
    ele sai do laço de repetição. Um switch-case não faria muita diferença aqui, eu acho, já que são
    muitas comparações diferentes e situações diferentes. 
    */
    for(int i=0; escadas[i].hitbox.height != 0 && escadas[i].hitbox.width != 0; i++){
        if(ha_sobreposicao(player->hitbox, escadas[i].hitbox)){ //checa se o jogador esta em alguma escada
            player->is_on_stair = 1;
            if(escadas[i].direcao == 1 || escadas[i].direcao==2){ //se um jogador estiver na subida/descida ele so pode se mover nas quatro direções
                player->mov_hor = 1;
                player->subida = 1;
                player->descida = 1;
                break;
            }
            else{//só ocorre se o jogador estiver naquelas escadas 'H', dai ele só pode se mover verticalmente
                player->mov_hor = 0;
                player->subida = 1;
                player->descida = 1;
                break;
            }
        }
        //se o jogador estiver em cima de escada de descida ele não consegue subir
        //!Por enquanto não funciona
        else if(ha_encosto_inferior(player->hitbox, escadas[i].hitbox) && escadas[i].direcao==2){
            player->is_on_stair = 1;
            player->hitbox.y = escadas[i].hitbox.y - player->hitbox.height;
            player->mov_hor = 1;
            player->subida = 0;
            player->descida = 1;
            break;
        }
        //se o jogador estiver em baixo de escada de subida ele não consegue descer
        //!Por enquanto não funciona
        else if(ha_encosto_inferior(escadas[i].hitbox, player->hitbox) && escadas[i].direcao==1){
            player->is_on_stair = 1;
            player->mov_hor = 1;
            player->subida = 1;
            player->descida = 0;
            break;
        }
        else{ //se o jogador não estiver em uma escada ele só pode se mover horizontalmente e pular
            player->mov_hor = 1;
            player->subida = 0;
            player->descida = 0;
        } 
    }

}
