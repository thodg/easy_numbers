#include "easy_numbers.h"

unsigned relative_digits (relative n)
{
  if (n) {
    unsigned digits = 0;
    for (; n ;) {
      n /= 10;
      digits++;
    }
    return digits;
  }
  else
    return 1;
}

unsigned tens_of (unsigned n)
{
  unsigned r = 1;
  for (; n ;) {
    n /= 10;
    r++;
  }
  return r;
}

unsigned tens (unsigned n)
{
  unsigned r = 1;
  for (; n ;) {
    r *= 10;
    n--;
  }
  return r;
}

unsigned relative_to_ascii (char *a, unsigned len, relative z)
{
  unsigned digits = relative_digits(z);
  unsigned n = 0;
  char sign = ' ';
  if (!len)
    return 0;
  if (len < digits + 1) {
    a[0] = 0;
    return 0;
  }
  if (z < 0) {
    sign = '-';
    z = -z;
  }
  a[n++] = sign;
  if (z == 0)
    a[n++] = '0';
  for (; z ;) {
    a[digits + 1 - n++] = (z % 10) + '0';
    z /= 10;
  }
  a[n] = 0;
  return n;
}

unsigned ease_digits (relative ease)
{
  ease = ease & SUP_EASE;
  if (ease) {
    unsigned digits = 0;
    for (; ease ;) {
      ease = ease * 10 % EASY_ONE;
      digits++;
    }
    return digits;
  }
  else
    return 1;
}

unsigned ease_to_ascii (char *a, unsigned len, relative ease)
{
  unsigned ed = min(SUP_EASE_DIGITS, ease_digits(ease));
  unsigned n = 0;
  if (len < ed) {
    a[0] = 0;
    return 0;
  }
  ease = ease & SUP_EASE;
  if (ease)
    for (; ease && d-- > 0 ;) {
      a[n++] = (ease * 10 >> EASE) + '0';
      ease = ease * 10 % EASY_ONE;
    }
  else
    a[n++] = '0';
  a[n++] = 0;
  return n;
}

unsigned easy_to_ascii (char *a, unsigned len, easy e)
{
  relative z = e_relative(e);
  relative ease = e_ease(e);
  unsigned n = relative_to_ascii(a, len, z);
  if (n) {
    if (len < n + 2) {
      a[0] = 0;
      return 0;
    }
    a[n++] = '.';
    unsigned p = ease_to_ascii(a + n, len - n, ease);
    if (!p) {
      a[0] = 0;
      return 0;
    }
    n += p;
  }
  return n;
}
