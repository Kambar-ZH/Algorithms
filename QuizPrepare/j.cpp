// Problem B. Don’t be scared of magic square
#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define read(x) cin >> x
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define vt vector
#define ll long long
const int MAXN = 1e9;
 
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool write()
{
    int n;
    cin >> n;
    vt<vt<int> > a(n, vt<int> (n));
    For(i, n) {
        For(j, n) {
            cin >> a[i][j];
        }
    }
    int initial_gcd = a[0][0];
    for (int i = 1; i < n; ++i) {
        initial_gcd = gcd(initial_gcd, a[0][i]);
    }   
    for (int i = 1; i < n; i++)
    {
        int local_gcd = a[i][0];
        for (int j = 1; j < n; j++)
        {
            local_gcd = gcd(local_gcd, a[i][j]);
        } 
        if (local_gcd != initial_gcd) {
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int local_gcd = a[0][i];
        for (int j = 1; j < n; j++)
        {
            local_gcd = gcd(local_gcd, a[j][i]);
        } 
        if (local_gcd != initial_gcd) {
            return 0;
        }
    }
    return 1;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    bool result = write();
    if (result) cout << "Yes";
    else cout << "No";
    return 0;
}