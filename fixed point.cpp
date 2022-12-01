#include<stdio.h>
#include<math.h>
#define f(x) cos(x)-3*x+1
#define g(x) (cos(x)+1)/3
int main()
{
	int count;
	float x0,x1,err,eps;
	printf("enter theguess\n");
	scanf("%f",&x0);
	printf("enter the tolerence\n");
	scanf("%f",&eps);
	count=1;
	begin:
	x1=g(x0);
	err=fabs((x1-x0)/x1);
	if(err<eps)
	{
		printf("root=%f\n",x1);
		printf("number of iteration=%d\n",count);
	}
	else
	{
		x0=x1;
		count=count+1;
		goto begin;
	}
	return 0;
}
