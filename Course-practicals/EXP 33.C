#include<stdio.h>
int main(){
int p[20],f[10],t[10],n,m,i,j,k,pos,min,hit=0,time=0;
printf("Enter number of pages: ");
scanf("%d",&n);
printf("Enter page reference string: ");
for(i=0;i<n;i++)scanf("%d",&p[i]);
printf("Enter number of frames: ");
scanf("%d",&m);
for(i=0;i<m;i++)f[i]=-1,t[i]=0;
for(i=0;i<n;i++){
time++;
for(j=0;j<m;j++)if(f[j]==p[i])break;
if(j<m){hit++;t[j]=time;}
else{
for(j=0;j<m;j++)if(f[j]==-1)break;
if(j==m){
min=t[0];pos=0;
for(k=1;k<m;k++)if(t[k]<min)min=t[k],pos=k;
j=pos;
}
f[j]=p[i];t[j]=time;
}
}
printf("Page Faults = %d\n",n-hit);
printf("Page Hits = %d\n",hit);
return 0;
}
