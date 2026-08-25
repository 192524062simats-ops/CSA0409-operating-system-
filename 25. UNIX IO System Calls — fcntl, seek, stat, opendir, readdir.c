#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

int main()
{
    int fd;
    struct stat fileStat;
    DIR *dir;
    struct dirent *entry;

    /* Create and open a file */
    fd = open("sample.txt", O_CREAT | O_RDWR, 0644);

    if (fd == -1)
    {
        printf("Error opening file.\n");
        return 1;
    }

    printf("File opened successfully.\n");

    /* fcntl() */
    int flags = fcntl(fd, F_GETFL);
    printf("File access mode obtained using fcntl().\n");

    /* lseek() */
    lseek(fd, 0, SEEK_END);
    printf("File pointer moved using lseek().\n");

    /* stat() */
    if (stat("sample.txt", &fileStat) == 0)
    {
        printf("File size: %ld bytes\n", fileStat.st_size);
        printf("File inode: %ld\n", fileStat.st_ino);
    }

    close(fd);

    /* opendir() */
    dir = opendir(".");

    if (dir == NULL)
    {
        printf("Unable to open directory.\n");
        return 1;
    }

    printf("\nFiles and directories:\n");

    /* readdir() */
    while ((entry = readdir(dir)) != NULL)
    {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    return 0;
}
