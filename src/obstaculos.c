//Para funções relacionadas à coisas que podem machucar o jogador(inimigos, projéteis, etc)
#include "obstaculos.h"
#include "ambiente.h"

void enemy_move(Inimigo inimigos[], Plataforma plataformas[], float dt){
    int direcao = 0, virar = 0; //0 é direita e 1 é esquerda, virar é uma flag pra mudar de direção
    for(int i=0; inimigos[i].hitbox.height != 0 && inimigos[i].hitbox.width != 0; i++){
        for(int j=0; plataformas[j].hitbox.height != 0 && plataformas[j].hitbox.width != 0; j++){
            if(!(ha_encosto_inferior(inimigos[i].hitbox, plataformas[j].hitbox))){
                virar = 1;
            }
            if(virar){
                direcao = !direcao;
                virar = 0;
            }

            if(direcao == 0)
                inimigos[i].hitbox.x += 50.0*dt;
            if(direcao != 0)
                inimigos[i].hitbox.x -= 50.0*dt;
            
        }
    }
}