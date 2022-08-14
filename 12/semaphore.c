#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned long long ull;

ull sum = 0;
sem_t sem;

void *f(void *args) {
  // pthread_detach(pthread_self());
  int *p = (int *)args;

  sem_wait(&sem);
  sum += *p;
  sem_post(&sem);

  free(p);
  return NULL;
}

int main() {
  int pshared = 0; // shared in this process.
  sem_init(&sem, pshared, 1);

  int n = 10000;
  pthread_t tids[n];
  for (int i = 0; i < n; ++i) {
    int *p = (int *)malloc(sizeof(int));
    *p = i;
    if (pthread_create(&tids[i], NULL, f, (void *)p)) {
      exit(1);
    }
  }

  for (int i = 0; i < n; ++i) {
    pthread_join(tids[i], NULL);
  }
  sem_destroy(&sem);

  printf("actual: %llu, expected: %llu\n", sum, (ull)n * (n - 1) / 2);
}
