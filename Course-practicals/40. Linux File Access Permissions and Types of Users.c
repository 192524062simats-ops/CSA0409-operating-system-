#include <stdio.h>
#include <sys/stat.h>

int main()
{
    char *filename = "sample.txt";
    struct stat file;

    if (stat(filename, &file) != 0)
    {
        printf("File does not exist.\n");
        return 1;
    }

    printf("File: %s\n\n", filename);

    printf("Owner Permissions:\n");

    printf("Read    : %s\n",
           (file.st_mode & S_IRUSR) ? "Yes" : "No");

    printf("Write   : %s\n",
           (file.st_mode & S_IWUSR) ? "Yes" : "No");

    printf("Execute : %s\n",
           (file.st_mode & S_IXUSR) ? "Yes" : "No");

    printf("\nGroup Permissions:\n");

    printf("Read    : %s\n",
           (file.st_mode & S_IRGRP) ? "Yes" : "No");

    printf("Write   : %s\n",
           (file.st_mode & S_IWGRP) ? "Yes" : "No");

    printf("Execute : %s\n",
           (file.st_mode & S_IXGRP) ? "Yes" : "No");

    printf("\nOthers Permissions:\n");

    printf("Read    : %s\n",
           (file.st_mode & S_IROTH) ? "Yes" : "No");

    printf("Write   : %s\n",
           (file.st_mode & S_IWOTH) ? "Yes" : "No");

    printf("Execute : %s\n",
           (file.st_mode & S_IXOTH) ? "Yes" : "No");

    return 0;
}
