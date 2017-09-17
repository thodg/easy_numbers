#include "easy_numbers.h"
#include "easy_notation.h"

e43 * e43_identity (e43 *m)
{
  m->xx = ONE; m->yx = 0; m->zx = 0; m->dx = 0;
  m->xy = 0; m->yy = ONE; m->zy = 0; m->dy = 0;
  m->xz = 0; m->yz = 0; m->zz = ONE; m->dz = 0;
  return m;
}

e43 * e43_translate (e43 *m, e3 d)
{
  m->dx += d.x;
  m->dy += d.y;
  m->dz += d.z;
  return m;
}

e43 * e43_scale (e43 *m, e3 s)
{
  m->xx = e_times(m->xx, s.x);
  m->yy = e_times(m->yy, s.y);
  m->zz = e_times(m->zz, s.z);
  return m;
}

/*
void e43_rotate (e43 *m, e3 a, s_t b)
{
  (void) a;
  m->n[0] = m->n[0] TIMES  e_cosinus(b);
  m->n[1] = m->n[5] TIMES -e_sinus(b);
  m->n[4] = m->n[0] TIMES  e_sinus(b);
  m->n[5] = m->n[5] TIMES  e_cosinus(b);
}
*/

e3 e43_e3 (e43 *m, e3 a)
{
  return E3(e_times(m->xx, a.x) + e_times(m->yx, a.y) + e_times(m->zx, a.z) + m->dx,
            e_times(m->xy, a.x) + e_times(m->yy, a.y) + e_times(m->zy, a.z) + m->dy,
            e_times(m->xz, a.x) + e_times(m->yz, a.y) + e_times(m->zz, a.z) + m->dz);
}
