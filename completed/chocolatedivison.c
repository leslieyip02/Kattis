#include <stdio.h>

int main(void)
{
    int r, c;
    scanf("%i %i", &r, &c);
    printf("%s\n", (r * c) % 2 == 0 ? "Alf" : "Beata");

    return 0;
}