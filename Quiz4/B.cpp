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
const int Ns = 1e3 + 5;
vt<vt<int> > mat(Ns, vt<int> (Ns));
void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    For(i, n) For(j, n) cin >> mat[i][j];
    for (int i = 0; i < m; ++i) {
        int f, s, t;
        cin >> f >> s >> t;
        f--, s--, t--;
        if (mat[f][s] && mat[f][t] && mat[s][t] && mat[s][f] && mat[t][f] && mat[t][s]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}