#include "easy_numbers.h"

const unsigned natural_bits = NATURAL_BITS;
const natural sup_natural = SUP_NATURAL;

const unsigned relative_bits = RELATIVE_BITS;
const relative sup_relative = SUP_RELATIVE;
const relative inf_relative = INF_RELATIVE;

const unsigned easy_bits = EASY_BITS;
const unsigned ease = EASE;
const unsigned sup_ease_digits = SUP_EASE_DIGITS;
const easy easy_one = EASY_ONE;
const easy sup_ease = SUP_EASE;
const easy inf_ease = INF_EASE;
const easy sup_easy = SUP_EASY;
const easy inf_easy = INF_EASY;

const relative sup_easy_relative = SUP_EASY_RELATIVE;
const relative inf_easy_relative = INF_EASY_RELATIVE;

const angle sup_angle = SUP_ANGLE;

relative e_ease (easy e)
{
  return (relative) (e & SUP_EASE);
}

relative e_relative (easy e)
{
  relative z = e >> EASE;
  if (z < 0 && e_ease(e))
    z = z + 1;
  return z;
}

easy e_times (easy a, easy b)
{
  return a * b >> EASE;
}

easy e_by (easy a, easy b)
{
  return a << EASE / b;
}
