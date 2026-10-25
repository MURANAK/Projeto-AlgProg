//Para funções gerais de funcionamento
#include "geral.h"
#include "raylib.h"

//Para caso eu precise do centro de um objeto
Vector2 get_center(float width, float heigth){
    Vector2 centro;

    centro.x = width/2;
    centro.y = heigth/2;

    return centro;
}