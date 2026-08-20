#include<stdio.h>
int main(){
int n,m,i,j,k,alloc[10][10],max[10][10],need[10][10],avail[10],finish[10]={0},safe[10],count=0,ok;
printf("Enter processes and resources: ");
scanf("%d%d",&n,&m);
printf("Enter Allocation matrix:\n");
for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&alloc[i][j]);
printf("Enter Max matrix:\n");
for(i=0;i<n;i++)for(j=0;j<m;j++)scanf("%d",&max[i][j]);
printf("Enter Available resources: ");
for(j=0;j<m;j++)scanf("%d",&avail[j]);
for(i=0;i<n;i++)for(j=0;j<m;j++)need[i][j]=max[i][j]-alloc[i][j];
while(count<n){
ok=0;
for(i=0;i<n;i++)if(!finish[i]){
for(j=0;j<m;j++)if(need[i][j]>avail[j])break;
if(j==m){
for(k=0;k<m;k++)avail[k]+=alloc[i][k];
safe[count++]=i;
finish[i]=1;
ok=1;
}
}
if(!ok)break;
}
if(count==n){
printf("Safe sequence: ");
for(i=0;i<n;i++)printf("P%d ",safe[i]);
}else printf("System is unsafe");
return 0;
}
