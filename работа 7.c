#include <stdio.h>
int main()
{
 setlocale(0,"");
 int n;
 printf("Введите количетсво последовательностей\n");
 printf("n:");
 scanf("%d", &n);
 float a[n],b[n],c[n],max_a,max_b,max_c,x[n],y[n];
  for (int i=1;i<=n;i++)
 {
  printf("Введите %d последовательность чисел\n", i);
  printf("a[%d]=",i);
  scanf("%f",  &a[i]);
  printf("b[%d]=",i);
  scanf("%f",  &b[i]);
  printf("c[%d]=",i);
  scanf("%f",  &c[i]);
 }
 max_a=a[1];
 max_b=b[1];
 max_c=c[1];
 for(int i=1;i<=n;i++)
 {
  if (a[i]>=max_a)
  max_a=a[i];
  if (b[i]>=max_b)
  max_b=b[i];
  if (c[i]>=max_c)
  max_c=c[i];
 }
 for(int i=1;i<=n;i++)
 {
  x[i]=(max_a+max_b)-(a[i]+b[i])/2;
  y[i]=(max_b+max_c)-(b[i]+c[i])/2;
 }
 printf("\nX последовательность чисел\n");
 for(int i=1;i<=n;i++)
 {
  printf("x[%d]=%.2f\n",i,x[i]);
  }
  printf("\nY последовательность чисел\n");
  for(int i=1;i<=n;i++)
  {
      printf("y[%d]=%.2f\n",i,y[i]);
  }
 printf("\nmax_a=%.2f max_b=%.2f max_c=%.2f\n",max_a,max_b,max_c);
 printf("\nКОНЕЦ\n");
 return 0;
}
