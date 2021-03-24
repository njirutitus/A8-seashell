// This is a simple test client for the at-decode module

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "at-decode.h"
#include "read-ints.h"

int main(void) {
  int len = 0;
  int *data = read_ints(&len);
  if (data) {
    char *pic = at_decode(data, len);
    printf("%s", pic);
    free(pic);
    free(data);
  }
}
