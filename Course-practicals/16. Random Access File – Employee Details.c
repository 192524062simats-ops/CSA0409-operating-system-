#include<stdio.h>
struct emp{
int id;
char name[20];
float salary;
};
int main(){
struct emp e[10];
int n,i,r;
printf("Enter number of employees: ");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter ID, Name and Salary: ");
scanf("%d%s%f",&e[i].id,e[i].name,&e[i].salary);
}
printf("Enter record number to access: ");
scanf("%d",&r);
if(r>=1&&r<=n)
printf("ID: %d\nName: %s\nSalary: %.2f\n",e[r-1].id,e[r-1].name,e[r-1].salary);
else
printf("Invalid record");
return 0;
}
