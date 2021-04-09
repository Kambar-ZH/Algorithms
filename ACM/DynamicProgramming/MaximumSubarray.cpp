#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define vt vector
#define itn int
const int MAXN = 1e9;
 
// Kadane's algorithm

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    For(i, n) {
        cin >> a[i];
    }
    int ans = INT_MIN, sum = 0;
    For(i, n) {
        sum += a[i];
        ans = max(ans, sum);
        sum = max(sum, 0);
    }
    see(ans);
    return 0;
}