#include<stdio.h>
#include<conio.h>
#include<math.h>
#define e 0.001
#define f(x) cos(x)-3*x+1
#define g(x) (1+cos(x))/3
int main()
{
	float x0,x1;
	int i=0,N;
	system("cls");
	printf("Enter a number: ");
	scanf("%f",&x0);
	
	do
	{
		x1 = g(x0);
	    printf("%d\t%f\t%f\t%f\t%f\n",i, x0, f(x0), x1, f(x1));
		i++;
		if(i<0)
		{
			printf("It is not convergernt");
			exit(0);
		}
		else
		x0=x1;
	}
	while(fabs(f(x1))>e);
	printf("\nThe root is %f\n", x1);
	printf("The no of iterations is %d",i);
	 getch();
	 return(0);
}