#include <stdio.h>

struct process
{
    int at, bt, pr, rt, ct, tat, wt;
};

int main()
{
    struct process p[10];
    int n,i,time=0,completed=0,min,index;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nArrival Time: ");
        scanf("%d",&p[i].at);

        printf("Burst Time: ");
        scanf("%d",&p[i].bt);

        printf("Priority: ");
        scanf("%d",&p[i].pr);

        p[i].rt=p[i].bt;
    }

    while(completed<n)
    {
        min=9999;
        index=-1;

        for(i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].rt>0 && p[i].pr<min)
            {
                min=p[i].pr;
                index=i;
            }
        }

        if(index==-1)
        {
            time++;
            continue;
        }

        p[index].rt--;
        time++;

        if(p[index].rt==0)
        {
            completed++;
            p[index].ct=time;
            p[index].tat=p[index].ct-p[index].at;
            p[index].wt=p[index].tat-p[index].bt;
        }
    }

    printf("\nAT\tBT\tPR\tWT\tTAT\n");

    for(i=0;i<n;i++)
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].at,p[i].bt,p[i].pr,p[i].wt,p[i].tat);

    return 0;
}
