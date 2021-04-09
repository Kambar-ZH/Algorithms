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
vt<vt<int> > dst(Ns, vt<int> (Ns));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n, m;

bool inside (int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int maxi = 0;
void bfs() {
    queue<pair<int, int> > p;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 2) {
                p.push({i, j});
            }
        }
    }
    while (!p.empty()) {
        pair<int, int> v = p.front();
        int mx = v.first;
        int my = v.second;
        mat[mx][my] = 2;
        p.pop();
        for (int i = 0; i < 4; ++i) {
            int tx = mx + dx[i], ty = my + dy[i];
            if (inside(tx, ty) && mat[tx][ty] == 1) {
                p.push({tx, ty});
                dst[tx][ty] = dst[mx][my] + 1;
                mat[tx][ty] = 2;
                maxi = max(maxi, dst[tx][ty]);
            }
        }
    }
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    cin >> n >> m;
    For(i, n) For(j, m) cin >> mat[i][j];

    bfs();

    For(i, n) For(j, m) {
        if (mat[i][j] == 1) {
            cout << -1 << endl;
            return;
        } 
    }
    cout << maxi << endl;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}