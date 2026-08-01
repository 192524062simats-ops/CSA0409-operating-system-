#include <stdio.h>

int main()
{
    FILE *source, *destination;
    char ch;
    char src[100], dest[100];

    printf("Enter source file name: ");
    scanf("%s", src);

    printf("Enter destination file name: ");
    scanf("%s", dest);

    source = fopen(src, "r");

    if(source == NULL)
    {
        printf("Source file not found.");
        return 0;
    }

    destination = fopen(dest, "w");

    while((ch = fgetc(source)) != EOF)
    {
        fputc(ch, destination);
    }

    fclose(source);
    fclose(destination);

    printf("File copied successfully.");

    return 0;
}
