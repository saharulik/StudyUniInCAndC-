#include <stdio.h>
#include <math.h>
int main()
{
    setlocale(0, "");
int n;
float step, xn, xk, a, y, x, b, m;

printf("������� n:");
scanf("%d", &n);
printf("������� a:");
scanf("%f", &a);
printf("������� X���:");
scanf("%f", &xn);
printf("������� X���:");
scanf("%f", &xk);

step=(xk-xn)/(n-1);
x=xn;
m=2*pow(a,2);

printf("step=%f\n", step);

printf("%7s %5s %10s\n", "�����", "x", "y");

for(int i=1; i<=n; i++ )
{
y=1.5*pow(cos(a+x/m+pow(x,2)),4);
printf("%5d %10.2f %10.5f\n", i, x, y);
x+=step;
}
return 0;
}
