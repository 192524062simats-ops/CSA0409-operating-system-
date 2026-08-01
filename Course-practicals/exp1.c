#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid;

    pid = fork();

    if(pid == 0)
    {
        printf("\nChild Process");
        printf("\nPID = %d", getpid());
        printf("\nParent PID = %d\n", getppid());
    }
    else if(pid > 0)
    {
        printf("\nParent Process");
        printf("\nPID = %d", getpid());
        printf("\nParent PID = %d\n", getppid());
    }
    else
    {
        printf("Process creation failed.");
    }

    return 0;
}
