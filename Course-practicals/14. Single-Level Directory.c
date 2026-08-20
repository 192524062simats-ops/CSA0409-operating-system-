#include<stdio.h>
#include<string.h>
int main(){
char files[20][20],name[20];
int n=0,i,ch;
while(1){
printf("\n1.Create 2.Search 3.Delete 4.Display 5.Exit\n");
printf("Enter choice: ");
scanf("%d",&ch);
if(ch==1){
printf("Enter file name: ");
scanf("%s",files[n++]);
printf("File created\n");
}
else if(ch==2){
printf("Enter file name: ");
scanf("%s",name);
for(i=0;i<n;i++)
if(strcmp(files[i],name)==0)break;
if(i<n)printf("File found\n");
else printf("File not found\n");
}
else if(ch==3){
printf("Enter file name: ");
scanf("%s",name);
for(i=0;i<n;i++)
if(strcmp(files[i],name)==0){
files[i][0]='\0';
printf("File deleted\n");
break;
}
}
else if(ch==4){
printf("Files:\n");
for(i=0;i<n;i++)
if(files[i][0]!='\0')printf("%s\n",files[i]);
}
else break;
}
return 0;
}
