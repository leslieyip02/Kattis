#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char* s = malloc(1000000);
    scanf("%s", s);
    
    int l = strlen(s) - 2;
    printf("AWH");
    while (l--)
        printf("O");
    printf("\n");

    free(s);
    return 0;
}

// print("AWH".ljust(1000000,"O"))