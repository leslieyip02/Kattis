#include <stdio.h>
#include <string.h>

int main(void)
{
  char max[1000], required[1000];
  // read input from first 2 lines
  fgets(max, 1000, stdin);
  fgets(required, 1000, stdin);
  // only go if max can fulfill required
  printf("%s", strlen(max) >= strlen(required) ? "go" : "no");

  return 0;
}