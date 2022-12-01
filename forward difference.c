//program to calculate derivative using forward difference formula
#include <stdio.h>

float f(float x)
{
    return x*x;
}
int main()
{
    float x,h,fx,fxplush,f1x;
    printf("Enter x and h\t");
    scanf("%f%f",&x,&h);
    fx = f(x);
    fxplush = f(x+h);
    f1x = (fxplush - fx)/h;
    printf("The value of derivative of x^2 at %.3f is %.3f",x,f1x);
}
// Enter x and h   1 0.2
// The value of derivative of x^2 at 1.000 is 2.200

