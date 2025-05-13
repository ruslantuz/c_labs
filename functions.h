#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void fillMatrix(int* matrix, int M, int N);
void printMatrix(const int* matrix, int M, int N);
void processMatrix(void (*fillFunc)(int*, int, int), int* matrix, int M, int N, int m, int n);

#endif
