#include <stdio.h>
#include "easy_numbers.h"

relative e_relative (easy e)
{
  return (relative) (e >> EASE);
}

relative e_ease (easy e)
{
  return (relative) (e & SUP_EASE);
}

char * e_to_a (char *a, size_t alen, easy e)
{
  relative rel = e_relative(e);
  relative ease = e_ease(e);
  snprintf(a, alen, "%lli.%lli", rel, ease);
  return a;
}
