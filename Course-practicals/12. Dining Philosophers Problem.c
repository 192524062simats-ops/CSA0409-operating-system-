#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
sem_t fork[5];

void *philosopher(void *arg){
int i=*(int*)arg;
printf("Philosopher %d is thinking\n",i+1);
sem_wait(&fork[i]);
sem_wait(&fork[(i+1)%5]);
printf("Philosopher %d is eating\n",i+1);
sem_post(&fork[(i+1)%5]);
sem_post(&fork[i]);
return NULL;
}
int main(){
pthread_t p[5];
int i,id[5];
for(i=0;i<5;i++)sem_init(&fork[i],0,1);
for(i=0;i<5;i++){id[i]=i;pthread_create(&p[i],NULL,philosopher,&id[i]);}
for(i=0;i<5;i++)pthread_join(p[i],NULL);
return 0;
}
