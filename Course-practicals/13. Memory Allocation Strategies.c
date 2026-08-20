#include<stdio.h>
void allocate(int b[],int nb,int p[],int np,int type){
int i,j,k,best;
for(i=0;i<np;i++){
best=-1;
for(j=0;j<nb;j++){
if(b[j]>=p[i]){
if(best==-1)best=j;
else if(type==1)best=j;
else if(type==2&&b[j]<b[best])best=j;
else if(type==3&&b[j]>b[best])best=j;
}}
if(best!=-1){
printf("Process %d -> Block %d\n",i+1,best+1);
b[best]-=p[i];
}else printf("Process %d -> Not Allocated\n",i+1);
}}
int main(){
int b[10],p[10],nb,np,i;
printf("Enter number of blocks: ");
scanf("%d",&nb);
printf("Enter block sizes: ");
for(i=0;i<nb;i++)scanf("%d",&b[i]);
printf("Enter number of processes: ");
scanf("%d",&np);
printf("Enter process sizes: ");
for(i=0;i<np;i++)scanf("%d",&p[i]);

printf("\nFirst Fit:\n");
allocate(b,nb,p,np,1);

printf("\nBest Fit:\n");
allocate(b,nb,p,np,2);

printf("\nWorst Fit:\n");
allocate(b,nb,p,np,3);
return 0;
}
