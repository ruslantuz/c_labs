#include <stdio.h>
#include "functions.h"

int main() {
    int M, N;
    printf("Введіть розміри матриці M та N: ");
    scanf("%i %i", &M, &N);
    int matrix[M][N];

    int m, n;
    printf("Введіть рядки m та n для обміну: ");
    scanf("%i %i", &m, &n);

    processMatrix(fillMatrix, &matrix[0][0], M, N, m, n);

    printf("Матриця після обміну рядків %d і %d:\n", m, n);
    printMatrix(&matrix[0][0], M, N);

    return 0;
}