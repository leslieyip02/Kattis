#include <bits/stdc++.h>
using namespace std;

const double E = 0.000001;

int main()
{
    /* 
    
        (aR + bI + cJ + dK) * (xR + yI + zJ + wK) = 

        axR + ayI + azJ + awK +
        bxI - byR + bzK - bwJ +
        cxJ - cyK - czR + cwI +
        dxK + dyJ - dzI - dwR

        (ax - by - cz - dw)R = 1R
        (ay + bx + cw - dz)I = 0I
        (az - bw + cx + dy)J = 0J
        (aw + bz - cy + dx)K = 0K

        a - b - c - d = 1 (1)
        b + a - d + c = 0 (2)
        c + d + a - b = 0 (3)
        d - c + b + a = 0 (4)

    */

    double a, b, c, d, e, f, g, h;
    cin >> a >> b >> c >> d
        >> e >> f >> g >> h;

    double m[4][5] = {
        { e, -f, -g, -h, 1 },
        { f,  e, -h,  g, 0 },
        { g,  h,  e, -f, 0 },
        { h, -g,  f,  e, 0 }
    };

    // use gaussian elimination to find echelon form
    for (int i = 1; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double r = m[i][j] == 0 ? 0 : m[j][j] / m[i][j];

            for (int k = 0; k < 5; k++)
            {
                m[i][k] = m[j][k] - m[i][k] * r;
                m[i][k] = abs(m[i][k]) <= E ? 0 : m[i][k];
            }
        }
    }

    // find potency of each type
    double p[4];
    for (int i = 3; i >= 0; i--)
    {
        p[i] = m[i][4];
        for (int j = 3; j > i; j--)
            p[i] -= p[j] * m[i][j];

        p[i] = m[i][i] == 0 ? 0 : p[i] / m[i][i];
    }

    double R = p[0];
    double I = p[1];
    double J = p[2];
    double K = p[3];

    // cast on to self
    double x = a * R - b * I - c * J - d * K;
    double y = b * R + a * I - d * J + c * K;
    double z = c * R + d * I + a * J - b * K;
    double w = d * R - c * I + b * J + a * K;
    
    cout << (abs(x) <= E ? 0 : x) << ' '
        << (abs(y) <= E ? 0 : y) << ' '
        << (abs(z) <= E ? 0 : z) << ' '
        << (abs(w) <= E ? 0 : w) << '\n';

    return 0;
}