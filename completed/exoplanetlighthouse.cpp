#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int t;
    scanf("%i", &t);
    while (t--)
    {
        double R, h1, h2;
        scanf("%lf %lf %lf", &R, &h1, &h2);
        h1 /= 1000;
        h2 /= 1000;

        double a = acos(R / (R + h1)) + acos(R / (R + h2));
        printf("%lf\n", R * a);
    }

    return 0;
}