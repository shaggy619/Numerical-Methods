#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.001
#define f(x) x*x-4*x-10
int main()
{
	float x0,x1,x2,f0,f1,f2;
	int i=0;
	system("cls");
	printf("Enter the two values: ");
	scanf("%f%f",&x0,&x1);
	do
	{
		f0=f(x0);
		f1=f(x1);
		x2=((x0*f1)-(x1*f0))/(f1-f0);
		f2=f(x2);
		f0=f1;
		f1=f2;
		x0=x1;
		x1=x2;
		i++;
	    printf("The number of iterations is %d\n",i);
		printf("\nThe root is %f",x2);
	}
	while(fabs(x2)>e);
	return 0;
}