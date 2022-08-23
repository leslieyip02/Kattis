#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    char o[10000], d[10000];

    int n;
    scanf("%i", &n);
    scanf("%s", o);
    scanf("%s", d);

    bool ok = true;
    if (n % 2 == 0)
    {
        ok = !strcmp(o, d);
    }
    else
    {
        for (int i = 0; i < strlen(o); i++)
        {
            if (!(int) (o[i] - '0') ^ (int) (d[i] - '0'))
            {
                ok = false;
                break;
            }
        }
    }

    printf("%s\n", ok ? "Deletion succeeded" : "Deletion failed");

    return 0;
}