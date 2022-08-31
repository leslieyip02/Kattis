#include <iostream>
using namespace std;

int main()
{
    int b, br, bs, a, as;
    cin >> b >> br >> bs >> a >> as;

    int t = (br - b) * bs;
    int i = 1;
    while (i * as <= t)
        i++;
    cout << a + i << endl;
}