#include <stdio.h>
#include <math.h>
float fd[100],x[100];
int factorial(int i)
{
    if(i==0)
        return 1;
    else
        return i * factorial(i-1);
}

float fx(float xp,int n)
{
    int i,j;
    float value,p=1,h,s;
    h = x[1] - x[0];
    s = (xp - x[0]) / h;
    value = fd[0];
    for(i=1;i<n;i++)
    {
        for(j=1;j<=i;j++)
        {
            p *=  (s - j + 1);
        }
        value = value + (fd[i] * p) / factorial(i);
        p = 1;
    }
    return value;
}

int main()
{
    int i,j,k,n;
    float f[100],h,a,b,c,s1,s2,x1,x2,value;
    printf("Enter number of data points: ");
    scanf("%d",&n);
    printf("Enter data points and functional value respectively:\n");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&f[i]);
    }
    h = x[1] - x[0];
    for(i=0;i<n;i++)
        fd[i] = f[i];
    for(i=0;i<n;i++)
    {
        for(j=n-1;j>i;j--)
        {
            fd[j] = fd[j] - fd[j-1];
        }
    }

    a = 0.5 * fd[3];
    b = fd[2] - fd[3];
    c = fd[1] - (fd[2] / 2) + (fd[3] / 3);
    s1 = (-b + sqrt(b * b - 4 * a * c))/(2 * a);
    s2 = (-b - sqrt(b * b - 4 * a * c))/(2 * a);
    x1 = x[0] + s1 * h;
    x2 = x[0] + s2 * h;
    value = (fd[2] + ((6 * s1 - 6) * fd[3]) / 6)/(h * h);
    if(value < 0)
        printf("The maxima is %f at %f\n",fx(x1,n),x1);
    else
        printf("The minima is %f at %f\n",fx(x1,n),x1);
    value = (fd[2] + ((6 * s2 - 6) * fd[3]) / 6)/(h * h);
        if(value < 0)
        printf("The maxima is %f at %f\n",fx(x2,n),x2);
    else
        printf("The minima is %f at %f\n",fx(x2,n),x2);

}
// Enter number of data points: 4
// Enter data points and functional value respectively:
// 0 -5
// 1 -7
// 2 -3
// 3 13
// The minima is -7.000000 at 1.000000
// The maxima is -3.000000 at -1.000000

