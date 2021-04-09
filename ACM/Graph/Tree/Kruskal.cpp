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
 
const int N = 2e5 + 1e3;
vt<int> degree(N), p(N), r(N);

int get(int a) {
	if (a == p[a]) return a;
	return p[a] = get(p[a]);
}

void join(int u, int v) {
	u = get(u);
	v = get(v);
	if (r[u] == r[v]) {
		r[u]++;
	}
	if (r[u] > r[v]) {
		p[v] = u;
	} else {
		p[u] = v;
	}
}

struct edge {
	int a, b, c;
	edge (int a, int b, int c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}
};

bool cmp(edge & a, edge & b) {
	return a.c < b.c;
}

void write()
{
	int n, m; cin >> n >> m;
	For(i, n) {
		p[i] = i;
	}
	vt<edge> edges; 
	For(i, m) {
		int u, v, c; cin >> u >> v >> c; u--, v--;
		edges.push_back(edge(u, v, c));
	}
	sort(edges.begin(), edges.end(), cmp);
	ll total_cost = 0;
	for (auto e : edges) {
		if (get(e.a) != get(e.b)) {
			join(e.a, e.b);
			g[e.a].push_back(e.b); 
			g[e.b].push_back(e.a);
			cost[{e.a, e.b}] = cost[{e.b, e.a}] = e.c; 
			total_cost += e.c;
		}
	}
    cout << total_cost << endl;
	
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