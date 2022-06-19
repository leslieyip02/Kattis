#include <stdio.h>

int main(void)
{
    char name[250];
    gets(name);

    // store previous printed letter
    char prev = '0';
    for (int i = 0; name[i] != '\0'; i++)
    {        
        if (name[i] != prev)
        {
            printf("%c", name[i]);
            prev = name[i];
        }
    }

    return 0;
}