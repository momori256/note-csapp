#include <stdint.h>
#include <stdio.h>
#include <x86intrin.h>

#define R (10000)
#define C (10000)

void stwatch(int (*f)(int[R][C]), int a[R][C]) {
  uint64_t t1 = __rdtsc();
  f(a);
  uint64_t t2 = __rdtsc();
  printf("%llu\n", (unsigned long long)(t2 - t1));
}

int f1(int a[R][C]) {
  int sum = 0;
  for (int r = 0; r < R; ++r) {
    for (int c = 0; c < C; ++c) {
      sum += a[r][c];
    }
  }
  return sum;
}

int f2(int a[R][C]) {
  int sum = 0;
  for (int c = 0; c < C; ++c) {
    for (int r = 0; r < R; ++r) {
      sum += a[r][c];
    }
  }
  return sum;
}

int a[R][C];

int main() {
  stwatch(f1, a);
  stwatch(f2, a);
}
