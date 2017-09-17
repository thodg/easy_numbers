#include "easy_numbers.h"

easy e3_dot_product (e3 a, e3 b)
{
  return e_times(a.x, b.x) + e_times(a.y, b.y) + e_times(a.z, b.z);
}

e3 e3_times (e3 a, easy b)
{
  return E3(e_times(a.x, b), e_times(a.y, b), e_times(a.z, b));
}

e3 e3_add (e3 a, e3 b)
{
  return E3(a.x + b.x, a.y + b.y, a.z + b.z);
}

e3 e3_sub (e3 a, e3 b)
{
  return E3(a.x - b.x, a.y - b.y, a.z - b.z);
}

easy e3_along (e3 a, e3 b)
{
  if (b.x > b.y && b.x > b.z)
    return e_by(a.x, b.x);
  if (b.y > b.x && b.y > b.z)
    return e_by(a.y, b.y);
  return e_by(a.z, b.z);
}
