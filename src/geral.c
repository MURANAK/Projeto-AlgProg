#include "geral.h"
#include "raylib.h"

Vector2 get_center(float width, float heigth){
    Vector2 centro;

    centro.x = width/2;
    centro.y = heigth/2;

    return centro;
}