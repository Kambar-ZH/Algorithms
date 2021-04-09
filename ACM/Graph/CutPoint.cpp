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
 
int timer = 0;
set<int> st;

void dfs(int v, int p, vt<vt<int> > & g, vt<int> & in, vt<int> & out, vt<int> & used) {
	used[v] = 1;
	in[v] = out[v] = timer++;
	int childs = 0;
	for (auto u : g[v]) {
		if (u == p) {
			continue;
		}
		if (used[u]) {
			out[v] = min(out[v], in[u]);
		} else {
			dfs(u, v, g, in, out, used);
			out[v] = min(out[v], out[u]);
			if (out[u] >= in[v] && p != -1) {
				st.insert(v);
			}
			childs++;
		}
	}
	if (p == -1 && childs > 1) {
		st.insert(v);
	}
}

void write(int t)
{
	int n, m; cin >> n >> m;
	vt<vt<int> > g(n);
	For(i, m) {
		int f, t;
		cin >> f >> t;
		f--, t--;
		g[f].push_back(t);
		g[t].push_back(f);
	}
	vt<int> in(n), out(n);
	vt<int> used(n);
	For(i, n) {
		if (!used[i]) {
			dfs(i, -1, g, in, out, used);
		}
	}
	cout << "Case " << t + 1 << ": " << st.size() << endl;
	timer = 0;
	st.clear();
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