#include "easy_numbers.h"

easy e_tangent (angle y)
{
  natural side = SUP_ANGLE / 8;
  if (y < side)
    return y * EASY_ONE / side;
  if (y < side * 2)
    return SUP_EASY / (side * 2 - y);
  if (y == side * 2)
    return SUP_EASY;
  if (y < side * 3)
    return SUP_EASY / (y - side * 2 + 1);
  if (y < side * 5)
    return (side * 4 - y) * EASY_ONE / side;
  if (y < side * 6)
    return SUP_EASY / (y - side * 6);
  if (y == side * 6)
    return SUP_EASY;
  if (y < side * 7)
    return SUP_EASY / (y - side * 6);
  return y;
}

/*
#define SIN_MAX (2 * TANGENT_MAX)

s_t g_sin[SIN_MAX];

static void sin_table ()
{
  unsigned int l;
  s_t d = 0;
  s_t min = 0;
  for (l = 0; l <= A / 2; l++) {
    s_t c;
    s_t max = A;
    g_sin[l] = min;
    for (; c = s_squares(g_sin[l], A - l) - A * A,
           c != 0 &&
           c != d ;) {
      d = c;
      if (c < 0) {
        min = g_sin[l];
        g_sin[l] = (min + max + 1) / 2;
      }
      else {
        max = g_sin[l];
        g_sin[l] = (min + max + 1) / 2;
      }
    }
    if (l > 0)
      g_sin[A - l] = 
  }
}

s_t s_sin (s_t a)
{
  for (; 4 * A <= a; a -= 4 * A);
  for (; a < 0; a += 4 * A);
  if (a < A)
    return g_sin[a];
  if (a < 2 * A)
    return g_sin[2 * A - 1 - a];
  if (a < 3 * A)
    return -g_sin[a - 2 * A];
  return g_sin[4 * A - 1 - a];
}

s_t s_cos (s_t a)
{
  for (; 4 * A <= a; a -= 4 * A);
  for (; a < 0; a += 4 * A);
  if (a < A)
    return g_sin[A - 1 - a];
  if (a < 2 * A)
    return -g_sin[a - A];
  if (a < 3 * A)
    return -g_sin[3 * A - 1 - a];
  return g_sin[a - 3 * A];
}

*/
