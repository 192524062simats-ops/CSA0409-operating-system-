#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

void *threadFunction(void *arg)
{
    printf("Child thread is running.\n");

    printf("Child thread ID: %lu\n",
           (unsigned long)pthread_self());

    pthread_exit(NULL);
}

int main()
{
    pthread_t thread1, thread2;

    /* Create thread */
    printf("Creating thread...\n");

    pthread_create(&thread1, NULL, threadFunction, NULL);

    printf("Thread created successfully.\n");

    /* Equal */
    if (pthread_equal(thread1, pthread_self()))
        printf("Thread IDs are equal.\n");
    else
        printf("Thread IDs are not equal.\n");

    /* Join */
    pthread_join(thread1, NULL);

    printf("Thread joined successfully.\n");

    /* Create another thread */
    pthread_create(&thread2, NULL, threadFunction, NULL);

    pthread_join(thread2, NULL);

    printf("All threads completed.\n");

    return 0;
}
