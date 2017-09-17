#include "easy_numbers.h"

easy e_absolute_value (easy e)
{
  if (e < 0)
    return -e;
  return e;
}

easy e_squared (easy e)
{
  return e_times(e, e);
}

easy e_squares (easy e1, easy e2)
{
  return e_squared(e1) + e_squared(e2);
}

easy e_inverse (easy e)
{
  return e_by(EASY_ONE, e);
}
