#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    size_t l = 100;    
    char* s = (char*) malloc(l * sizeof(char));
    getline(&s, &l, stdin);

    l = 1000;
    char* k = (char*) malloc(l * sizeof(char));
    getline(&k, &l, stdin);

    l = strlen(k) - 1;
    char* id = (char*) malloc(3 * sizeof(char));
    for (int i = 0; i < l; i += 3)
    {
        strncpy(id, k + i, 3);
        printf("%c", *(s + atoi(id) - 1));
    }

    return 0;
}