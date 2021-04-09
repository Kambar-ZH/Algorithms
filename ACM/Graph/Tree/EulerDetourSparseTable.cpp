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

const int N = 5e5 + 100;
const int L = 20;
int t1 = 0, t2 = 0;
vt<int> tin(N), tout(N);
vt<vt<int> > up(N, vt<int>(L, 0));
vt<vt<int> > g(N);

void find_ancestors(int v) {
	tin[v] = t1++;
	for (int to : g[v]) {
		find_ancestors(to);
	}
	tout[v] = t2++;
}

bool is_ancestor(int p, int c) {
	return tin[p] <= tin[c] && tout[c] <= tout[p];
}

void get_ups(int v, int p) {
	up[v][0] = p;
	for (int i = 1; i < L; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
	}
	for (int to : g[v]) {
		get_ups(to, v);
	}
}

int lca(int u, int v) {
	if (is_ancestor(u, v)) {
		return u;
	}
	if (is_ancestor(v, u)) {
		return v;
	}
	for (int i = L - 1; i >= 0; i--) {
		if (!is_ancestor(up[u][i], v)) {
			u = up[u][i];
		}	
	}
	return up[u][0];
}

void write()
{
	int n; cin >> n;
	vt<pii> queries;
	For(i, n) {
		string op; cin >> op;
		int f, t; cin >> f >> t; f--, t--;
		if (op[0] == 'A') {
			g[f].push_back(t);
		} else {
			queries.push_back({f, t});
		}
	}
	find_ancestors(0);
	get_ups(0, 0);
	for (auto q : queries) {
		cout << lca(q.first, q.second) + 1 << endl;
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("lca.out", "w", stdout);
	freopen("lca.in", "r", stdin);
#endif
	int t;
	t = 1;
	//cin >> t;
	For(T, t) write();
	return 0;
}