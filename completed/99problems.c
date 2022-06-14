#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numDigits(int x);
int main(void)
{
    int n;
    scanf("%i", &n);

    // return 99 if n is 2 digits or less
    if (n < 149) 
    {
        printf("%i", 99);
        return 0;
    }

    int d = numDigits(n);
    char nStr[d];
    sprintf(nStr, "%i", n);

    // read last 2 digits of n
    char lastDigits[2];
    *lastDigits = *(nStr + d - 2);
    *(lastDigits + 1) = *(nStr + d - 1);
    *(lastDigits + 2) = '\0';

    char output[d];
    int x = 0;

    // go up if last digits >= 49
    if (atoi(lastDigits) >= 49)
    {
        for (int i = 0; i < d - 2; i++)
        {
            *(output + i) = *(nStr + i);
            x++;
        }
    }
    // go down if last 2 digits < 49
    else
    {
        int i = 0;
        char frtDigits[d - 2];
        while (i < d - 2)
        {
            *(frtDigits + i) = *(nStr + i);
            i++;
        }
        *(frtDigits + i) = '\0';

        int frtNum = atoi(frtDigits) - 1;
        sprintf(frtDigits, "%i", frtNum);

        for (int j = 0; j < d - 2; j++)
        {
            if (frtDigits[j] != 0) {
                *(output + j) = *(frtDigits + j);
                x++;
            }
        }
    }

    // set end to '99'
    *(output + x) = '9';
    *(output + x + 1) = '9';
    *(output + x + 2) = '\0';
    printf("%s", output);

    return 0;
}

int numDigits(int x)
{
    int digits = 0;
    do
    {
    x /= 10;
    digits++;
    }
    while (x != 0);
    return digits;
}

