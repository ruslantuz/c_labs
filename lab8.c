#include<stdio.h>
#include<stdlib.h> 

int main(){
    int Arr1[5][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };
    int i,j;
    int top = 0, bottom = 4;
    int left = 0, right = 4;

    printf("Початковий масив:\n");
    for (i = 0; i<=4; i++){
        for(j=0;j<=4;j++){
            printf("%2i ", Arr1[i][j]);
        }
        printf("\n");
    }
    printf("Читання масиву за схемою вар. 10:\n");
    while (top <= bottom && left <= right) {
        // Рух вліво
        for (int i = right; i >= left; i--) {
            printf("%d ", Arr1[top][i]);
        }
        top++;

        // Рух вниз
        for (i = top; i <= bottom; i++) {
            printf("%d ", Arr1[i][left]);
        }
        left++;

        // Рух вправо
        for (i = left; i <= right; i++) {
            printf("%d ", Arr1[bottom][i]);
        }
        bottom--;

        // Рух вгору
        for (i = bottom; i >= top; i--) {
            printf("%d ", Arr1[i][right]);
        }
        right--;
    }
    printf("\n");

    printf("Заповнення масиву значеннями 1 та 0:\n");
    int Arr2[5][5];
    for (i = 0; i<=4;i++){
        for(j=0;j<=4;j++){
            if ((i == 0 || i == 4  || j==0 || j == 4) || (i == 2 && j == 2)){
                Arr2[i][j] = 0;
            }
            else{
                Arr2[i][j] = 1;
            }
            printf("%i ", Arr2[i][j]);
        }
        printf("\n");
    }
    return 0;
}