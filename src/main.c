//Bibliotecas
#include "raylib.h"
#include "player.h"
#include "ambiente.h"
#include "mapa.h"
#include "obstaculos.h"
#include "sistema.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Constantes
// da tela
#define LARGURA 300
#define ALTURA 900
//do jogador
#define VEL 200.0f
#define G 500.0f
#define JUMP_POWER -250.0f //!tem que achar um jeito melhor de definir isso, ou consertar para que o jogador comece a cair imediatamente após atigir algo em cima

//TODO: placar, menu de pause, menu inicial, menu final com os scores, temporizador


int main(){
    //inicializações gráficas
    InitWindow(LARGURA, ALTURA, "JOGO");
    SetTargetFPS(60);
    ToggleFullscreen(); //tela cheia pq sim

    //importante para as funções de gerar e desenhar mapa, guarda a largura e altura da tela
    //?deixei assim em vez de usar os defines, pra no futuro ser possivel sair e entrar da tela cheia
    Vector2 ScreenSize = {GetScreenWidth(), GetScreenHeight()};

    //importa o texto do arquivo mapa1.txt
    char *texto = LoadFileText("resources/mapa1.txt");
    //testando se o arquivo é válido
    if (texto == NULL) {
        TraceLog(LOG_ERROR, "Nao foi possivel ler o mapa!");
        CloseWindow();
        return 1;
    }

    //dimensões do mapa
    int lin, col;
    medir_mapa(texto, &lin, &col);

    //aloca o espaço na memória dinâmicamente com o calloc, que preenche a matriz com \0
    char (*Mapa)[col] = calloc(lin, sizeof *Mapa);

    //structs do mapa, que são definidas a partir do tamanho do mapa usando o calloc
    Plataforma *plataformas = calloc(lin*col + 1, sizeof *plataformas);
    Escada *escadas = calloc(lin*col + 1, sizeof *escadas);
    Inimigo *inimigos = calloc(lin*col + 1, sizeof *inimigos);
    Porta portas[2] = {0};

    preencher_mapa(texto, lin, col, Mapa);
    UnloadFileText(texto);   //terminou de usar o texto, pode liberar a memória de novo

    Vector2 celula; //as celulas ficticias da tela dividida em grade
    gerar_mapa(ScreenSize, lin, col, Mapa, plataformas, portas, escadas, inimigos, &celula);

    //declaracao do jogador com base na posição da porta de inicio, decidida na geração do mapa
    //já que esse jogo é só de computador, então a tela sempre será mais larga que alta, então da para deixar o jogador na vertical
    Player player = {{portas[0].hitbox.x, portas[0].hitbox.y, celula.x * 0.8, celula.y * 0.8}, BROWN, 1, 1, 0, 0, 1, 0, 0.0};

    //loop do jogo
    while(!WindowShouldClose()){
        //movimentos
        /*
        Com o delta time(dt) eu consigo definir a velocidade de acordo com quanto tempo demora para carregar
        uma frame, em vez de quantas frames por segundo. Sem isso, a movimento do jogador é valocidae*FPS, então
        um computador com FPS maior se move mais. Com o dt acaba igualando. É meio confuso, eu recomendo você pesquisar
        sobre isso pra entender melhor
        */
        float dt = GetFrameTime();
        player_move(ScreenSize, &player, VEL, dt, JUMP_POWER, G, plataformas, escadas);

        //Fazendo checagens
        colisao_plataformas(&player, plataformas);

        //Atualização da frame
        BeginDrawing();
        desenhar_mapa(lin, col, Mapa, plataformas, portas, escadas, inimigos);
        DrawRectangleRec(player.hitbox, player.cor);
        ClearBackground(GRAY);
        EndDrawing();
    }

    free(Mapa); free(plataformas); free(escadas); free(inimigos);

    //Fim do programa
    CloseWindow();
    return 0;
}