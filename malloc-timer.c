#include <stdlib.h>
#include <stdio.h>

#include "tester.h"

int
main (int argc, char **argv)
{
  malloc_test();
  calloc_test();
  malloc_plus_memset_test();

  return 0;
}
