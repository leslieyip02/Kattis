#include <stdio.h>

int main(void)
{
    char n[2];
    scanf("%c", &n[0]);
    scanf("%c", &n[1]);
    printf("%c%c", n[1], n[0]);
    return 0;
}