#include <stdio.h>
#include <pthread.h> 
#include <semaphore.h>

int count = 0, rcount = 0;
sem_t rd, wr;

void *writer(void *p) {
    int *i = (int *)p;
    sem_wait(&wr);
    printf("\nWriter %d writes page number %d", *i, ++count);
    sem_post(&wr);
}

void *reader(void *p) {
    int *i = (int *)p;
    sem_wait(&rd);
    rcount++;
    if(rcount == 1) sem_wait(&wr);
    sem_post(&rd);
    printf("\nReader %d reads page number %d ", *i, count);
    sem_wait(&rd);
    rcount--;
    if(rcount == 0) sem_post(&wr);
    sem_post(&rd);
}

int main() {
    sem_init(&rd, 0, 1);
    sem_init(&wr, 0, 1);
    int a[] = {1, 2, 3, 1, 2, 3};
    pthread_t p[6];
    for(int i=0; i<3; i++) pthread_create(&p[i], NULL, writer, &a[i]);
    for(int i=3; i<6; i++) pthread_create(&p[i], NULL, reader, &a[i]);
    for(int i=0; i<6; i++) pthread_join(p[i], NULL);
    printf("\n");
}