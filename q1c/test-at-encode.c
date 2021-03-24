// This is a simple test client for the at-encode module

#include <stdlib.h>
#include <stdio.h>
#include "at-encode.h"
#include "slurp.h"

int main(void) {
  char *pic = slurp();
  if (pic) {
    int len = 0;
    int *data = at_encode(pic, &len);
    if (data) {
      for (int i = 0; i < len; ++i) {
        if (data[i]) {
          printf("%d ", data[i]);
        } else {
          printf("0\n");
        }
      }
    }
    free(data);
    free(pic);
  }
}
