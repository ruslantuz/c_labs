#include<stdio.h>
#include<string.h>

int main(){
    // char str[30];
    char *pib[3];
    int j = 0;
    printf("Введіть ПІБ: ");
    scanf("%s %s %s", &pib[0], &pib[1], &pib[2]);
    

    printf("%s %s %s", pib[0], pib[1], pib[2]);

    // // 
    // for (int i = 0; i < strlen(str); i++){
    //     if (str[i] == " "){
    //         for (j=0; j<i;j++){
    //             pib
    //         }
            
    //         str[i] = 0;
    //     }
    //     else{j++;}

    // }


    return 0;
}