#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int n, q, i;
    scanf("%i", &n);
    scanf("%i", &q);

    // store latest modified value and which iteration it was changed
    int ppl[n][2];
    for (int k = 0; k < n; k++)
    {
        // -1 means
        ppl[k][0] = 0;
        ppl[k][1] = -1;
    }

    // base case (updates when restart)
    int restarted[2] = { 0, -1 };

    for (int k = 0; k < q; k++)
    {
        char *evt = malloc(6 * sizeof(char));
        scanf("%s", evt);
        if (strcmp(evt, "SET") == 0)
        {
            scanf("%i", &i);
            scanf("%i", &ppl[i - 1][0]);
            ppl[i - 1][1] = k;
        }
        else if (strcmp(evt, "RESTART") == 0)
        {
            scanf("%i", &restarted[0]);
            restarted[1] = k;
        }
        else 
        {
            scanf("%i", &i);

            // if value at index is not equal to current base value,
            // then see which one is more recent
            printf("%i\n", (ppl[i - 1][1] > restarted[1] ? ppl[i - 1][0] : restarted[0]));
        }
        
        free(evt);
    }

    
    return 0;
}