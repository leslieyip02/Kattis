#include <stdio.h>
#include <stdlib.h>

size_t buffer_size = 100;

int main(void)
{
    char *ln = malloc(buffer_size * sizeof(char));
    int n = 0;
    int m[buffer_size];

    int c = 0;
    m[c] = getline(&ln, &buffer_size, stdin);
    while (m[c] > 1)
    {
        m[c]--;
        if (m[c] > n)
            n = m[c];
        m[++c] = getline(&ln, &buffer_size, stdin);
    }

    int s = 0;
    for (int i = 0; i < c - 1; i++)
        s += (n - m[i]) * (n - m[i]);
    printf("%i\n", s);

    return 0;
}