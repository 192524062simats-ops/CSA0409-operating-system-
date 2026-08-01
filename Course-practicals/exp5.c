#include <stdio.h>

int main()
{
    int n,i,j,temp;
    int bt[20],p[20],wt[20],tat[20];

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Burst Time: ");
        scanf("%d",&bt[i]);

        printf("Priority: ");
        scanf("%d",&p[i]);
    }

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(p[i]>p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;

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

    printf("\nPriority\tBT\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("%d\t\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);

    return 0;
}
