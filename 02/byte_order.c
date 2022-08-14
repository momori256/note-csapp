#include <stdio.h>

void show_bytes(unsigned char* p, int size) {
  for (int i = 0; i < size; ++i) {
    printf("%02x ", p[i]);
  }
  puts("");
}

int main() {
  {
    int x = 0x123456;
    show_bytes((unsigned char*)&x, sizeof(x));
  }

  {
    float x = 1234.56f;
    show_bytes((unsigned char*)&x, sizeof(x));
  }
  return 0;
}
