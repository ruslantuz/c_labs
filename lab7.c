#include<stdio.h>
#include<stdbool.h>

int main(){
    int Arr[15];
    char c;
    bool b = 0;
    int i, count = 0;
    float Avg;

    while (b == 0){
        printf("Choose array filling method: (1 - manual, 2 - auto)\r\n");
        scanf("%c",&c);
        switch(c){
            case '1':
                b = 1;
                printf("\r\n");
                for (i = 0; i<=14; i++){
                    printf("Arr[%i] = ", i);
                    scanf("%i", &Arr[i]);
                }
                break;
            case '2':
                b = 1;
                for (i = 0; i<=14; i++){
                    Arr[i] = i - 7;
                }
                break;
            default:
                printf("Wrong symbol!\r\n");
        }
    }
    printf("\r\nArray Arr[15] = {");  
    for (i = 0; i<=14; i++){
        if (i != 14){
            printf("%i, ", Arr[i]);
        }
        else{
            printf("%i}\r\n", Arr[i]);
        }
        if(Arr[i] < 0){
            Avg += Arr[i];
            count++;
        }
    }

    Avg /= count;
    printf("Average of negative values: %.2f\r\n", Avg);
    return 0;
}