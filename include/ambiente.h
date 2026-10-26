//Para structs e funções relacionadas ao ambiente fixo (plataformas, escadas, portas)

#ifndef AMBIENTE_H
#define AMBIENTE_H

#include "raylib.h"

//TODO: colisões, escadas funcionarem, porta de fim funcionar

typedef struct{ //! eu tambem vou usar esse struct para pintar o fundo
    Rectangle hitbox;
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
    int duro; //pra saber que precisa ter colisão
}Plataforma;

typedef struct{
    Rectangle hitbox;
    int direcao; //! 0 será nada (o H), 1 será subida (o S), 2 será descida (o D)
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
}Escada;

typedef struct{
    Rectangle hitbox;
    int inicio; //! 1 significa que eh a porta de inicio e 0 significa que eh a porta pra passar pro fim
    Color cor; //?essa parte pode ser substituida por uma string que contem o caminho do arquivo do sprite
}Porta;


Vector2 get_center(float x, float y, float width, float height);

#endif