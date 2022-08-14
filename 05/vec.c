#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <x86intrin.h>

typedef float data_t;
#define ELEM (0)
#define OP *

struct Vec {
  long len;
  data_t *data;
};

typedef struct Vec Vec;

void create_vec(Vec **v, uint64_t len) {
  *v = (Vec *)malloc(sizeof(Vec));
  (*v)->len = len;
  (*v)->data = (data_t *)calloc(len, sizeof(data_t));
  if ((*v)->data == NULL) {
    exit(1);
  }
}

void destroy_vec(Vec *v) { free(v); }

// Start.
void combine1(Vec *v, data_t *dst) {
  *dst = ELEM;
  for (uint64_t i = 0; i < v->len; ++i) {
    *dst = *dst OP v->data[i];
  }
}

// Cache struct data to local variables.
void combine2(Vec *v, data_t *dst) {
  *dst = ELEM;
  data_t *p = v->data;
  uint64_t len = v->len;
  for (uint64_t i = 0; i < len; ++i) {
    *dst = *dst OP p[i];
  }
}

// Reduce memory accesses.
void combine3(Vec *v, data_t *dst) {
  data_t d = ELEM;
  data_t *p = v->data;
  uint64_t len = v->len;
  for (uint64_t i = 0; i < len; ++i) {
    d = d OP p[i];
  }
  *dst = d;
}

// Loop unrolling 2 x 2.
void combine4(Vec *v, data_t *dst) {
  data_t d1 = ELEM;
  data_t d2 = ELEM;

  data_t *p = v->data;
  uint64_t len = v->len;

  uint64_t i = 0;
  for (i = 0; i + 1 < len; i += 2) {
    d1 = d1 OP p[i];
    d2 = d2 OP p[i + 1];
  }

  for (; i < len; ++i) {
    d1 = d1 OP p[i];
  }
  *dst = d1 OP d2;
}

// Loop unrolling 5 x 5.
void combine5(Vec *v, data_t *dst) {
  data_t d1 = ELEM;
  data_t d2 = ELEM;
  data_t d3 = ELEM;
  data_t d4 = ELEM;
  data_t d5 = ELEM;

  data_t *p = v->data;
  uint64_t len = v->len;

  uint64_t i = 0;
  for (i = 0; i + 4 < len; i += 5) {
    d1 = d1 OP p[i];
    d2 = d2 OP p[i + 1];
    d3 = d3 OP p[i + 2];
    d4 = d4 OP p[i + 3];
    d5 = d5 OP p[i + 4];
  }

  for (; i < len; ++i) {
    d1 = d1 OP p[i];
  }
  *dst = d1 OP d2 OP d3 OP d4 OP d5;
}

int main(int argc, char *argv[]) {
  int type = atoi(argv[1]);
  uint64_t len = atoll(argv[2]);

  Vec *v;
  create_vec(&v, len);

  double avg = 0.0;
  data_t dst;
  for (int i = 0; i < 3; ++i) {
    uint64_t t1 = __rdtsc();
    switch (type) {
    case 1:
      combine1(v, &dst);
      break;
    case 2:
      combine2(v, &dst);
      break;
    case 3:
      combine3(v, &dst);
      break;
    case 4:
      combine4(v, &dst);
      break;
    case 5:
      combine5(v, &dst);
      break;
    }

    uint64_t t2 = __rdtsc();
    avg += (t2 - t1) / 3.0;
  }
  printf("%lf\n", avg / len);

  destroy_vec(v);
  return 0;
}
