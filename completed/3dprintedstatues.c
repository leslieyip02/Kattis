#include <stdio.h>

int main(void)
{
  int n;
  scanf("%i", &n);

  int days = 1;
  int numPrinters = 1;
  while (numPrinters < n)
  {
    numPrinters *= 2;
    days++;
  }
  printf("%i", days);

  return 0;
}