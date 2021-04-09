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
 
int write()
{
    priority_queue<int, vector<int>, greater<int> > a;
    int n, k;
    cin >> n >> k;
    For(i, n) {
        int x;
        cin >> x;
        a.push(x);
    }
    int i = 0;
    while (!a.empty()) {
        if (a.top() >= k) return i;
        int t = a.top();
        a.pop();
        if (a.empty()) return -1;
        int tt = a.top();
        a.pop();
        if (a.empty()) return -1;
        a.push(t + tt * 2);
        i++;
    }
    return -1;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << write() << endl;
    return 0;
}