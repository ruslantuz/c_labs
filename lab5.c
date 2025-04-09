#include<stdio.h>
#include<stdbool.h>
#include<math.h>

int main(){
    int sum = 0; // Сума послідовності
    int n; // Елемент послідовності

    int m = 100; // Початок діапазону значень
    bool is_prime; // Змінна для перерівки чи є число простим

    // Підзадача 1
    printf("Послідовність значень 3*m + 5 кратних 4 (діапазон значень m - [100;400]):\n");
    for (;m<=400;m++){
        n = 3*m+5;
        if (n % 4 == 0){
            printf("%i ",n);
            sum += n;
        }
    }
    printf("\nСума значень = %i\n\n", sum);
    
    // Підзадача 2
    m = 100;
    printf("Прості числа в діапазоні [100; 400]:\n");
    do{
        is_prime = true;
        for (int i = 2; i*i <= m; i++){
            if(m%i == 0){
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            printf("%i ", m);
        }
        m++;
    } while(m<400);

    // Підзадача 3
    int a = 1, b, c;
    int found = 0;
    printf("\n\nПошук коренів р-ня 2*a + 5*c^2 - 11*b == 0:\n");
    while (!found) {
        b = 1;
        while (b <= 100 && !found) {
            c = 1;
            while (c <= 100 && !found) {
                if ((2 * a + 5 * pow(c,2) - 11 * b) == 0) {
                    printf("Знайдено корені: a = %d, b = %d, c = %d\n", a, b, c);
                    found = 1;
                }
                c++;
            }
            b++;
        }
        a++;
    }
}