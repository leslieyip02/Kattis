#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
	
    if (y == 1)
	  {
	      cout << (x == 0 ? "ALL GOOD" : "IMPOSSIBLE") << '\n';
	  }
    else
	  {
	      // using y = mx + c,
		    // A: y = x
		    // B: y = Y * x + X
		    // x = Y * x + X
		    // x = X / (1 - Y)
		    cout << setprecision(10) << (double) x / (1 - y) << '\n';
	  }
	
	  return 0;
}