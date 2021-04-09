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
void print(vt<T> & a, int n) {
	For(i, n) cout << a[i] << " " ;
	cout << endl;
}
template<typename T>
void print2(vt<vt<T> > & a) {
	For(i, a.size()) {
		For(j, a[i].size()) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
template<typename T>
void read2(vt<vt<T> > & a) {
	For(i, a.size()) {
		For(j, a[i].size()) {
			cin >> a[i][j];
		}
	}
}


const int N = 1e5 + 10;
vt<vt<int> > g(N);
vt<int> used(N), colors(N), fup(N), tin(N);
int maxColor = 1;
int timer = 1;

void isBridge(int v) {
	//TO-DO
}

void clear(int n) {
	maxColor = timer = 1;
	For(i, n) {
		used[i] = colors[i] = fup[i] = tin[i] = 0;
		g[i].clear();
	}
}

void paint(int v, int color) {
	colors[v] = color;
	for (auto to : g[v]) {
		if (colors[to] != 0) continue;

		if (fup[to] > tin[v]) {
			paint(to, ++maxColor);
		} else {
			paint(to, color);
		}
	}
}

void dfs(int v, int p = -1) {
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for (auto to : g[v]) {
		if (to == p) continue;
		if (used[to]) {
			fup[v] = min(fup[v], tin[to]);
		} else {
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if (fup[to] > tin[v]) {
				isBridge(to);
			}
		}
	}
}
 
void write(int t)
{
	int n, m; cin >> n >> m;

	For(i, m) {
		int f, t;
		cin >> f >> t;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			dfs(i);
		}
	}
	for (int i = 0; i < n; i++) {
		if (!colors[i]) {
			paint(i, maxColor);
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int t;
	t = 1;
	cin >> t;
	For(T, t) write(T);
	return 0;
}