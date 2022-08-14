struct S {
  char c;
  int i;
};

int f(struct S *s) {
  int x = (int)s->c;
  return x + s->i;
}
