#include <stdio.h>
#include <string.h>

int r[] = { 1, 1000, 12, 3, 22, 10, 8, 3 };
char* t[] = { "thou", "th", "inch", "in", "foot", "ft", "yard", "yd", "chain", "ch", "furlong", "fur", "mile", "mi", "league", "lea" };

int main(void)
{
    double v;
    scanf("%lf", &v);

    char u[8];
    int ui1, ui2;
    
    scanf("%s", u);
    for (int i = 0; i < 16; i++)
        if (strcmp(u, t[i]) == 0)
            ui1 = i / 2;

    scanf("%s %s", u, u);
    for (int i = 0; i < 16; i++)
        if (strcmp(u, t[i]) == 0)
            ui2 = i / 2;

    if (ui1 < ui2)
        while (++ui1 <= ui2)
            v /= r[ui1];
    else
        while (ui1 > ui2)
            v *= r[ui1--];

    printf("%0.10lf\n", v);

    return 0;
}