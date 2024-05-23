/*
Implementar um jogo de xadrez, que possui regras próprias as quais devemos respeitar 
e ilustrar no terminal como está sendo jogado, isto, por meio de matrizes.
"    Input
Na primeira linha serão dados dois inteiros N e M, sendo, respectivamente, o número de linhas e
colunas. Logo após será dado um grid com N linhas e M colunas, composto por carácteres.
Uma posição no grid (i, j) contém uma peçaa de Bruno se estiver marcada com o caracter 'X'. Já
uma posição livre é marcada pelo caracter '.'."
"    Output
Como saída você deve retornar a matriz com as peças de Bruno marcadas com 'X' e as posições
em que Isa pode colocar uma peça marcadas com '*'. Já as posições em que Isa não pode colocar
uma peça basta manter o caracter que estava na leitura.
Para esse exercício você deve utilizar funções, matrizes e alocação dinâmica."
*/
#include <stdio.h>
#include <stdlib.h>

#define N 1000
#define M 1000

void leituraMatriz(char **matriz, int nrows, int mcols);
void alocacaoMatriz(char ***matriz, int nrows, int mcols);

//Leitura de matriz normal, para cada linha vai se ler m colunas.
void leituraMatriz(char **matriz, int nrows, int mcols){
    for(int i=0; i<nrows; i++){
        for(int j=0; j<mcols; j++){
            scanf("%c", matriz[i][j]);
        }
    }
}

//Define uma matriz como: (E um ponteiro que aponta para) outros ponteiro de char de n linhas, com a coluna 0,
//e aponta cada uma dessas linhas para outro ponteiro de tipo "comum" que seriam as colunas "novas".
void alocacaoMatriz(char ***matriz, int nrows, int mcols){
    (*matriz) = (char **) malloc(sizeof(char*)*nrows);

    for(int i=0; i<nrows; i++){
        (*matriz)[i] = (char *) malloc(sizeof(char)*mcols);
    }
}
//Função principal do programa.
void playWhere(char **matriz, int nrows, int mcols){
    
}

int main(void){
    char **Mat;
    int n, m;
    scanf("%d %d", &n, &m);

    alocacaoMatriz(&Mat, n, m);

    //posições no grid: '.', ponto final, é espaço livre
    //'X' é a posição adversária
    //'*' é a posição a ser decidida
    leituraMatriz(Mat, n, m);

    playWhere(Mat, n, m);

}