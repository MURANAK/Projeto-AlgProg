#include "mapa.h"
#include "ambiente.h"
#include "obstaculos.h"
#include "raylib.h"

void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[][col], Porta portas[], Escada escadas[][col], Inimigo inimigos[][col]){
    int i, j;
    Vector2 celula; //as celulas ficticias da tela dividida em grade

    //dividindo a tela em uma grade
    celula.x = tela.x / (float)col; //largura da celula
    celula.y = tela.y / (float)lin; //altura da celula

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            switch (map[i][j])
            {
            case 'Z': //caractere 'Z' na tabela eh plataforma, aqui em preto
                //Definindo posição
                plats[i][j].pos.x = j*celula.x;
                plats[i][j].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                plats[i][j].size.x = celula.x;
                plats[i][j].size.y = celula.y;

                //definindo cor e "dureza"
                plats[i][j].cor = BLACK;
                plats[i][j].duro = 1;
                
                break;
                
            case 'S': //caractere 'S' na tabela eh subida de escada, aqui em azul escuro
                //Definindo posição
                escadas[i][j].pos.x = j*celula.x;
                escadas[i][j].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[i][j].size.x = celula.x;
                escadas[i][j].size.y = celula.y;

                //definindo direção e cor
                escadas[i][j].direcao = 1;
                escadas[i][j].cor = DARKBLUE;
                break;

            case 'D': //caractere 'D' na tabela eh descida de escada, aqui em azul claro
                //Definindo posição
                escadas[i][j].pos.x = j*celula.x;
                escadas[i][j].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[i][j].size.x = celula.x;
                escadas[i][j].size.y = celula.y;

                //definindo direção e cor
                escadas[i][j].direcao = 2;
                escadas[i][j].cor = BLUE;
                break;

            case 'H': //caractere 'H' na tabela eh escada para efeito visual, aqui em roxo
                //Definindo posição
                escadas[i][j].pos.x = j*celula.x;
                escadas[i][j].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[i][j].size.x = celula.x;
                escadas[i][j].size.y = celula.y;

                //definindo direção e cor
                escadas[i][j].direcao = 0;
                escadas[i][j].cor = PURPLE;
                break;;

            case 'P': //caractere 'P' na tabela eh a posicao inicial do jogador, aqui em verde
                //Definindo posição
                portas[0].pos.x = j*celula.x;
                portas[0].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                portas[0].size.x = celula.x;
                portas[0].size.y = celula.y;

                //definindo se eh inicio ou final e sua cor
                portas[0].inicio = 1;
                portas[0].cor = GREEN;
                break;

            case 'F': //caractere 'F' na tabela eh o final da fase, aqui em dourado
                //Definindo posição
                portas[1].pos.x = j*celula.x;
                portas[1].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                portas[1].size.x = celula.x;
                portas[1].size.y = celula.y;

                //definindo se eh inicio ou final e sua cor
                portas[1].inicio = 0;
                portas[1].cor = GOLD;
                break;

            case 'E': //caractere ´E´ na tabela eh inimigo, aqui em vermelho
                //Definindo posição
                inimigos[i][j].pos.x = j*celula.x;
                inimigos[i][j].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                inimigos[i][j].size.x = celula.x;
                inimigos[i][j].size.y = celula.y;

                //definindo a cor
                inimigos[i][j].cor = RED;
                break;
            
            default: //o resto sao espacos vazios, aqui em cinza claro
                //Definindo posição
                plats[i][j].pos.x = j*celula.x;
                plats[i][j].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                plats[i][j].size.x = celula.x;
                plats[i][j].size.y = celula.y;

                //definindo cor e "dureza"
                plats[i][j].cor = LIGHTGRAY;
                plats[i][j].duro = 0;
                break;
            }
				
        }
    }
}

void desenhar_mapa(int lin, int col, char map[][col], Plataforma plats[][col], Porta portas[], Escada escadas[][col], Inimigo inimigos[][col]){
    int i, j;

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            switch (map[i][j])
            {
            case 'Z': //caractere 'Z' na tabela eh plataforma, aqui em preto
                DrawRectangleV(plats[i][j].pos, plats[i][j].size, plats[i][j].cor);
                
                break;
                
            case 'S': //caractere 'S' na tabela eh subida de escada, aqui em azul escuro
                DrawRectangleV(escadas[i][j].pos, escadas[i][j].size, escadas[i][j].cor);
                break;

            case 'D': //caractere 'D' na tabela eh descida de escada, aqui em azul claro
                DrawRectangleV(escadas[i][j].pos, escadas[i][j].size, escadas[i][j].cor);
                break;

            case 'H': //caractere 'H' na tabela eh escada para efeito visual, aqui em roxo
                DrawRectangleV(escadas[i][j].pos, escadas[i][j].size, escadas[i][j].cor);
                break;;

            case 'P': //caractere 'P' na tabela eh a posicao inicial do jogador, aqui em verde
                DrawRectangleV(portas[0].pos, portas[0].size, portas[0].cor);
                break;

            case 'F': //caractere 'F' na tabela eh o final da fase, aqui em dourado
                DrawRectangleV(portas[1].pos, portas[1].size, portas[1].cor);
                break;

            case 'E': //caractere ´E´ na tabela eh inimigo, aqui em vermelho
                DrawRectangleV(inimigos[i][j].pos, inimigos[i][j].size, inimigos[i][j].cor);
                break;
            
            default: //o resto sao espacos vazios, aqui em cinza claro
                DrawRectangleV(plats[i][j].pos, plats[i][j].size, plats[i][j].cor);
                break;
            }
				
        }
    }

}