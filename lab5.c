#include <stdio.h>
#include <math.h>

int main(){
    double x, y, a, b, c;

    printf("Enter x: ");
    scanf("%lf", &x);

    //Варіант 1
    a = 0.1, b = 9.8, c = 11.12;
    if (log(a) < x){
        y = pow(pow(b,2) + sqrt(fabs(x+c)) ,(1/3));
    }
    else if(log(a) == x){
        y = cos(x-b-c);
    }
    else{
        y = sin(x+a-b);
    }
    printf("y(%lf) = %lf\n", x, y);

    //Варіант 2
    a = 10, b = 10.05, c = 6.2;
    if (log(a) < x){
        y = pow(pow(b,2) + sqrt(fabs(x+c)) ,(1/3));
    }
    else if(log(a) == x){
        y = cos(x-b-c);
    }
    else{
        y = sin(x+a-b);
    }
    printf("y(%lf) = %lf\n", x, y);

    //Варіант 3
    a = 100, b = 3.03, c = 7.12;
    if (log(a) < x){
        y = pow(pow(b,2) + sqrt(fabs(x+c)) ,(1/3));
    }
    else if(log(a) == x){
        y = cos(x-b-c);
    }
    else{
        y = sin(x+a-b);
    }
    printf("y(%lf) = %lf\n", x, y);

    return 0;
}