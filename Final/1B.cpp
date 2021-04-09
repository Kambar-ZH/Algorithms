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
#define pa pair<int, int>
#define vt vector
#define ll long long
#define ld long double
const int MAXN = 1e9;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " " ;
    cout << endl;
}
 

const int N = 1e4 + 1e3;
vt<int> dist(N);
vt<int> from(N);

vt<bool> used(N, false);

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n, f;
    cin >> n >> f;
    queue<int> p;
    p.push(n);
    used[n] = true;
    while (!p.empty()) {
        int v = p.front();
        p.pop();
        if (v - 1 >= 0 && !used[v - 1]) {
            p.push(v - 1);
            used[v - 1] = true;
            dist[v - 1] = dist[v] + 1;
            from[v - 1] = v;
        }
        int tmp = 2 * v;
        if (tmp <= N && !used[tmp]) {
            p.push(tmp);
            used[tmp] = true;
            dist[tmp] = dist[v] + 1;
            from[tmp] = v;
        }
    }
    int copy = f;
    cout << dist[f] << endl;
    if (dist[f] == 0) return;
    vt<int> answer;
    while (from[f]) {
        f = from[f];
        answer.push_back(f);
    } 
    for (int i = answer.size() - 2; i >= 0;--i) {
        cout << answer[i] << " ";
    }
    cout << copy << " ";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}