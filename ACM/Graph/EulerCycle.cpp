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
 
const int N = 1e5 + 10;
const int M = 4e5 + 10;
vt<int> path;
vt<unordered_map<int, bool> > g(N);

void remove(int v, int u) {
	g[v].erase(u);
	g[u].erase(v);
}

void dfs(int v) {
	while (g[v].size()) {
		int to = g[v].begin()->first;
		remove(v, to);
		dfs(to);
	}
	path.push_back(v);
}

void write()
{
	int n, m; cin >> n >> m;
	vt<int> degree(n);
	For(i, m) {
		int f, t; cin >> f >> t; f--, t--;
		if (f == t) continue;
		degree[f]++;
		degree[t]++;
		g[f][t] = true;
		g[t][f] = true;
	} 
	bool bad = false;
	For(i, n) {
		if (degree[i] % 2 != 0) {
			bad = true;
			break;
		}
	}
	dfs(0);
	For(i, n) {
		if (g[i].size() > 0) {
			bad = true;
			break;
		}
	}
	if (bad) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	For(i, path.size()) {
		cout << path[i] + 1 << " ";
	}
	see;
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