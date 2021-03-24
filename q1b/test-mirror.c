// A simple test client for the mirror module

#include <stdio.h>
#include <stdlib.h>
#include "read-str.h"
#include "mirror.h"

int main(void) {
  while (1) {
    char *str = read_str();
    if (str == NULL) {
      break;
    }
    char *strrts = mirror(str);
    printf("%s\n", strrts);
    free(str);      
    free(strrts);
  }
}
