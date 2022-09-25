#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
    int n, i;
    scanf("%i", &n);

    size_t m = 1001;
    char* ln = malloc(m * sizeof(char));
    char* ss = "simon says";
    getline(&ln, &m, stdin);
    
    bool found;
    while (n--)
    {
        getline(&ln, &m, stdin);

        found = true;
        for (i = 0; i < 10; i++)
        {
            if (*(ln + i) != *(ss + i))
            {
                found = false;
                break;
            }
        }
        
        if (found)
            for (i++; i < strlen(ln); i++)
                printf("%c", *(ln+ i));
        
        printf("\n");
    }

    return 0;
}