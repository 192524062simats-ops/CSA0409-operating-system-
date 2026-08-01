#include <stdio.h>
#include <pthread.h>

void *display(void *arg)
{
    printf("Thread is executing.\n");
    return NULL;
}

int main()
{
    pthread_t thread;

    pthread_create(&thread,NULL,display,NULL);

    pthread_join(thread,NULL);

    printf("Main thread completed.\n");

    return 0;
}
