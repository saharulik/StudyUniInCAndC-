#include <stdio.h>

int main()
{
int s=0;
int *mass;
int N;
int otric=0;
int min=100000;
int max=-100000;
int indi;
int indj;
int indk;
int mindi;
int mindj;
int mindk;
int proizved=1;
printf("Enter N:");
scanf("&d",N);
int arr[N][N][N];
printf("Enter elements:\n");
for(int i=0;i<N;i++){
for(int j=0;j<N;j++){
for(int k=0;k<N;k++){
  printf("arr[%d][%d][%d]:",i,j,k);
scanf("%d",arr[i][j][k]);
if(arr[i][j][k]<0)
{
otric=otric+arr[i][j][k];
}
s++;
}
}
}

mass=arr[0][0];
for(int i=0;i<N*N*N;i++){
if(mass[i]<min){
min=mass[i];
indi=i;
}
if(mass[i]>max){
max=mass[i];
mindi=i;
}

}
if(indi<mindi){
for(int i=indi+1;i<mindi;i++){
proizved*=mass[i];

}}else{

for(int i=mindi+1;i<indi;i++){
proizved*=mass[i];
}
}


cout « "Summ otric = " « otric « endl;
cout « "Proizved megdy MIN i MAX = " « proizved « endl;
cout « "Ocenka slognosti: " « s « endl;
cout « "MAX = " « max « endl;
cout « "MIN = " « min « endl;

return 0;
}
