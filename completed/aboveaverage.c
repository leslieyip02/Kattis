#include <stdio.h>

int main(void)
{
  int c;
  scanf("%i", &c);

  for (int i = 0; i < c; i++)
  {
    int n;
    scanf("%i", &n);
    int scores[n];
    int sum = 0;
    for (int j = 0; j < n; j++)
    {
      scanf("%i", &scores[j]);
      sum += scores[j];
    }
    float avg = (float) sum / n;
    int count = 0;
    for (int k = 0; k < n; k++)
    {
      if (scores[k] > avg)
      {
        count++;
      }
    }
    float above = (float) count / n * 100;
    printf("%.3f\%\n", above);
  }
  return 0;
}