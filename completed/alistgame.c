#include <stdio.h>

int main(void)
{
  int n;
  scanf("%i", &n);

  int k = 1, current = 2, step = 1;
  while (current * current <= n)
  {
    if (n % current == 0)
    {
      n /= current;
      k++;
    }
    else
    {
      current += step;
      if (current == 3) { step++; }
    }
  }
  printf("%i", k);
  return 0;
}