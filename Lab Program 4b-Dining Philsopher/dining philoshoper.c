#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5
sem_t chopstick[N];

void *philosopher(void *num) {
    int id = *(int *)num;

    while (1) {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);


        sem_wait(&chopstick[id]);
        sem_wait(&chopstick[(id + 1) % N]);

        printf("Philosopher %d is eating...\n", id);
        sleep(2);


        sem_post(&chopstick[id]);
        sem_post(&chopstick[(id + 1) % N]);

        printf("Philosopher %d finished eating and put down chopsticks.\n", id);
        sleep(1);
    }
}

int main() {
    pthread_t tid[N];
    int i, phil[N];


    for (i = 0; i < N; i++) {
        sem_init(&chopstick[i], 0, 1);
    }
    for (i = 0; i < N; i++) {
        phil[i] = i;
        pthread_create(&tid[i], NULL, philosopher, &phil[i]);
    }


    for (i = 0; i < N; i++) {
        pthread_join(tid[i], NULL);
    }

    return 0;
}


