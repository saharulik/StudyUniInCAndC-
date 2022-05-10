#include <stdio.h>
int main()
{
   setlocale(0,"");
   int n,m;
   float s,v,c,x,j,i,k;
   printf("¬ведите n:",n);
   scanf("%d", &n);
   printf("¬ведите m:",m);
   scanf("%d", &m);
   printf("¬ведите x:",x);
   scanf("%d", &x);
c=0;
v=0;
s=0;
    for (i=1;i<=m;i++)
    {
        c=c+(1/i);
    }
for (j=1;j<=n;j++)
{
    s=s+((j*x)+1)/((2*j)+(x*c));
    for (k=1;k<=m;k++)
    {
        v=v+((k/j)+(j/k));
    }
}
printf("%9s %10s\n", "—умма v", "—умма c");
printf("%8.2f %9.2f\n", v, c);
printf("y=%.2f\n", s);
return 0;
}
