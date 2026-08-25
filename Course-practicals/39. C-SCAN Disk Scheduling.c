#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[50];
    int n, head, diskSize;
    int i, j, temp;
    int totalMovement = 0;

    printf("Enter disk size: ");
    scanf("%d", &diskSize);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request sequence:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    /* Sort requests */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nSeek Sequence:\n");
    printf("%d", head);

    /* Move towards right */
    for (i = 0; i < n; i++)
    {
        if (request[i] >= head)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    /* Move to end */
    totalMovement += abs(head - (diskSize - 1));
    head = diskSize - 1;
    printf(" -> %d", head);

    /* Jump to beginning */
    totalMovement += diskSize - 1;
    head = 0;
    printf(" -> %d", head);

    /* Service remaining requests */
    for (i = 0; i < n; i++)
    {
        if (request[i] < head)
        {
            totalMovement += abs(head - request[i]);
            head = request[i];
            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal Head Movement = %d cylinders\n",
           totalMovement);

    return 0;
}
