#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

void fillMatrix(int* matrix, int M, int N) {
    srand(time(NULL));
    for (int i = 0; i < M * N; i++) {
        matrix[i] = rand() % 101;
    }
}

void printMatrix(const int* matrix, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%4d", matrix[i * N + j]);
        }
        printf("\n");
    }
}

void processMatrix(void (*fillFunc)(int*, int, int), int* matrix, int M, int N, int m, int n) {
    fillFunc(matrix, M, N);
    printf("Заповнена матриця: \n");
    printMatrix(&matrix[0], M, N);

    if (m < 0 || m >= M || n < 0 || n >= M || m == n) {
        printf("Неправильні номери рядків для обміну.\n");
        return;
    }

    for (int j = 0; j < N; j++) {
        int temp = matrix[m * N + j];
        matrix[m * N + j] = matrix[n * N + j];
        matrix[n * N + j] = temp;
    }
}
