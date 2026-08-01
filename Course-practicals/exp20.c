#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex, writeBlock;
int data = 0;
int readCount = 0;

void *reader(void *arg)
{
    sem_wait(&mutex);

    readCount++;

    if(readCount == 1)
        sem_wait(&writeBlock);

    sem_post(&mutex);

    printf("Reader reads data = %d\n", data);

    sem_wait(&mutex);

    readCount--;

    if(readCount == 0)
        sem_post(&writeBlock);

    sem_post(&mutex);

    return NULL;
}

void *writer(void *arg)
{
    sem_wait(&writeBlock);

    data++;

    printf("Writer writes data = %d\n", data);

    sem_post(&writeBlock);

    return NULL;
}

int main()
{
    pthread_t r1, r2, w1;

    sem_init(&mutex, 0, 1);
    sem_init(&writeBlock, 0, 1);

    pthread_create(&r1, NULL, reader, NULL);
    pthread_create(&w1, NULL, writer, NULL);
    pthread_create(&r2, NULL, reader, NULL);

    pthread_join(r1, NULL);
    pthread_join(w1, NULL);
    pthread_join(r2, NULL);

    sem_destroy(&mutex);
    sem_destroy(&writeBlock);

    return 0;
}
