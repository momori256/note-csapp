#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct stat stat_t;

off_t get_fsize(char *path) {
  stat_t buf;
  if (stat(path, &buf) == -1) {
    _exit(1);
  }
  return buf.st_size;
}

char *load(char *path) {
  off_t sz = get_fsize(path);
  int fd = open(path, O_RDONLY);

  char *p = (char *)mmap(NULL, sz, PROT_READ, MAP_PRIVATE, fd, 0);
  if (p == MAP_FAILED) {
    _exit(1);
  }
  close(fd);
  return p;
}

int main(int argc, char *argv[]) {
  char *p = load(argv[1]);
  size_t len = strlen(p);
  write(STDOUT_FILENO, p, len);
  munmap(p, len);
  return 0;
}
