#include <stdint.h>
#include <stdio.h>

int main() {
  { // UINT_MAX.
    uint32_t x = 0xffffffffu;
    printf("uint : int = %u : %d\n", x, (int32_t)x);

    int32_t y = -1;
    printf("uint : int = %u : %d\n", (uint32_t)y, y);
    /*
      uint : int = 4294967295 : -1
      uint : int = 4294967295 : -1
    */
  }

  {
    // INT_MAX.
    int32_t x = 0x80000000;
    printf("uint : int = %u : %d\n", (uint32_t)x, x);

    int32_t y = 0x80000000;
    printf("uint : int = %u : %d\n", (uint32_t)y, y);
    /*
      uint : int = 2147483648 : -2147483648
      uint : int = 2147483648 : -2147483648
    */
  }

  { // overflow.
    int32_t x = 0x7fffffff;
    int32_t y = 0x5;
    printf("%d + %d = %d\n", x, y, x + y);
  }

  { // signed truncate.
    int32_t x = 0x0000ffff;
    printf("int : short = %d : %d\n", x, (int16_t)x);

    int32_t y = 0x0001ffff;
    printf("int : short = %d : %d\n", y, (int16_t)y);
    /*
      int : short = 65535 : -1
      int : short = 131071 : -1
    */
  }

  { // unsigned truncate.
    uint32_t x = 0x0000ffffu;
    printf("int : short = %d : %d\n", x, (uint16_t)x);

    uint32_t y = 0x0001ffffu;
    printf("int : short = %d : %d\n", y, (uint16_t)y);
    /*
      int : short = 65535 : 65535
      int : short = 131071 : 65535
    */
  }

  { printf("%0b\n", 12345); }

  return 0;
}
