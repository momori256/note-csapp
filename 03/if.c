#include <stdio.h>

int f1(int x) { return x + 1; }

int f2(int x) { return x + 2; }

int main() {
  unsigned int x = f1(2);
  unsigned int y = f2(3);
  if (x < y) {
    return 0;
  } else {
    return 1;
  }
}
