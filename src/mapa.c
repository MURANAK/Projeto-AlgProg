//Para funções relacionadas ao mapa
#include "mapa.h"
#include "ambiente.h"
#include "obstaculos.h"
#include "raylib.h"

//!Função de geração do mapa
/*
Nessa geração de mapa, os objetos são todos tratados como vetores unidimensionais que tem como capacidade
máxima o mapa inteiro. Dessa forma eu tenho eles preenchidos de maneira linear e sequencial, o que pode tornar
mais fácil de percorrer todos para checar colisões, por exemplo.
*/
void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[]){
    int i, j, n_plat=0, n_escada=0, n_inimigos=0;
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
                plats[n_plat].pos.x = j*celula.x;
                plats[n_plat].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                plats[n_plat].size.x = celula.x;
                plats[n_plat].size.y = celula.y;

                //definindo cor e "dureza"
                plats[n_plat].cor = BLACK;
                plats[n_plat].duro = 1;

                n_plat++;
                
                break;
                
            case 'S': //caractere 'S' na tabela eh subida de escada, aqui em azul escuro
                //Definindo posição
                escadas[n_escada].pos.x = j*celula.x;
                escadas[n_escada].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].size.x = celula.x;
                escadas[n_escada].size.y = celula.y;

                //definindo direção e cor
                escadas[n_escada].direcao = 1;
                escadas[n_escada].cor = DARKBLUE;

                n_escada++;
                break;

            case 'D': //caractere 'D' na tabela eh descida de escada, aqui em azul claro
                //Definindo posição
                escadas[n_escada].pos.x = j*celula.x;
                escadas[n_escada].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].size.x = celula.x;
                escadas[n_escada].size.y = celula.y;

                //definindo direção e cor
                escadas[n_escada].direcao = 2;
                escadas[n_escada].cor = BLUE;

                n_escada++;
                break;

            case 'H': //caractere 'H' na tabela eh escada para efeito visual, aqui em roxo
                //Definindo posição
                escadas[n_escada].pos.x = j*celula.x;
                escadas[n_escada].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].size.x = celula.x;
                escadas[n_escada].size.y = celula.y;

                //definindo direção e cor
                escadas[n_escada].direcao = 0;
                escadas[n_escada].cor = PURPLE;

                n_escada++;
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
                inimigos[n_inimigos].pos.x = j*celula.x;
                inimigos[n_inimigos].pos.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                inimigos[n_inimigos].size.x = celula.x;
                inimigos[n_inimigos].size.y = celula.y;

                //definindo a cor
                inimigos[n_inimigos].cor = RED;

                n_inimigos++;
            }
				
        }
    }
}

//!Função para desenhar o mapa
/*
Essa função assume que nenhum objeto terá tamanho 0, mas como os vetores são preenchidos com apenas zeros
na inicialização, é possível determinar até onde foi preenchido baseado nessa condição
*/
//?Você acha que é melhor transformar as quantidades preenchidas em ponteiros, pra dar pra usar em outras funções?
/*
?Por enquanto essa função desenha apenas retângulos com o mesmo tamanho das "células"
?Eu vou deixar pra você decidir como vai realmente desenhar os sprites na tela
*/

void desenhar_mapa(int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[]){
    int i;

    //desenhando as plataformas
    for(i=0; plats[i].size.x !=0 && plats[i].size.y != 0; i++)
        DrawRectangleV(plats[i].pos, plats[i].size, plats[i].cor);

    //desenhando as escadas
    for(i=0; escadas[i].size.x !=0 && escadas[i].size.y != 0; i++)
        DrawRectangleV(escadas[i].pos, escadas[i].size, escadas[i].cor);

    //desenhando os inimigos
    for(i=0; inimigos[i].size.x !=0 && inimigos[i].size.y != 0; i++)
        DrawRectangleV(inimigos[i].pos, inimigos[i].size, inimigos[i].cor);

    //desenhando as portas
    for(i=0; i<2; i++)
        DrawRectangleV(portas[i].pos, portas[i].size, portas[i].cor);
}