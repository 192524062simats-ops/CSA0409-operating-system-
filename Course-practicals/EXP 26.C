#include<stdio.h>
int main(){
FILE *f;
char name[50],data[100];

printf("Enter file name: ");
scanf("%s",name);
getchar();

f=fopen(name,"w");
if(f==NULL){
printf("File cannot be created");
return 1;
}

printf("Enter data: ");
fgets(data,100,stdin);
fprintf(f,"%s",data);
fclose(f);

f=fopen(name,"r");
printf("File contents: ");
fgets(data,100,f);
printf("%s",data);
fclose(f);

return 0;
}
