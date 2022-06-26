#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *s = malloc(80 * sizeof(char));
    gets(s);

    int n = 0;
    while (*s != '\0')
    {
        switch(*s)
        {
            case 65:
            case 69:
            case 73:
            case 79:
            case 85:
            case 97:
            case 101:
            case 105:
            case 111:
            case 117:
                n++;
                break;
            default:
                break;
        }
        s++;
    }

    printf("%i", n);

    return 0;
}