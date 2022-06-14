#include <stdio.h>

int main(void)
{
  int cba[3] = { 0 };
  for (int i = 0; i < 3; i++)
  {
    int x;
    scanf("%i", &x);

    for (int j = 0; j < 3; j++)
    {
      if (x > cba[j])
      {
        for (int k = 2 - j; k > 0; k--)
        {
          cba[j + k] = cba[j + k - 1];
        }
        cba[j] = x;
        break;
      }
    }
  }

  char order[3];
  scanf("%s", order);
  
  int output[3];
  for (int i = 0; i < 3; i++)
  {
    switch(order[i])
    {
      case 'C':
        output[i] = cba[0];
        break;
      case 'B':
        output[i] = cba[1];
        break;
      default:
        output[i] = cba[2];
        break;
    }
  }
  
  for (int i = 0; i < 3; i++)
  {
    printf("%i ", output[i]);
  }
}