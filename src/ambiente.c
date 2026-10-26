//Para funções relacionadas ao ambiente fixo (plataformas, escadas, portas)
#include "raylib.h"
#include "ambiente.h"

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

//Para ver se dois objetos estão colidindo
int ha_colisao(Rectangle obj1, Rectangle obj2){
    int colisao = 0;

    if((obj1.x+obj1.width)==obj2.x || obj1.x==(obj2.x+obj2.width)){//checando se há colisão no eixo x
        if((obj1.y+obj1.height)==obj2.y || obj1.y==(obj2.y+obj2.height))//checando se há colisão no eixo y
            colisao = 1;
    }

    return colisao;

}