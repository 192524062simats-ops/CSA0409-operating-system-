#include <stdio.h>

int main()
{
    int n;
    int blocks[50];
    int i;

    printf("Enter number of blocks in the file: ");
    scanf("%d", &n);

    printf("Enter the disk block numbers:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nLinked File Allocation:\n");

    printf("First Block = %d\n", blocks[0]);
    printf("Last Block  = %d\n", blocks[n - 1]);

    printf("\nBlock\tNext Block\n");

    for (i = 0; i < n - 1; i++)
    {
        printf("%d\t%d\n", blocks[i], blocks[i + 1]);
    }

    printf("%d\tNULL\n", blocks[n - 1]);

    return 0;
}
