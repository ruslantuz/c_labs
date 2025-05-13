#include<stdio.h>
#include<math.h>

double phi(double x, double y);
double f(double xi, double zeta);

double phi(double x, double y){
    double result;
    result = (f((x+1)/fabs(y), pow(y,3))-f((log(fabs(x+y)))/(2*x + 4*y), sqrt(x+2*y))) /
        (f((2*x + 6*y)/(y-4) , (y+2*x)/(2*y-3)) - f((x+y)/(2+y) , (2*x)/(4-3*y)));
    return result;
}
double f(double xi, double zeta){
    if(xi>0){
        return (pow(xi,1/3)+sqrt(fabs(zeta)))/(2*zeta - 3 * pow(xi,2));
    }
    else{
        return (sin(xi) + zeta)/(pow(xi,3)-cos(pow(zeta,2)));
    }
}

int main(){
    double x = 2, y = 2;
    printf("Значення ф-ї phi(%.2f, %.2f) = %.4f\r\n", x, y, phi(x,y));
    return 0;
}