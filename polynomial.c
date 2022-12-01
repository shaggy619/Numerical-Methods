#include<stdio.h>
#include<math.h>
int main()
{
 int n, I, j, k,i;
 float sumx=0, sumxsq=0, sumy=0, sumxy=0, x, y;
 float sumx3=0, sumx4=0, sumxsqy=0, a[20][20], u = 0.0, b[20];
 printf("enter number of data points: ");
 scanf("%d",&n);
 
 printf("Enter data points and functional value respectively\n");
 for(i = 0; i < n; i++)
 {
  scanf("%f %f", &x, &y);
  sumx += x;
  sumxsq += pow(x, 2);
  sumx3 += pow(x, 3);
  sumx4 += pow(x, 4);
  sumy += y;
  sumxy += x * y;
  sumxsqy += pow(x, 2) * y;
 }
 a[0][0] = n;
 a[0][1] = sumx;
 a[0][2] = sumxsq;
 a[0][3] = sumy;
 a[1][0] = sumx;
 a[1][1] = sumxsq;
 a[1][2] = sumx3;
 a[1][3] = sumxy;
 a[2][0] = sumxsq;
 a[2][1] = sumx3;
 a[2][2] = sumx4;
 a[2][3] = sumxsqy;
 
 printf("The augmented matrix is\n");
 for(i = 0; i < 3; i++)
 {
  for(j = 0; j <= 3; j++)
   printf("%.1f\t", a[i][j]);
  printf("\n");
 }
 for(k = 0; k <= 2; k++)
 {
  for(i = 0; i <= 2; i++)
  {
   if(i != k)
    u = a[i][k]/a[k][k];
   for(j = k; j <= 3; j++)
    a[i][j] = a[i][j] - u * a[k][j];
  }
 }
 
 for(i = 0; i < 3; i++)
 {
  b[i] = a[i][3]/a[i][i];
  printf("\nb[%d] = %.1f",i, b[i]);
 }
 printf("\n");
 printf("y = %.1fx +  %.1fx + %.1fx^2", b[0], b[1], b[2]);
}

//enter number of data points: 4
//Enter data points and functional value respectively
//1 6
//2 11
//3 18
//4 27
//The augmented matrix is
//4.0     10.0    30.0    62.0
//10.0    30.0    100.0   190.0
//30.0    100.0   354.0   644.0
//
//b[0] = 3.0
//b[1] = 2.0
//b[2] = 1.0
//y = 3.0x +  2.0x + 1.0x^2
