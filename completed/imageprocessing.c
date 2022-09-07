#include <stdio.h>
#include <string.h>

int main(void)
{
    int h, w, n, m;
    scanf("%i %i %i %i", &h, &w, &n, &m);

    int img[h][w];
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            scanf("%i", &img[i][j]);

    int kernel[n][m];
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            scanf("%i", &kernel[i][j]);

    int p = h - n + 1;
    int q = w - m + 1;
    int processed[p][q];
    memset(processed, 0, p * q * sizeof(int));
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < n; k++)
                for (int l = 0; l < m; l++)
                    processed[i][j] += img[i + k][j + l] * kernel[k][l];

    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
            printf("%i ", processed[i][j]);
        printf("\n");
    }

    return 0;
}