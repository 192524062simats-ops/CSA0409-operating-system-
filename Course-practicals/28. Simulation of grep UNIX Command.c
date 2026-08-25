#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;
    char filename[50];
    char pattern[50];
    char line[200];
    int lineNumber = 1;
    int found = 0;

    printf("Enter file name: ");
    scanf("%s", filename);

    printf("Enter word to search: ");
    scanf("%s", pattern);

    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return 1;
    }

    printf("\nLines containing '%s':\n", pattern);

    while (fgets(line, sizeof(line), fp) != NULL)
    {
        if (strstr(line, pattern) != NULL)
        {
            printf("%d: %s", lineNumber, line);
            found = 1;
        }

        lineNumber++;
    }

    if (!found)
    {
        printf("Pattern not found.\n");
    }

    fclose(fp);

    return 0;
}
