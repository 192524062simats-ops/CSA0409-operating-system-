#include <stdio.h>

int main()
{
    int indexBlock;
    int n;
    int blocks[50];
    int i;

    printf("Enter index block number: ");
    scanf("%d", &indexBlock);

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    printf("Enter the file block numbers:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndex Block: %d\n", indexBlock);

    printf("\nIndex Block Contents:\n");

    for (i = 0; i < n; i++)
    {
        printf("Entry %d -> Block %d\n", i + 1, blocks[i]);
    }

    printf("\nFile allocated successfully.\n");

    return 0;
}
