//Para funções relacionadas à coisas que podem machucar o jogador(inimigos, projéteis, etc)
#include "obstaculos.h"
#include "ambiente.h"

enemy_move(Inimigo inimigos[], Plataforma plataformas[], float dt){
    int direcao = 0, virar = 0; //0 é direita e 1 é esquerda, virar é uma flag pra mudar de direção
    for(int i=0; plataformas[i].hitbox.height != 0 && plataformas[i].hitbox.width != 0; i++){
        if(!(ha_encosto_inferior(inimigos[i].hitbox, plataformas[i].hitbox)))
            virar = 1;
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