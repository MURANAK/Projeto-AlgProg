#include "raylib.h"

typedef struct Player{
    Vector2 pos;
    Vector2 size;
    Color cor;
    int vida;
}Player;

void player_move(Player *player, int vel);