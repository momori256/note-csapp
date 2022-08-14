int f(int n) {
  int x = 1;

  switch (n) {
  case 51:
    x += 1;
    break;

  case 52:
    x += 2;

  case 53:
    x += 3;
  case 54:
    x += 4;
    break;

  case 55:
  case 56:
    x += 5;
    break;

  default:
    x += 10;
    break;
  }
  return x;
}

int main() {
  int n = 53;
  int m = f(n);
  return m;
}
