#include <stdio.h>

int main()
{
    int n,i,j,temp;
    int bt[20],wt[20],tat[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter Burst Time: ");
        scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j])
            {
                temp=bt[i];
                bt[i]=bt[j];
                bt[j]=temp;
            }
        }
    }

    wt[0]=0;

    for(i=1;i<n;i++)
        wt[i]=wt[i-1]+bt[i-1];

    for(i=0;i<n;i++)
        tat[i]=wt[i]+bt[i];

    printf("\nBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\n",bt[i],wt[i],tat[i]);

    return 0;
}
