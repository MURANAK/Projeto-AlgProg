//Para funções relacionadas ao ambiente fixo (plataformas, escadas, portas)
#include "raylib.h"
#include "ambiente.h"

Vector2 get_center(Vector2 tamanho, Vector2 posicao){
    Vector2 centro;

    centro.x = posicao.x + (tamanho.x/2);
    centro.y = posicao.y + (tamanho.y/2);

    return centro;
}