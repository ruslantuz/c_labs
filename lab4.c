#include <stdio.h>

int main(){
    int x, y, z;
    char ch;
    int max_q; // змінна для макс. частки від ділення
    int res1, res2; // змінні для збереження пари значень з макс. часткою від ділення 
    int temp;

    printf("Please, choose initialization way: 0 - Manual, 1 - Auto\r\n");
    scanf("%c", &ch);
    switch(ch)
    {
        // Ввід даних з консолі
        case '0':
            printf("Manual mode/\r\n");
            printf("Enter value for x: ");
            scanf("%i", &x);
            printf("Enter value for y: ");
            scanf("%i", &y);
            printf("Enter value for z: ");
            scanf("%i", &z);
            break;
        
        // Присвоєння значень без введення вручну
        default:
            printf("Auto mode/\r\n");
            x = 10;
            y = 4;
            z = 25;    
    }

    // Частка від ділення x та y з врахуванням того, яке значення більше
    max_q = (x>y) ? (x / y) : (y/x); 
    res1 = x;
    res2 = y;

    //Перевірка, чи буде частка від ділення z та y більшою
    temp = ((z > y) ? (z / y) : (y/z));
    if (max_q < temp){ 
        max_q = temp;
        res1 = y;
        res2 = z;
    } 

    //Перевірка, чи буде частка від ділення x та z більшою
    temp = ((x>z) ? (x / z) : (z/x));
    if (max_q < temp){ 
        max_q =  temp;
        res1 = x;
        res2 = z;
    }

    printf("Pair of values with the largest quotient: %i, %i\n", res1, res2);
    return 0;
}