#include <bits/stdc++.h>
using namespace std;
 
int ext_euclid (int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = ext_euclid (b%a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    int x, y;
    if (a == 1) {
        cout << 1;
        return 0;
    } else if (a == 0 || b % a == 0) {
        cout << "No solution";
        return 0;
    }
    ext_euclid(a, b, x, y); 
    if (x > 0) {
        cout << x; 
    } else {
        cout << b + x;
    }
    return 0;
}