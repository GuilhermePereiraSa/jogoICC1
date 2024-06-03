#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void leituraMatriz(char** matriz, int nrows, int mcols);
void alocacaoMatriz(char*** matriz, int nrows, int mcols);
void markPlayablePositions(char** matriz, int nrows, int mcols);
bool isPlayable(char** matriz, int nrows, int mcols, int row, int col);
void printMatriz(char** matriz, int nrows, int mcols);

void leituraMatriz(char** matriz, int nrows, int mcols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols; j++) {
            scanf(" %c", &matriz[i][j]);
        }
    }
}

void alocacaoMatriz(char*** matriz, int nrows, int mcols)
{
    (*matriz) = (char**)malloc(sizeof(char*) * nrows);

    for (int i = 0; i < nrows; i++) {
        (*matriz)[i] = (char*)malloc(sizeof(char) * mcols);
    }
}

void markPlayablePositions(char** matriz, int nrows, int mcols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols; j++) {
            if (matriz[i][j] == '.') {
                if (isPlayable(matriz, nrows, mcols, i, j)) {
                    matriz[i][j] = '*';
                }
            }
        }
    }
}

bool isPlayable(char** matriz, int nrows, int mcols, int row, int col)
{
    int neighbors = 0;

    // Verifica se há peças adversárias nas posições vizinhas (acima, abaixo, esquerda, direita)
    if (row > 0 && matriz[row - 1][col] == 'X') // acima
        neighbors++;
    if (row < nrows - 1 && matriz[row + 1][col] == 'X') // abaixo
        neighbors++;
    if (col > 0 && matriz[row][col - 1] == 'X') // esquerda
        neighbors++;
    if (col < mcols - 1 && matriz[row][col + 1] == 'X') // direita
        neighbors++;

    // Retorna true se o número de vizinhos com peças adversárias for par
    return neighbors % 2 == 0;
}

void printMatriz(char** matriz, int nrows, int mcols)
{
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < mcols; j++) {
            printf("%c", matriz[i][j]);
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

    markPlayablePositions(Mat, n, m);

    printMatriz(Mat, n, m);

    // Liberando a memória alocada
    for (int i = 0; i < n; i++) {
        free(Mat[i]);
    }
    free(Mat);
    Mat = NULL;

    return 0;
}
