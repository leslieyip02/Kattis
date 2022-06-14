#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char line[40];

    while (gets(line) != NULL)
    {
        long long int nums[2];
        char *token = strtok(line, " ");
        for (int i = 0; i < 2; i++)
        {
            nums[i] = strtoll(token, NULL, 10);
            token = strtok(NULL, " ");
        }

        long long int diff = (nums[0] > nums[1]) ? nums[0] - nums[1] : nums[1] - nums[0];
        printf("%lld\n", diff);
    }

    return 0;
}