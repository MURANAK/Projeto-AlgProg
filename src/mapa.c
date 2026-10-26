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

Nessa geração as plataformas são geradas como retângulos únicos de tamanhos variados, a príncipio é pra
isso me ajudar na hora das colisões
*/
void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[]){
    int i, j, n_plat=0, n_escada=0, n_inimigos=0;
    float tamanho_plat=0; //para saber qual deve ser a largura de cada plataforma
    Vector2 celula; //as celulas ficticias da tela dividida em grade

    //dividindo a tela em uma grade
    celula.x = tela.x / (float)col; //largura da celula
    celula.y = tela.y / (float)lin; //altura da celula

    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            switch (map[i][j])
            {
            case 'Z': //caractere 'Z' na tabela eh plataforma, aqui em preto
                if(tamanho_plat == 0){
                    //Definindo posição
                    plats[n_plat].hitbox.x = j*celula.x;
                    plats[n_plat].hitbox.y = i*celula.y;

                    tamanho_plat ++;
                }

                if(map[i][j+1] == 'Z')
                    tamanho_plat++;
                else{
                    //Definindo tamanho, lembrando que x é a largura e y é a altura
                    plats[n_plat].hitbox.width = tamanho_plat*celula.x;
                    plats[n_plat].hitbox.height = celula.y;

                    //definindo cor e "dureza"
                    plats[n_plat].cor = BLACK;
                    plats[n_plat].duro = 1;

                    n_plat++;
                    tamanho_plat = 0;
                }
                
                break;
                
            case 'S': //caractere 'S' na tabela eh subida de escada, aqui em azul escuro
                //Definindo posição
                escadas[n_escada].hitbox.x = j*celula.x;
                escadas[n_escada].hitbox.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].hitbox.width = celula.x;
                escadas[n_escada].hitbox.height = celula.y;

                //definindo direção e cor
                escadas[n_escada].direcao = 1;
                escadas[n_escada].cor = DARKBLUE;

                n_escada++;
                break;

            case 'D': //caractere 'D' na tabela eh descida de escada, aqui em azul claro
                //Definindo posição
                escadas[n_escada].hitbox.x = j*celula.x;
                escadas[n_escada].hitbox.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].hitbox.width = celula.x;
                escadas[n_escada].hitbox.height = celula.y;

                //definindo direção e cor
                escadas[n_escada].direcao = 2;
                escadas[n_escada].cor = BLUE;

                n_escada++;
                break;

            case 'H': //caractere 'H' na tabela eh escada para efeito visual, aqui em roxo
                //Definindo posição
                escadas[n_escada].hitbox.x = j*celula.x;
                escadas[n_escada].hitbox.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].hitbox.width = celula.x;
                escadas[n_escada].hitbox.height = celula.y;

                //definindo direção e cor
                escadas[n_escada].direcao = 0;
                escadas[n_escada].cor = PURPLE;

                n_escada++;
                break;;

            case 'P': //caractere 'P' na tabela eh a posicao inicial do jogador, aqui em verde
                //Definindo posição
                portas[0].hitbox.x = j*celula.x;
                portas[0].hitbox.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                portas[0].hitbox.width = celula.x;
                portas[0].hitbox.height = celula.y;

                //definindo se eh inicio ou final e sua cor
                portas[0].inicio = 1;
                portas[0].cor = GREEN;
                break;

            case 'F': //caractere 'F' na tabela eh o final da fase, aqui em dourado
                //Definindo posição
                portas[1].hitbox.x = j*celula.x;
                portas[1].hitbox.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                portas[1].hitbox.width = celula.x;
                portas[1].hitbox.height = celula.y;

                //definindo se eh inicio ou final e sua cor
                portas[1].inicio = 0;
                portas[1].cor = GOLD;
                break;

            case 'E': //caractere ´E´ na tabela eh inimigo, aqui em vermelho
                //Definindo posição
                inimigos[n_inimigos].hitbox.x = j*celula.x;
                inimigos[n_inimigos].hitbox.y = i*celula.y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                inimigos[n_inimigos].hitbox.width = celula.x;
                inimigos[n_inimigos].hitbox.height = celula.y;

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
    Vector2 pos, size;

    //desenhando as plataformas
    for(i=0; plats[i].hitbox.width !=0 && plats[i].hitbox.height != 0; i++){
        pos.x = plats[i].hitbox.x;
        pos.y = plats[i].hitbox.y;

        size.x = plats[i].hitbox.width;
        size.y = plats[i].hitbox.height;

        DrawRectangleV(pos, size, plats[i].cor);
    }

    //desenhando as escadas
    for(i=0; escadas[i].hitbox.width !=0 && escadas[i].hitbox.height != 0; i++){
        pos.x = escadas[i].hitbox.x;
        pos.y = escadas[i].hitbox.y;

        size.x = escadas[i].hitbox.width;
        size.y = escadas[i].hitbox.height;

        DrawRectangleV(pos, size, escadas[i].cor);
    }

    //desenhando os inimigos
    for(i=0; inimigos[i].hitbox.width !=0 && inimigos[i].hitbox.height != 0; i++){
        pos.x = inimigos[i].hitbox.x;
        pos.y = inimigos[i].hitbox.y;

        size.x = inimigos[i].hitbox.width;
        size.y = inimigos[i].hitbox.height;

        DrawRectangleV(pos, size, inimigos[i].cor);
    }

    //desenhando as portas
    for(i=0; i<2; i++){
        pos.x = portas[i].hitbox.x;
        pos.y = portas[i].hitbox.y;

        size.x = portas[i].hitbox.width;
        size.y = portas[i].hitbox.height;

        DrawRectangleV(pos, size, portas[i].cor);
    }
}