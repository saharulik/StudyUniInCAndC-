#include <stdio.h>
#include <stdlib.h>
float doSUB(float a,float b)
{
    int d;
    d=a-b;
    return d;
}
float doSUM(float a,float b)
{
    float d;
    d=a+b;
    return d;
}

float gh(float (*func)(float a,float b))
{
  float fi[4],min;
  fi[1]=func(5,8);
  fi[2]=func(-5,2);
  fi[3]=func(1,3);
  fi[4]=func(0,2);
  min=fi[1];
  for(int i=1;i<=4;i++)
 {
  if (fi[i]<=min)
  min=fi[i];
 }
 return min;
}
int main()
{
  float mem[2];
  mem[1]=gh(doSUM);
  mem[2]=gh(doSUB);
printf("min:%f\n",mem[1]);
printf("min: %f\n",mem[2]);
return 0;
}
