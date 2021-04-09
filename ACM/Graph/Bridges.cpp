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
 
const int MAXN = 20000;
int n, m, counter, timer, tin[MAXN], fup[MAXN];
vector<int> graph[MAXN];
vector<int> used;
set<pii> member;

void dfs(int v, int p = -1)
{
    used[v] = true;
    tin[v] = fup[v] = timer++;
    for (int i = 0; i < graph[v].size(); i++)
    {
        int to = graph[v][i];
        if (to == p) continue;
        if (used[to]) fup[v] = min(fup[v], tin[to]);
        else
        {
            dfs(to, v);
            fup[v] = min(fup[v], fup[to]);
            if (fup[to] > tin[v])
            {   
				if (v > to) {
					member.insert(make_pair(to, v));
				} else {
					member.insert(make_pair(v, to));
				}
				counter+=1;
            }
        }   
    }
}

void find_bridges() {
    for (int i = 0; i < n; i++) {
        if (!used[i]) dfs(i);

	}
}

void write(int t)
{
	cin >> n;
    used.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        int from;
		cin >> from;
		string s; cin >> s;
		int m = atoi(s.substr(1, s.length() - 2).c_str());
		for (int j = 0; j < m; j++) {
			int to;
			cin >> to;
			graph[from].push_back(to);
			graph[to].push_back(from);
		}
    }
    find_bridges();
	cout << "Case " << t + 1 <<  ":" << endl; 
    cout << member.size() << " " << "critical links" << endl;
    for (auto mem : member)
    {
			cout << mem.first << " - " << mem.second << endl;
    }
	for (int i = 0; i < n; i++) {
		graph[i].clear();
		tin[i] = fup[i] = used[i] = 0;
	}
	timer = 0;
	member.clear();
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