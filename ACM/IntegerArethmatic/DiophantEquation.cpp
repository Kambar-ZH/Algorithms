#include <bits/stdc++.h>
using namespace std;
 
int euclid(int a, int b, int c, int & x, int & y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int x1, y1;
    int gcd = euclid(b, a % b, c, x1, y1);
    x = y1;
    y = x1 - a / b * y1;
    return gcd;
}

bool find(int a, int b, int c, int & gcd, int & x, int & y) {
    gcd = euclid(a, b, c, x, y);
    if (c % gcd != 0) {
        return 0;
    }
    x *= c / gcd;
    y *= c / gcd;
    if (a < 0) x *= - 1;
    if (b < 0) y *= - 1;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    int a, b, c;
    int gcd, x, y;
    cin >> a >> b >> c;
    if (find(a, b, c, gcd, x, y)) {
        cout << gcd << " " << x << " " << y;
    } else {
        cout << "Impossible";
    }
    return 0;
}