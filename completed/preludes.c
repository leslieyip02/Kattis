#include <stdio.h>
#include <string.h>

int main(void)
{
    int c = 1;
    char note[8];
    char tonality[8];
    while (scanf("%s %s", note, tonality) != EOF)
    {
        printf("Case %i: ", c);
        if (strlen(note) == 1)
        {
            printf("UNIQUE\n");
        }
        else
        {
            int i = (int) note[0] - 65;
            i += note[1] == '#' ? 1 : -1;
            i = (i + 7) % 7 + 65;

            note[0] = (char) i;
            note[1] = note[1] == '#' ? 'b' : '#';

            printf("%s %s\n", note, tonality[1] == 'a' ? "major" : "minor");
        }

        c++;
    }

    return 0;
}