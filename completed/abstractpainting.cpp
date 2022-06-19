#include <iostream>
using namespace std;

/* 

    POSSIBILITIES:

    for 0 given edges, there are 18 valid states (6 per colour pair):

        > red and blue:
            +-R-+   +-R-+   +-B-+   +-B-+   +-B-+   +-R-+
            R   B   B   B   R   B   B   R   R   R   B   R
            +-B-+   +-R-+   +-R-+   +-R-+   +-B-+   +-B-+

        > green and blue:
            +-G-+   +-G-+   +-B-+   +-B-+   +-B-+   +-G-+
            G   B   B   B   G   B   B   G   G   G   B   G
            +-B-+   +-G-+   +-G-+   +-G-+   +-B-+   +-B-+

        > red and green:
            +-R-+   +-R-+   +-G-+   +-G-+   +-G-+   +-R-+
            R   G   G   G   R   G   G   R   R   R   G   R
            +-G-+   +-R-+   +-R-+   +-R-+   +-G-+   +-G-+

    for 1 given edge, there are 6 valid states:

        > e.g. red on left edge
            +-R-+   +-B-+   +-B-+   +-B-+   +-R-+   +-B-+
            R   B   R   B   R   R   R   G   R   G   R   R 
            +-B-+   +-R-+   +-B-+   +-G-+   +-R-+   +-G-+

    for 2 given edges, there are 2 valid states:

        > e.g. red on left and top edge
            +-R-+   +-R-+
            R   B   R   G
            +-B-+   +-R-+

        > e.g. red on left and blue on top edge
            +-B-+   +-B-+
            R   B   R   R
            +-R-+   +-B-+

*/

int main()
{
    int t, r, c;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> r >> c;

        // start choosing from the top left corner
        long long possibilities = 1;       
        for (int y = 0; y < r; y++)
        {
            for (int x = 0; x < c; x++)
            {
                // 18 ways to choose at (0, 0)
                if (x == 0 && y == 0) 
                    possibilities *= 18;
                // for the top row and left column,
                // there is only 1 restriction (from above or left)
                else if (x == 0 || y == 0)
                    possibilities *= 6;
                // for the rest of the squares,
                // there are 2 restrictions (from above and left)
                else
                    possibilities *= 2;
                // modulo
                possibilities %= 1000000007;
            }
        }
        cout << possibilities << endl;
    }

    return 0;
}