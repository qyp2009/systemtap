#include <stdlib.h>

void fun() {
  malloc(1000);
}

int main(int argc, char *argv[]) {
  fun();
  return 0;
}
