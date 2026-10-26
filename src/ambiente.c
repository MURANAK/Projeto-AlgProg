//Para funções relacionadas ao ambiente fixo (plataformas, escadas, portas)
#include "raylib.h"
#include "ambiente.h"

Vector2 get_center(float x, float y, float width, float height){
    Vector2 centro;

    centro.x = x + (width/2);
    centro.y = y + (height/2);

    return centro;
}