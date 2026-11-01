//Para funções relacionadas ao mapa
#include "mapa.h"
#include "ambiente.h"
#include "obstaculos.h"
#include "raylib.h"


//!Função de medir o tamanho do mapa
/*
Essa função recebe o arquivo de texto e percorre ele todo, procurando os \n e atualizando quantas
linhas e colunas a matriz do mapa têm pra comportar o tamanho do mapa.

Ela ignora também o caracter \r que às vezes pode existir ali, que é um resquício invisível que
pode ter de tu mexer nesse arquivo de texto no Windows.
*/
void medir_mapa(const char *texto, int *lin, int *col){
    int largura_atual = 0;
    *lin = 0;
    *col = 0;

    for (int k = 0; texto[k] != '\0'; k++){
        if (texto[k] == '\n') {
            (*lin)++;
            if (largura_atual > *col) {
                *col = largura_atual; //garante que o *col sempre tem a maior largura registrada, aí a matriz nunca vai ter o problema de ser pequena demais
            }
            largura_atual = 0;
        } else if (texto[k] != '\r') { // \r é um caracter invisível que tem no Windows, tem que ignorar pra não dar problema
            largura_atual++;
        }
    }

    //caso a última linha não termine num \n ela ainda não foi contada, então aqui repete a estrutura anterior pra contar a última linha
    if (largura_atual > 0) {
        (*lin)++;
        if (largura_atual > *col) {
            *col = largura_atual;
        }
    }
}



//!Função de preencher a matriz do mapa a partir do arquivo de texto
/*
Essa função percorre a toda string do arquivo de texto do mapa e preenche a matriz mapa com os caracteres válidos
que ela encontrar. Ou seja, ignorando o \r do Windows. 

A matriz já é iniciada toda preenchida por \0, que contam como células vazias, por causa do allocamento 
dinâmico do calloc, então não precisa preencher ela previamente com espaços vazios nem nada assim.
*/
void preencher_mapa(const char *texto, int lin, int col, char mapa[][col]){
    int lin_atual = 0;
    int col_atual = 0; 
    for (int k = 0; texto[k] != '\0'; k++) {
        if (texto[k] == '\n'){ //pula pra próxima linha da matriz, a coluna volta pra 0
            lin_atual++;
            col_atual = 0;
        } else if (texto[k] != '\r'){ // se for qualquer caracter normal
            if (lin_atual < lin && col_atual < col){ //só pra garantir que não tá escrevendo fora da matriz
                mapa[lin_atual][col_atual] = texto[k];
            }
            col_atual++;
        }
    }
}



//!Função de geração do mapa
/*
Nessa geração de mapa, os objetos são todos tratados como vetores unidimensionais que tem como capacidade
máxima o mapa inteiro. Dessa forma eu tenho eles preenchidos de maneira linear e sequencial, o que pode tornar
mais fácil de percorrer todos para checar colisões, por exemplo.

Nessa geração as plataformas são geradas como retângulos únicos de tamanhos variados, a príncipio é pra
isso me ajudar na hora das colisões
*/

