#include <stdio.h>

union Data {
  int i;
  float f;
};

int main() {
  int x = 12345;

  union Data d;
  d.i = 0b01000110010000001110010000000000;

  printf("int: %d, float: %f\n", x, d.f);
  return 0;
}
