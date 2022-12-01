#include <stdio.h>

int main()
{
    int n,i,j;
    float x[100],f[100],xp,lf[100],value=0;
    printf("Enter number of data points: ");
    scanf("%d",&n);
    printf("Enter data points and functional value respectively:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&f[i]);
    }
    printf("Enter x at which interpolated value is to be calculated:");
    scanf("%f",&xp);

    for(i=0;i<n;i++)
    {
        lf[i] = 1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                lf[i] *=  (xp - x[j]) / (x[i] - x[j]);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        value += lf[i] * f[i];
    }

    printf("value at %f is %f",xp,value);
}
// expected output
// Enter number of data points: 6
// Enter data points and functional value respectively:
// 0 0
// 10 227.04
// 15 362.78
// 20 517.35
// 22.5 602.97
// 30 901.67
// Enter x at which interpolated value is to be calculated:16
// value at 16.000000 is 392.070557