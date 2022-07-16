#include <stdio.h>

int main(void)
{
    int n;
    scanf("%i", &n);

    int nums[n];
    for (int i = 0; i < n; i++)
        scanf("%i\n", &nums[i]);

    for (int i = n - 1; i >= 0; i--)
        printf("%i\n", nums[i]);

    return 0;
}