#include <stdio.h>

int main()
{
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n, i, j, bestIndex;

    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    printf("Enter size of each memory block:\n");
    for (i = 0; i < m; i++)
    {
        printf("Block %d: ", i + 1);
        scanf("%d", &blockSize[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process %d: ", i + 1);
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }

    /* Best Fit Allocation */
    for (i = 0; i < n; i++)
    {
        bestIndex = -1;

        for (j = 0; j < m; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIndex == -1 ||
                    blockSize[j] < blockSize[bestIndex])
                {
                    bestIndex = j;
                }
            }
        }

        if (bestIndex != -1)
        {
            allocation[i] = bestIndex;
            blockSize[bestIndex] -= processSize[i];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock No.\n");

    for (i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t", i + 1, processSize[i]);

        if (allocation[i] != -1)
            printf("B%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
