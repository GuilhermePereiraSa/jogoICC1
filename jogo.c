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

/*
posições no grid: '.', ponto final, é espaço livre
X' é a posição adversária
'*' é a posição a ser decidida

Exemplo:

    0   1   2
 ------------
0|  X   .   X

1|  X   X   .

2|  .   X   X


resposta:
    0   1   2
 ------------
0|  X   .   X

1|  X   X   .

2|  *   X   X
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void leituraMatriz(char** matriz, int nrows, int mcols);
void alocacaoMatriz(char*** matriz, int nrows, int mcols);
void aux_playWhere(char** matriz, int nrows, int mcols);
bool is_playable(char** matriz, int column, int row);
void printMatriz(char** matriz, int nrows, int mcols);

//Leitura de matriz normal, para cada linha vai se ler m colunas.
void leituraMatriz(char** matriz, int nrows, int mcols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols; j++) {
            scanf("%c", matriz[i][j]);
        }
    }
}

//Define uma matriz como: (E um ponteiro que aponta para) outros ponteiro de char de n linhas, com a coluna 0,
//e aponta cada uma dessas linhas para outro ponteiro de tipo "comum" que seriam as colunas "novas".
void alocacaoMatriz(char*** matriz, int nrows, int mcols)
{
    (*matriz) = (char**)malloc(sizeof(char*) * nrows);

    for (int i = 0; i < nrows; i++) {
        (*matriz)[i] = (char*)malloc(sizeof(char) * mcols);
    }
}


void aux_playWhere(char** matriz, int nrows, int mcols)
{
    int column, row;

    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols;j++) {
            if (matriz[i][j] == '.') {
                column = j;
                row = i;
                if (is_playable(matriz, column, row)) {
                    matriz[i][j] = '*';
                }
            }
        }
    }

}

bool is_playable(char** matriz, int column, int row)

{
    int countImpar = 0;
    //Fixando a linha e movendo a coluna onde está o ponto: coluna antecessora e sucessora
    //e se estas possuem X contabiliza em countImpar;
    if (matriz[row][column + 1] == 'X') {
        countImpar++;
    }

    if (matriz[row][column - 1] == 'X') {
        countImpar++;
    }

    //Agora fixamos a coluna column e vemos se nas linhas antecessora àquele ponto e sucessora se 
    //possuem X

    if (matriz[row + 1][column] == 'X') {
        countImpar++;
    }

    if (matriz[row - 1][column] == 'X') {
        countImpar++;
    }

    if (countImpar % 2 != 0) {
        return false;
    }

    return true;

}

void printMatriz(char** matriz, int nrows, int mcols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols;j++) {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    char** Mat;
    int n, m;
    scanf("%d %d", &n, &m);

    alocacaoMatriz(&Mat, n, m);

    leituraMatriz(Mat, n, m);

    aux(Mat, n, m);

    printMatriz(Mat, n, m);

    free(Mat);
    Mat = NULL;

}