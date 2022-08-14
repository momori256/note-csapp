#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *f(void *args) {
  int *pn = (int *)args;
  printf("f %d\n", *pn);
  *pn *= 2;
  pthread_detach(pthread_self());
  return NULL;
}

int main() {
  int n = 5;

  pthread_t tid;
  if (pthread_create(&tid, NULL, f, (void *)&n)) {
    exit(1);
  }
  pthread_join(tid, NULL);
  printf("main %d\n", n);
}
