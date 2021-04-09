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

const int N = 1e5 + 100;
vt<bool> used(N, false);
vt<int> g[N];
const int NN = 1e3 + 10;
vt<int> d(N, 0);
int mat[NN][NN];

int n;
void read_list() {
    cin >> n;
    For(i, n) {
        int f, t;
        cin >> f >> t;
        g[f].push_back(t);
        g[t].push_back(f);
    }
}

void read_mat() {
    cin >> n;
    For(i, n) {
        For(j, n) {
            cin >> mat[i][j];
        }
    }
}

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
int dx8[8] = {2, -2, 1, -1, 2, -2, 1, -1};
int dy8[8] = {-1, -1, -2, -2, 1, 1, 2, 2};

void bfs() {
    queue<int> p;
    p.push();
    while (!p.empty()) {
        v = p.front();
        p.pop();
        for () {
            if (!used[]) {
                p.push();
                used[] = true;
            }
        }
    }
}

void dfs(int v) {
    used[v] = true;
    for (auto to : g[v]) {
        if (!used[to]) {
            used[to] = true;
            dfs(to);
        }
    }
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}