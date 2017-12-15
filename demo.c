#include <stdlib.h>
#include <stdio.h>
#include "easy_numbers.h"

void e_print (easy e)
{
  char a[128];
  easy_to_ascii(a, sizeof(a), e);
  a[sizeof(a) - 1] = 0;
  printf("%s", a);
}

void demo_write ()
{
  printf("\n__ Write _____________________________\n");
  printf("\nNATURAL_BITS = %u", NATURAL_BITS);
  printf("\nnatural_bits = %u", natural_bits);
  printf("\nSUP_NATURAL = %llu", SUP_NATURAL);
  printf("\nsup_natural = %llu", sup_natural);
  printf("\n");
  printf("\nRELATIVE_BITS = %u", RELATIVE_BITS);
  printf("\nrelative_bits = %u", relative_bits);
  printf("\nSUP_RELATIVE = % lli", SUP_RELATIVE);
  printf("\nsup_relative = % lli", sup_relative);
  printf("\nINF_RELATIVE = % lli", INF_RELATIVE);
  printf("\ninf_relative = % lli", inf_relative);
  printf("\n");
  printf("\nEASY_BITS = %u", EASY_BITS);
  printf("\neasy_bits = %u", easy_bits);
  printf("\nEASE = %u", EASE);
  printf("\nease = %u", ease);
  printf("\nEASY_ONE = "); e_print(EASY_ONE);
  printf("\neasy_one = "); e_print(easy_one);
  printf("\nSUP_EASE = "); e_print(SUP_EASE);
  printf("\nsup_ease = "); e_print(sup_ease);
  printf("\nINF_EASE = "); e_print(INF_EASE);
  printf("\ninf_ease = "); e_print(inf_ease);
  printf("\nSUP_EASY = "); e_print(SUP_EASY);
  printf("\nsup_easy = "); e_print(sup_easy);
  printf("\nINF_EASY = "); e_print(INF_EASY);
  printf("\ninf_easy = "); e_print(inf_easy);
  printf("\nSUP_EASY_RELATIVE = % lli", SUP_EASY_RELATIVE);
  printf("\nsup_easy_relative = % lli", sup_easy_relative);
  printf("\nINF_EASY_RELATIVE = % lli", INF_EASY_RELATIVE);
  printf("\ninf_easy_relative = % lli", inf_easy_relative);
  printf("\n-EASY_ONE / 2 = "); e_print(-EASY_ONE / 2);
  printf("\n-EASY_ONE / 3 = "); e_print(-EASY_ONE / 3);
  printf("\n-EASY_ONE / 4 = "); e_print(-EASY_ONE / 4);
  printf("\n-EASY_ONE / 5 = "); e_print(-EASY_ONE / 5);
  printf("\n-EASY_ONE / 6 = "); e_print(-EASY_ONE / 6);
  printf("\n-EASY_ONE / 7 = "); e_print(-EASY_ONE / 7);
  printf("\n-EASY_ONE / 8 = "); e_print(-EASY_ONE / 8);
  printf("\n-EASY_ONE / 9 = "); e_print(-EASY_ONE / 9);
  printf("\n-EASY_ONE / 10 = "); e_print(-EASY_ONE / 10);
  printf("\n-100 * EASY_ONE / 2 = "); e_print(-100 * EASY_ONE / 2);
  printf("\n-100 * EASY_ONE / 3 = "); e_print(-100 * EASY_ONE / 3);
  printf("\n-100 * EASY_ONE / 4 = "); e_print(-100 * EASY_ONE / 4);
  printf("\n-100 * EASY_ONE / 5 = "); e_print(-100 * EASY_ONE / 5);
  printf("\n-100 * EASY_ONE / 6 = "); e_print(-100 * EASY_ONE / 6);
  printf("\n-100 * EASY_ONE / 7 = "); e_print(-100 * EASY_ONE / 7);
  printf("\n-100 * EASY_ONE / 8 = "); e_print(-100 * EASY_ONE / 8);
  printf("\n-100 * EASY_ONE / 9 = "); e_print(-100 * EASY_ONE / 9);
  printf("\n-100 * EASY_ONE / 10 = "); e_print(-100 * EASY_ONE / 10);
  printf("\n");
}

void demo_ease ()
{
  printf("\n__ Ease _____________________________\n");
  printf("\n% lli", e_ease(EASY_ONE));
  printf("\n% lli", e_ease(SUP_EASY));
  printf("\n% lli", e_ease(INF_EASY));
  printf("\n% lli", e_ease(EASY_ONE * 2));
  printf("\n% lli", e_ease(EASY_ONE / 2));
  printf("\n% lli", e_ease(7 * EASY_ONE / 2));
  printf("\n% lli", e_ease(-7 * EASY_ONE / 2));
  printf("\n% lli", e_ease(INF_EASY));
  printf("\n");
}

void print_demo_times (easy a, easy b)
{
  easy c = e_times(a, b);
  printf("\n");
  e_print(a);
  printf(" × ");
  e_print(b);
  printf(" = ");
  e_print(c);
}

void demo_times ()
{
  printf("\n__ Times _____________________________\n");
  print_demo_times(0, 0);
  print_demo_times(0, EASY_ONE);
  print_demo_times( EASY_ONE,  0);
  print_demo_times( EASY_ONE,  EASY_ONE);
  print_demo_times( EASY_ONE,  EASY_ONE * 2);
  print_demo_times( EASY_ONE * 2,  EASY_ONE);
  print_demo_times( EASY_ONE * 2,  EASY_ONE * 3);
  print_demo_times( EASY_ONE * 3,  EASY_ONE * 2);
  print_demo_times(-EASY_ONE,  EASY_ONE);
  print_demo_times( EASY_ONE, -EASY_ONE);
  print_demo_times(-EASY_ONE, -EASY_ONE);
  print_demo_times(-EASY_ONE * 2,  EASY_ONE);
  print_demo_times( EASY_ONE * 2, -EASY_ONE * 3);
  print_demo_times(-EASY_ONE * 3,  EASY_ONE * 2);
  print_demo_times( EASY_ONE / 2,  EASY_ONE / 2);
  print_demo_times( EASY_ONE / 3,  EASY_ONE / 2);
  print_demo_times( 100 * EASY_ONE / 2,  EASY_ONE / 3);
  print_demo_times(-EASY_ONE / 2,  EASY_ONE);
  print_demo_times(-100 * EASY_ONE / 2, EASY_ONE / 2);
  print_demo_times(-100 * EASY_ONE / 3, EASY_ONE / 2);
  print_demo_times(-EASY_ONE / 2, EASY_ONE / 2);
  printf("\n");
}

int main (int argc, char *argv[])
{
  (void) argc;
  (void) argv;
  demo_ease();
  demo_write();
  demo_times();
  return 0;
}
