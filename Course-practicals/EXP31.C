#include<stdio.h>
int main(){
int p[20],f[10],n,m,i,j,k=0,fault=0;
printf("Enter number of pages: ");
scanf("%d",&n);
printf("Enter page reference string: ");
for(i=0;i<n;i++) scanf("%d",&p[i]);
printf("Enter number of frames: ");
scanf("%d",&m);
for(i=0;i<m;i++) f[i]=-1;
for(i=0;i<n;i++){
for(j=0;j<m;j++) if(f[j]==p[i]) break;
if(j==m){
f[k]=p[i];
k=(k+1)%m;
fault++;
}
}
printf("Page Faults = %d\n",fault);
printf("Page Hits = %d\n",n-fault);
return 0;
}
