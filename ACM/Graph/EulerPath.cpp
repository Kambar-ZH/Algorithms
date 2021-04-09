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
void print(vt<T> & a) {
	For(i, a.size()) cout << a[i] << " " ;
	cout << endl;
}

const int N = 1e5 + 10;
const int M = 4e5 + 10;
vt<int> euler_cycle;
vt<unordered_set<int> > g(N);
vt<bool> visited(N);

void remove(int v, int u) {
	g[v].erase(u);
}
 
void dfs(int v) {
	visited[v] = true;
	while (g[v].size()) {
		int to = *g[v].begin();
		remove(v, to);
		dfs(to);
	}
	euler_cycle.push_back(v);
}
 
void write()
{
	int n, m; cin >> n >> m;
	vt<int> in_degree(n);
    vt<int> out_degree(n);
	For(i, m) {
		int f, t; cin >> f >> t; f--, t--;
		if (f == t) continue;
		out_degree[f]++;
		in_degree[t]++;
		g[f].insert(t);
	} 
    int v1 = -1;
    int v2 = -1;
	bool bad = false;
	For(i, n) {
		if (out_degree[i] != in_degree[i]) {
            if (v1 == -1) {
                v1 = i;
            } else if (v2 == -1) {
                v2 = i;
            } else {
                bad = true;
                break;
            }
		}
	}
	if (v1 == -1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	int from = -1;
	int to = -1;
    // add new edge bettwen v1 and v2
    {
        if (in_degree[v1] > out_degree[v1]) {
            g[v1].insert(v2);
			from = v1, to = v2;
        } else {
            g[v2].insert(v1);
			from = v2, to = v1;
		}
    }
	dfs(0);
	For(i, n) {
		if (abs(in_degree[i] - out_degree[i]) > 1 || (!visited[i] && (in_degree[i] > 0 || out_degree[i] > 0))) {
			bad = true;
			break;
		}
	}
	if ((in_degree[0] == 0 && out_degree[0] == 0) || (in_degree[n - 1] == 0 && out_degree[n - 1] == 0)) {
		bad = true;
	}
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
	vt<int> euler_path;
	reverse(all(euler_cycle));
    For(i, euler_cycle.size() - 1) {
        if (euler_cycle[i] == from && euler_cycle[i + 1] == to) {
            for (int j = i + 1; j < euler_cycle.size() - 1; ++j) {
                euler_path.push_back(euler_cycle[j]);
            }
            for (int j = 0; j <= i; ++j) {
                euler_path.push_back(euler_cycle[j]);
            }
			break;
        }
    }
	For(i, euler_path.size()) {
		cout << euler_path[i] + 1 << " ";
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