#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define vt vector
#define itn int
const int MAXN = 1e9;

int n;
vt<int> arr;
vt<vt<int> > dp, sell;
 
int maximum_profit(int begin, int end) {
    if (dp[begin][end] != -1) {
        return dp[begin][end];
    }
    int year = n - (end - begin);
    if (begin == end) {
        return year * arr[begin];
    }

    int x = arr[begin] * year + maximum_profit(begin + 1, end);
    int y = arr[end] * year + maximum_profit(begin, end - 1);
    return max(x, y);

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    arr = vt<int> (n);
    dp = sell = vt<vt<int> > (n, vt<int> (n, -1));
    For(i, n) {
        cin >> arr[i];
    }   
    int answer = maximum_profit(0, n - 1);
    cout << answer;
    return 0;
}
// 2 4 6 2 5 |
// 4 6 2 5 | 2 * 1 = 2
// 4 6 2 | 2 * 1 + 5 * 2 = 12
// 4 6 | 2 * 1 + 5 * 2 + 2 * 3 = 18
// 6 | 2 * 1 + 5 * 2 + 2 * 3 + 4 * 4 = 34
// |  2 * 1 + 5 * 2 + 2 * 3 + 4 * 4 + 6 * 5 = 64