void gerar_mapa(Vector2 tela, int lin, int col, char map[][col], Plataforma plats[], Porta portas[], Escada escadas[], Inimigo inimigos[], Vector2 *celula){
    int i, j, n_plat=0, n_escada=0, n_inimigos=0;

    //dividindo a tela em uma grid de células, garante que as células são sempre quadradas e cabem na tela
    if (tela.x / col < tela.y / lin) { //testa qual dimensão da tela é menor e usa ela como base pro tamanho de cada célula
        celula->x = tela.x / col;
        celula->y = tela.x / col;
    } else {
        celula->x = tela.y / lin;
        celula->y = tela.y / lin;
    }

    float offset_x = (tela.x - celula->x * col) / 2.0;
    float offset_y = (tela.y - celula->y * lin) / 2.0;


    for(i=0; i<lin; i++){
        for(j=0; j<col; j++){
            switch (map[i][j])
            {
            case 'Z': //caractere 'Z' na tabela eh plataforma, aqui em preto
                //Definindo posição
                plats[n_plat].hitbox.x = offset_x + j*celula->x;
                plats[n_plat].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                plats[n_plat].hitbox.width = celula->x;
                plats[n_plat].hitbox.height = celula->y;

                //definindo direção e cor
                plats[n_plat].cor = BLACK;

                n_plat++;
                
                break;
                
            case 'S': //caractere 'S' na tabela eh subida de escada, aqui em azul escuro
                //Definindo posição
                escadas[n_escada].hitbox.x = offset_x + j*celula->x;
                escadas[n_escada].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].hitbox.width = celula->x;
                escadas[n_escada].hitbox.height = celula->y;

                //definindo direção e cor
                escadas[n_escada].direcao = 1;
                escadas[n_escada].cor = DARKBLUE;

                n_escada++;
                break;

            case 'D': //caractere 'D' na tabela eh descida de escada, aqui em azul claro
                //Definindo posição
                escadas[n_escada].hitbox.x = offset_x + j*celula->x;
                escadas[n_escada].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].hitbox.width = celula->x;
                escadas[n_escada].hitbox.height = celula->y;

                //definindo direção e cor
                escadas[n_escada].direcao = 2;
                escadas[n_escada].cor = BLUE;

                n_escada++;
                break;

            case 'H': //caractere 'H' na tabela eh escada para efeito visual, aqui em roxo
                //Definindo posição
                escadas[n_escada].hitbox.x = offset_x + j*celula->x;
                escadas[n_escada].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                escadas[n_escada].hitbox.width = celula->x;
                escadas[n_escada].hitbox.height = celula->y;

                //definindo direção e cor
                escadas[n_escada].direcao = 0;
                escadas[n_escada].cor = PURPLE;

                n_escada++;
                break;;

            case 'P': //caractere 'P' na tabela eh a posicao inicial do jogador, aqui em verde
                //Definindo posição
                portas[0].hitbox.x = offset_x + j*celula->x;
                portas[0].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                portas[0].hitbox.width = celula->x;
                portas[0].hitbox.height = celula->y;

                //definindo se eh inicio ou final e sua cor
                portas[0].inicio = 1;
                portas[0].cor = GREEN;
                break;

            case 'F': //caractere 'F' na tabela eh o final da fase, aqui em dourado
                //Definindo posição
                portas[1].hitbox.x = offset_x + j*celula->x;
                portas[1].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                portas[1].hitbox.width = celula->x;
                portas[1].hitbox.height = celula->y;

                //definindo se eh inicio ou final e sua cor
                portas[1].inicio = 0;
                portas[1].cor = GOLD;
                break;

            case 'E': //caractere ´E´ na tabela eh inimigo, aqui em vermelho
                //Definindo posição
                inimigos[n_inimigos].hitbox.x = offset_x + j*celula->x;
                inimigos[n_inimigos].hitbox.y = offset_y + i*celula->y;

                //Definindo tamanho, lembrando que x é a largura e y é a altura
                inimigos[n_inimigos].hitbox.width = celula->x;
                inimigos[n_inimigos].hitbox.height = celula->y;

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
    for(i=0; plats[i].hitbox.width !=0 && plats[i].hitbox.height != 0; i++){

        DrawRectangleRec(plats[i].hitbox, plats[i].cor);
    }

    //desenhando as escadas
    for(i=0; escadas[i].hitbox.width !=0 && escadas[i].hitbox.height != 0; i++){
        DrawRectangleRec(escadas[i].hitbox, escadas[i].cor);
    }

    //desenhando os inimigos
    for(i=0; inimigos[i].hitbox.width !=0 && inimigos[i].hitbox.height != 0; i++){
        DrawRectangleRec(inimigos[i].hitbox, inimigos[i].cor);
    }

    //desenhando as portas
    for(i=0; i<2; i++){
        DrawRectangleRec(portas[i].hitbox, portas[i].cor);
    }
}