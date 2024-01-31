#include <stdio.h>

int main()
{
    int N, ta, da, tb, db;
    scanf("%i %i %i %i %i", &N, &ta, &da, &tb, &db);
    int a = ta * N + da * (N * (N - 1)) / 2;
    int b = tb * N + db * (N * (N - 1)) / 2;
    printf("%s\n", a < b ? "Alice" : a == b ? "=" : "Bob");
    return 0;
}