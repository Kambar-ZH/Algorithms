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
 
void write()
{
#ifdef DEBUG
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vt<string> t(n);
	For(i, n) cin >> t[i];
	set<string> ss;
	bool check = false;
	For(i, n) {
		string s = t[i];
		if (!check) {
			For(j, s.length()) {
				string tmp = s.substr(j, int(s.length() - j)).c_str();
				if (ss.find(tmp) != ss.end()) {
					check = true;
				}
			}
			ss.insert(s);
		}
	}
	if (check)
		cout << "NO" << endl;
	else 
		cout << "YES" << endl;
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	For(t, T) write();
	return 0;
}