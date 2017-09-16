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
  m->xx = m->xx TIMES s.x;
  m->yy = m->yy TIMES s.y;
  m->zz = m->zz TIMES s.z;
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
  return E3(m->xx TIMES a.x + m->yx TIMES a.y + m->zx TIMES a.z + m->dx,
            m->xy TIMES a.x + m->yy TIMES a.y + m->zy TIMES a.z + m->dy,
            m->xz TIMES a.x + m->yz TIMES a.y + m->zz TIMES a.z + m->dz);
}
