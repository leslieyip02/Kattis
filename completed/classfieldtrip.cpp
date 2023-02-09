#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    char* a = (char*) malloc(100 * sizeof(char));
    char* b = (char*) malloc(100 * sizeof(char));

    scanf("%s", a);
    scanf("%s", b);

    while (*a != '\0' && *b != '\0')
    {
        if (*a < *b)
        {
            printf("%c", *a);
            a++;
        } 
        else
        {
            printf("%c", *b);
            b++;
        }
    }

    if (*a != '\0')
    {
        printf("%s", a);
    }
    else if (*b != '\0')
    {
        printf("%s", b);
    }

    return 0;
}