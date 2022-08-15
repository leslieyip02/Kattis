#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    char name1[12];
    char name2[12];
    scanf("%s", name1);
    scanf("%s", name2);
    bool inc = strcmp(name1, name2) < 0;

    for (int i = 2; i < n; i++)
    {
        strcpy(name1, name2);
        scanf("%s", name2);
        if (strcmp(name1, name2) < 0 != inc)
        {
            printf("NEITHER\n");
            return 0;
        }
    }

    printf("%s\n", inc ? "INCREASING" : "DECREASING");
    return 0;
}