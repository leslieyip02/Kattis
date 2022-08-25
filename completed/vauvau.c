#include <stdio.h>

int a, b, c, d;
char r[3][5] = { "none", "one", "both" };

int attacked(int t)
{
    int i = t % (a + b);
    int j = t % (c + d);
    return (i <= a && i != 0 ? 1 : 0) + (j <= c && j != 0 ? 1 : 0);   
}

int main(void)
{
    int p, m, g;
    scanf("%i %i %i %i", &a, &b, &c, &d);
    scanf("%i %i %i", &p, &m, &g);

    printf("%s\n", r[attacked(p)]);
    printf("%s\n", r[attacked(m)]);
    printf("%s\n", r[attacked(g)]);

    return 0;
}