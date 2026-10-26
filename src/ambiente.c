//Para funções relacionadas ao ambiente fixo (plataformas, escadas, portas)
#include "raylib.h"
#include "ambiente.h"
#include "player.h"

//para eu saber o centro de um objeto
Vector2 get_center(float x, float y, float width, float height){
    Vector2 centro;

    centro.x = x + (width/2);
    centro.y = y + (height/2);

    return centro;
}

//Para ver se dois objetos estão se sobrepondo
int ha_sobreposicao(Rectangle obj1, Rectangle obj2){
    int sobreposicao = 0;

    if((obj1.x+obj1.width)>obj2.x && obj1.x<(obj2.x+obj2.width)){//checando se há sobreposição no eixo x
        if((obj1.y+obj1.height)>obj2.y && obj1.y<(obj2.y+obj2.height))//checando se há sobreposição no eixo y
            sobreposicao = 1;
    }

    return sobreposicao;

}

//Para ver se a parte de baixo do obj1 está encostando na parte de cima do obj2
int ha_encosto_inferior(Rectangle obj1, Rectangle obj2){
    int encosto = 0;

    if((obj1.y+obj1.height) == obj2.y){ //garante que o obj1 está em cima do obj2 e encostando
        if(obj1.x <= (obj2.x+obj2.width) && (obj1.x+obj1.width)>=obj2.x)
            encosto = 1;
    }

    return encosto;

}

void colisao_plataformas(Player *player, Plataforma plataformas[]){
    Vector2 c_player, c_plataforma; //para eu determinar direções
    c_player = get_center(player->hitbox.x, player->hitbox.y, player->hitbox.width, player->hitbox.height);

    //checa sobreposição com todas as plataformas
    for(int i=0; plataformas[i].hitbox.height != 0 && plataformas[i].hitbox.width != 0; i++){
        c_plataforma = get_center(plataformas[i].hitbox.x, plataformas[i].hitbox.y, plataformas[i].hitbox.width, plataformas[i].hitbox.height);
        if(ha_sobreposicao(player->hitbox, plataformas[i].hitbox)){
            //vendo de qual direção o jogador está vindo
            //começando pelas laterais
            //checa se o centro do jogador está entre a altura total da plataforma
            if(c_player.y>plataformas[i].hitbox.y && c_player.y<(plataformas[i].hitbox.y+plataformas[i].hitbox.height)){
				if(c_player.x>c_plataforma.x) //vindo da direita da plataforma
					player->hitbox.x = plataformas[i].hitbox.x + plataformas[i].hitbox.width;
				if(c_player.x<c_plataforma.x) //vindo da esquerda
					player->hitbox.x = plataformas[i].hitbox.x - player->hitbox.width;
			}
            //depois de cima e de baixo
            else{
                if(c_player.y<c_plataforma.y){ //vindo de cima
					player->hitbox.y = plataformas[i].hitbox.y - player->hitbox.height;
				}
				if(c_player.y>c_plataforma.y){ //vindo de baixo
					player->hitbox.y = plataformas[i].hitbox.y + plataformas[i].hitbox.height;
				}
            }
        }
    }
}