// This is a simple test client for the Triple S module

#include <assert.h>
#include <string.h>
#include "triple-s.h"

int main(void) {
  struct triple_s *sss = sss_create();
 
  sss_add(sss, "monkey");
  sss_add(sss, "monkey");
  sss_add(sss, "alligator");
  sss_add_follows(sss, "zebra");
  
  assert(sss_count(sss) == 3);
  
  sss_add(sss, "unicorn");
  sss_remove(sss, "unicorn");
  
  assert(sss_search(sss, "unicorn") == -1);
  assert(sss_search(sss, "monkey") == 1);
  assert(!strcmp(sss_get(sss, 1), "monkey"));
  
  sss_destroy(sss);
}
