// A simple test client for the read-ints module

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "read-ints.h"

int main(void) {
  int len = 0;
  int *data = read_ints(&len);
  if (data == NULL) {
    assert(len == 0);
    printf("NO INPUT\n");
  } else {
    printf("count: %d\n", len);
    printf("first: %d\n", data[0]);
    printf("last: %d\n", data[len - 1]);
    free(data);
  }
}
