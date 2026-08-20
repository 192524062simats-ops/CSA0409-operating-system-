#include<stdio.h>
#include<string.h>
int main(){
char user[20],file[20];
printf("Enter user name: ");
scanf("%s",user);
printf("Enter file name: ");
scanf("%s",file);
printf("\nUser Directory: %s\n",user);
printf("File Created: %s\n",file);
printf("File Search: %s found\n",file);
return 0;
}
