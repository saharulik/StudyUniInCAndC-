#include <stdio.h>
float     summa(int n1,int n2,int a2,int a1,int a0)
{
    int j;
    float s=0;
    for (j=n1;j<=n2;j++)
    s=s+pow(j,3)*a2+a1*pow(j,2)+a0;
   return s;
        }
int  main(void)
{
int  n, m;
float  y;
setlocale(0,"");
    printf("n:");
    scanf("%d", &n);
    printf("m:");
    scanf("%d", &m);
    y =(float)(1+summa(1, n, 1, 2, 3))/(2+summa(3, m, 0, 2, -1));
   printf("y=%.2f", y);
return 0;
}
