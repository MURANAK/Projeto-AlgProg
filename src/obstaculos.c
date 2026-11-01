//Para funções relacionadas à coisas que podem machucar o jogador(inimigos, projéteis, etc)
#include "obstaculos.h"
#include "ambiente.h"

void enemy_move(Inimigo inimigos[], Plataforma plataformas[], float dt){
    for(int i=0; inimigos[i].hitbox.height != 0 && inimigos[i].hitbox.width != 0; i++){
        for(int j=0; plataformas[j].hitbox.height != 0 && plataformas[j].hitbox.width != 0; j++){
            if(inimigos[i].direcao == 0){ //quando estiver indo para direita
                Vector2 ponto_checagem; //um ponto pra ver se há plataforma a frente ou não
                ponto_checagem.x = inimigos[i].hitbox.x + inimigos[i].hitbox.width+1;
                ponto_checagem.y = inimigos[i].hitbox.y+inimigos[i].hitbox.height+1;

                if(CheckCollisionPointRec(ponto_checagem, plataformas[j].hitbox)){ //se houver plataforma a frente
                    inimigos[i].virar = 0;
                    break;
                }
                else{
                    inimigos[i].virar = 1;
                }
            }
            else{ //se estiver indo para a esquerda
                Vector2 ponto_checagem; //um ponto pra ver se há plataforma a frente ou não
                ponto_checagem.x = inimigos[i].hitbox.x - 1;
                ponto_checagem.y = inimigos[i].hitbox.y+inimigos[i].hitbox.height+1;

                if(CheckCollisionPointRec(ponto_checagem, plataformas[j].hitbox)){ //se houver plataforma a frente
                    inimigos[i].virar = 0;
                    break;
                }
                else{
                    inimigos[i].virar = 1;
                }
            }
            
        }
        if(inimigos[i].virar){
            inimigos[i].direcao = !inimigos[i].direcao;
            inimigos[i].virar = 0;
        }

        if(inimigos[i].direcao == 0)
            inimigos[i].hitbox.x += 50.0*dt;
        if(inimigos[i].direcao != 0)
            inimigos[i].hitbox.x -= 50.0*dt;
    }
}