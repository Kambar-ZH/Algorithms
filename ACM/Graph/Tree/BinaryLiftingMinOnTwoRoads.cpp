#include <bits/stdc++.h>
using namespace std;

#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)
#define qFor(i, x, n)       for(int i = x; i < n; ++i)
#define rFor(i, n)          for(int i = n - 1; i >= 0; --i)
#define see                 cout << endl
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define pii                 pair<int, int>
#define vt                  vector
#define ll                  long long
#define ld                  long double
 
const int MAX = 1e9;
const int MOD = 1e9 + 7;
const ll  INF = 1e18;
const ld  PI  = 3.14159265358979323846;
 
template<typename T>
void read(vt<T> & a) {
	For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
	For(i, a.size()) cout << a[i] << " " ;
	cout << endl;
}
template<typename T>
void print2(vt<vt<T> > & a) {
	For(i, a.size()) {
		For(j, a[i].size()) cout << a[i][j] << " ";
		cout << endl;
	}
}
template<typename T>
void read2(vt<vt<T> > & a) {
	For(i, a.size()) For(j, a[i].size()) cin >> a[i][j];
}

const int N = 3e5 + 10;
const int LOG = 20;
vt<vt<int> > g(N);
map<pii, int> cost;
vt<vt<int> > up(N, vt<int> (LOG));
vt<vt<int> > mn(N, vt<int> (LOG, MAX));
vt<int> tin(N), tout(N);
vt<int> depth(N);
int t1 = 0, t2 = 0;
 
void dfs(int v, int p, int d) {
	depth[v] = d;
	tin[v] = ++t1;
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v, d + 1);
		}
	}
	tout[v] = ++t2;
}
 
void get_ups(int v, int p) {
	up[v][0] = p;
	if (cost[{p, v}] != 0)
		mn[v][0] = cost[{p, v}];
	for (int i = 1; i < LOG; ++i) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mn[v][i] = min(mn[up[v][i - 1]][i - 1], mn[v][i - 1]);
	}
	for (int to : g[v]) {
		if (to == p) continue;
		get_ups(to, v);
	}
}
 
bool is_ancestor(int v, int u) {
	return tin[v] < tin[u] && tout[u] < tout[v];
}
 
int lca(int v, int u) {
	if (is_ancestor(v, u)) {
		return v;
	}
	if (is_ancestor(u, v)) {
		return u;
	}
	for (int i = LOG - 1; i >= 0; --i) {
		if (!is_ancestor(up[u][i], v)) {
			u = up[u][i];
		}
	}
	return up[u][0];
}

int get_min(int v, int p) {
	int res = MAX;
	for (int i = LOG - 1; i >= 0; --i) {
		if (p - pow(2, i) >= 0) {
			res = min(res, mn[v][i]);
			v = up[v][i];
			p -= pow(2, i);
		}
	}
	return res;
}

void write()
{
	int n, m; cin >> n >> m; 
	For(i, m) {
		int f, t, c; cin >> f >> t >> c; f--, t--;
		g[f].push_back(t); 
		g[t].push_back(f);
		cost[{f, t}] = cost[{t, f}] = c; 
	}
	dfs(0, -1, 0);
	get_ups(0, 0);
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int f, t; cin >> f >> t; f--, t--;
		int parent = lca(f, t);
		int d_f = (depth[f] - depth[parent]);
		int d_t = (depth[t] - depth[parent]);
		cout << min(get_min(f, d_f), get_min(t, d_t)) << endl;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int T;
	T = 1;
	//cin >> T;
	For(t, T) write();
	return 0;
}