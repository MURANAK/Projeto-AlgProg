#include "raylib.h"

typedef struct Plataforma{
    Vector2 pos;
    Vector2 size;
    Color cor;
    int duro; //pra saber que precisa ter colisão
}Plataforma;

typedef struct Escada{
    int direcao; //! 0 será nada (o H), 1 será subida (o S), 2 será descida (o D)
    Color cor;
}Escada;

typedef struct Porta{
    int inicio; //! 1 significa que eh a porta de inicio e 0 significa que eh a porta pra passar pro fim
    Color cor;
}Porta;