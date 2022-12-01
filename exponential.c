#include <stdio.h>
#include <math.h>

int main()
{
    int n,i,j;
    float x[100],f[100],fd[100],sx=0,slgy=0,sxlgy=0,sx2=0,b,a,R;
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
        slgy += log(f[i]);
        sxlgy += x[i] * log(f[i]);
        sx2 += x[i] * x[i];
    }
    
    b = ((n * sxlgy) - (sx * slgy)) / ((n * sx2) - (sx * sx));
    R = (slgy / n) - ( (b * sx) / n);
    a = exp(R);

    printf("a = %f\nb = %f\n",a,b); 
    printf("y = %.3f e^(%.3fx)",a,b);

}

//Enter number of data points: 6
//Enter data points and functional value respectively:
//0.4 750
//0.8 1000
//1.2 1400
//1.6 2000
//2 2700
//2.3 3750
//a = 519.498230
//b = 0.841723
//y = 519.498 e^(0.842x)
