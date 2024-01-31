#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
    char* buffer = malloc(MAX * sizeof(char));
    char* start = buffer;
    scanf("%s", buffer);
    int v = 0;
    int y = 0;
    while (*buffer != '\0')
    {
        switch (*buffer)
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                v++;
                break;
            case 'y':
                y++;
                break;
        }
        buffer++;
    }
    printf("%i %i\n", v, v + y);
    free(start);
    return 0;
}