#include <stdio.h>
int main()
{
 setlocale(0,"");
 int n,m,f,t;
 printf("������� ���������� �����\n");
 printf("n:");
 scanf("%d", &n);
 printf("������� ���������� ��������\n");
 printf("m:");
 scanf("%d", &m);
 float a[n][m];
  for (int i=1;i<=n;i++)
 {
for (int j=1;j<=m;j++)
 {
  printf("a[%d][%d]=",i,j);
  scanf("%f",  &a[i][j]);
 }
 }
for (int i=1;i<n;i++)
{
    f=a[i][1];
    t=a[i][m];
    a[i][1]=t;
    a[i][m]=f;
}
for (int i=1;i<=n;i++)
{
for (int j=1;j<=m;j++)
{
printf("a[%d][%d]=%f",i,j,a[i][j]);
}
printf("\n");
}
printf("\n�����\n");
  return 0;
}
