#include <stdio.h>
#include <stdlib.h>

int c[27] = { 0 };
size_t n = 1001;

int main(void)
{
    char *s = malloc(n * sizeof(char));
    char *t = malloc(n * sizeof(char));
  
    getline(&s, &n, stdin);
    getline(&t, &n, stdin);
    
    int i, j, x, y;
    for (i = 0, j = 0; s[i] != '\n' && t[j] != '\n'; i += x, j += y)
    {
        x = 1; 
        while (s[i + x] != '\n' && s[i + x] == s[i])
            x++;
            
        y = 1;
        while (t[j + y] != '\n' && t[j + y] == s[i])
            y++;
            
        if (y > x)
        {
            if (s[i] == ' ')
                c[26] = 1;
            else
                c[(int) s[i] - 97] = 1;
        }
    }
    
    for (i = 0; i < 26; i++)
        if (c[i])
            printf("%c", i + 97);
    puts(c[26] ? " " : "");

    return 0;
}