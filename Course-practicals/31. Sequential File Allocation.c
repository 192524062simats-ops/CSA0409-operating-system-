#include <stdio.h>

int main()
{
    int start, length;
    int i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter number of blocks required: ");
    scanf("%d", &length);

    printf("\nFile allocation using Sequential Allocation:\n");
    printf("Block\tFile Block\n");

    for (i = 0; i < length; i++)
    {
        printf("%d\t%d\n", start + i, i + 1);
    }

    printf("\nFile allocated successfully.\n");

    return 0;
}
