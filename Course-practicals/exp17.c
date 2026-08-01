#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    int allocation[10][10], maximum[10][10], need[10][10];
    int available[10], finish[10] = {0}, safeSequence[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("Enter Allocation Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter Maximum Matrix:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);

    printf("Enter Available Resources:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &available[i]);

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int flag = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > available[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if(flag)
                {
                    for(k = 0; k < m; k++)
                        available[k] += allocation[i][k];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0)
        {
            printf("System is not in safe state.\n");
            return 0;
        }
    }

    printf("\nSafe Sequence: ");

    for(i = 0; i < n; i++)
        printf("P%d ", safeSequence[i]);

    printf("\n");

    return 0;
}
