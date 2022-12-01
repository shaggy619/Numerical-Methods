#include <stdio.h>

int main()
{
    int n,i,j;
    float x[100],f[100],fd[100],sx=0,sy=0,sxy=0,sx2=0,b,a;
    printf("Enter number of data points: ");
    scanf("%d",&n);
    printf("Enter data points and functional value respectively:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&f[i]);
    }

    for(i=0;i<n;i++)
    {
        sx = sx + x[i];
        sy += f[i];
        sxy += x[i] * f[i];
        sx2 += x[i] * x[i];
    }
    
    b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx));
    a = (sy / n) - ( (b * sx) / n);

    printf("a = %.2f\nb = %.2f\n",a,b); 
    printf("y = %.3f+%.3fx",a,b);

}

//Enter number of data points: 5
//Enter data points and functional value respectively:
//1 3
//2 5
//3 7
//4 10
//5 12
//a = 0.500000
//b = 2.300000
//y = 0.50+2.30x
