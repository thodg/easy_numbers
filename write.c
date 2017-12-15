#include "easy_numbers.h"

unsigned natural_digits (natural n)
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

unsigned natural_to_ascii (char *a, unsigned len, natural n)
{
  unsigned digits = natural_digits(n);
  unsigned i = 0;
  if (!len)
    return 0;
  if (len < digits + 1) {
    a[0] = 0;
    return 0;
  }
  if (n == 0)
    a[i++] = '0';
  for (; n ;) {
    a[digits - ++i] = (n % 10) + '0';
    n /= 10;
  }
  a[i] = 0;
  return i;
}

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

unsigned relative_to_ascii (char *a, unsigned len, relative z)
{
  unsigned digits = relative_digits(z);
  unsigned i = 0;
  char sign = ' ';
  if (!len)
    return 0;
  if (len < digits + 2) {
    a[0] = 0;
    return 0;
  }
  if (z < 0) {
    sign = '-';
    z = -z;
  }
  a[i++] = sign;
  if (z == 0)
    a[i++] = '0';
  for (; z ;) {
    a[digits + 1 - i++] = (z % 10) + '0';
    z /= 10;
  }
  a[i] = 0;
  return i;
}

unsigned ease_digits (relative ease)
{
  ease = ease & SUP_EASE;
  if (ease) {
    unsigned digits = 0;
    for (; ease && digits < SUP_EASE_DIGITS ;) {
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
  unsigned ed = ease_digits(ease);
  unsigned n = 0;
  if (len < ed) {
    a[0] = 0;
    return 0;
  }
  ease = ease & SUP_EASE;
  if (ease)
    for (; ease && ed-- > 0 ;) {
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
  unsigned i = 0;
  char sign = ' ';
  if (e < 0) {
    sign = '-';
    z = -z;
  }
  a[i++] = sign;
  i += natural_to_ascii(a + i, len - i, z);
  if (i > 1) {
    if (len < i + 2) {
      a[0] = 0;
      return 0;
    }
    a[i++] = '.';
    unsigned p = ease_to_ascii(a + i, len - i, ease);
    if (!p) {
      a[0] = 0;
      return 0;
    }
    i += p;
  }
  return i;
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
