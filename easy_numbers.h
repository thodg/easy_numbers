#ifndef EASY_NUMBERS_H
#define EASY_NUMBERS_H

typedef unsigned long long natural;
#define NATURAL_BITS (sizeof(natural) << 3)
static const unsigned natural_bits = NATURAL_BITS;
#define SUP_NATURAL ((natural) -1)
static const natural sup_natural = SUP_NATURAL;

typedef long long relative;
#define RELATIVE_BITS (sizeof(relative) << 3)
static const unsigned relative_bits = RELATIVE_BITS;
#define SUP_RELATIVE (((natural) 1 << (RELATIVE_BITS - 1)) - 1)
static const relative sup_relative = SUP_RELATIVE;

typedef long long easy;
#define EASY_BITS (sizeof(easy) << 3)
#define SUP_EASY ((easy) 1 << 63)
static const easy sup_easy = SUP_EASY;

#define EASE 15
#define EASY_ONE (1 << EASE)
#define SUP_EASE (EASY_ONE - 1)
#define EASES / easy_one

#define EASY_RELATIVE_BITS (RELATIVE_BITS - EASE)
#define SUP_EASY_RELATIVE ((1 << EASY_RELATIVE_BITS) - 1)

#define EASY_TIMES / EASY_ONE *
#define EASY_BY * EASY_ONE /

typedef unsigned long angle;
#define ANGLE_BITS (sizeof(angle) << 3)
#define SUP_ANGLE ((angle) -1)

easy e_absolute_value (easy e);
easy e_squared (easy e);
easy e_squares (easy e1, easy e2);
easy e_inverse (easy e);
easy e_tangent (angle y);

typedef struct {
  easy x;
  easy y;
} e2;

#define E2(x, y) ((e2){(x),(y)})
easy e2_dot_product (e2 a, e2 b);
e2 e2_add (e2 a, e2 b);
e2 e2_subtract (e2 a, e2 b);

typedef struct {
  easy x;
  easy y;
  easy z;
} e3;

#define E3(x, y, z) ((e3){(x),(y),(z)})
easy e3_dot_product (e3 a, e3 b);
e3 e3_times (e3 a, easy b);
e3 e3_add (e3 a, e3 b);
e3 e3_sub (e3 a, e3 b);
easy e3_along (e3 a, e3 b);

typedef struct
{
  easy xx, yx, zx, dx;
  easy xy, yy, zy, dy;
  easy xz, yz, zz, dz;
} e43;

e43 * e43_identity (e43 *m);
e43 * e43_translate (e43 *m, e3 d);
e43 * e43_scale (e43 *m, e3 s);
e3 e43_e3 (e43 *m, e3 a);

#endif /* EASY_NUMBERS_H */
