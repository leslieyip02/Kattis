#include <stdio.h>

#define MAX 1024

int main()
{
    int b = 0;
    int k = 0;
    int i = 0;
    char buffer[MAX];
    scanf("%s ", buffer);
    while (*(buffer + i) != '\0')
    {
        if (*(buffer + i) == 'b')
        {
            b++;
        }
        else if (*(buffer + i) == 'k')
        {
            k++;
        }
        i++;
    }

    if (b == 0 && k == 0)
    {
        printf("none\n");
    }
    else if (b > k)
    {
        printf("boba\n");
    }
    else if (k > b)
    {
        printf("kiki\n");
    }
    else
    {
        printf("boki\n");
    }
    return 0;
}