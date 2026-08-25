#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[50];
    int n, head, diskSize, direction;
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

    printf("Enter direction (0 = left, 1 = right): ");
    scanf("%d", &direction);

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

    if (direction == 1)
    {
        for (i = 0; i < n; i++)
        {
            if (request[i] >= head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }

        totalMovement += abs(head - (diskSize - 1));
        head = diskSize - 1;
        printf(" -> %d", head);

        for (i = n - 1; i >= 0; i--)
        {
            if (request[i] < head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }
    }
    else
    {
        for (i = n - 1; i >= 0; i--)
        {
            if (request[i] <= head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }

        totalMovement += abs(head - 0);
        head = 0;
        printf(" -> %d", head);

        for (i = 0; i < n; i++)
        {
            if (request[i] > head)
            {
                totalMovement += abs(head - request[i]);
                head = request[i];
                printf(" -> %d", head);
            }
        }
    }

    printf("\n\nTotal Head Movement = %d cylinders\n",
           totalMovement);

    return 0;
}
