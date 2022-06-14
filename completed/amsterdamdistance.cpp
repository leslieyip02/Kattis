#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.14159265358979323846;

int main()
{
    int m, n;
    double r;
    cin >> m >> n >> r;

    int a[2], b[2];
    cin >> a[0] >> a[1] >> b[0] >> b[1];

    // try to move towards center along radius before moving along the arc to minimise distance
    double min_distance = 0;
    double inner = min(a[1], b[1]);
    for (int o = 0; o <= inner; o++)
    {
        double distance = 0;
        // distance along arc
        // angle in radians
        double angle = (double) abs(a[0] - b[0]) / m * PI;
        // offset inwards by o
        distance += (inner - o) / n * r * angle;
        
        // distance along radius
        distance += (double) (abs(a[1] - b[1]) + o * 2)/ n * r;
        if (!min_distance) min_distance = distance;
        min_distance = min(min_distance, distance);
    }

    cout << setprecision(10) << min_distance << endl;
    return 0;
}