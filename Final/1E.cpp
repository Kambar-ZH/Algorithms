#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i) cout << i.first << " " << i.second << endl
#define vt vector
#define ll long long
#define pa pair<ll, ll>
#define ld long double
const ll MAXN = 1e18;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " " ;
    cout << endl;
}
 

const int N = 1e3 + 100;
vt<pa> g[N];

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vt<pair<ll, ll> > coo(n);
    For(i, n) {
        cin >> coo[i].first >> coo[i].second;
    }
    For(i, n) {
        for (int j = 0; j < n; ++j) {
            g[i].push_back({j, abs(coo[j].first - coo[i].first) + abs(coo[j].second - coo[i].second)});
            // cout << i << " " << j << " " << abs(coo[j].first - coo[i].first) + abs(coo[j].second - coo[i].second) << " " << coo[j].first << " " <<  coo[i].first << " " << coo[j].second << " " <<  coo[i].second << endl;
        }
    }
    vt<ll> d(N, MAXN);
    queue<pair<int, ll> > p;
    p.push({0, -1});
    while (!p.empty()) {
        int v = p.front().first;
        ll atleast = p.front().second;
        p.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            int to = g[v][i].first;
            ll cost = g[v][i].second;
            if (d[to] > cost) {
                ll tmp = max(cost, atleast);
                if (atleast == -1) {
                    d[to] = cost;
                    p.push({to, cost});
                } else if (d[to] > tmp) {
                    d[to] = tmp;
                    p.push({to, tmp});
                }
            }
        }
    }
    if (n == 1) {
        cout << 0 << endl; 
        return;
    }
    cout << d[n - 1] << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
} 