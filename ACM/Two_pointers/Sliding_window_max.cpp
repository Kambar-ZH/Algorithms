#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define mp(i, j) make_pair(i, j)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see cout << endl
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
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
 
void write()
{
	int n, q;
	cin >> n >> q;
	vt<int> a(n);
	read(a);
	For(qq, q) {
		int x; cin >> x;
		deque<int> dq;
		For(i, x) {
			while (!dq.empty() && a[dq.back()] <= a[i]) {
				dq.pop_back();
			} 
			dq.push_back(i);
		}
		int mini = a[dq.front()];
		qFor(i, x, n) {
			while (!dq.empty() && i - dq.front() >= x) {
				dq.pop_front();
			} 
			while (!dq.empty() && a[i] >= a[dq.back()]) {
				dq.pop_back();
			} 
			dq.push_back(i);
			mini = min(mini, a[dq.front()]);
		}
		cout << mini << endl;
	}
}
 
// Sample test cases:
// 7 7
// 12 1 78 90 57 89 56
// 1
// 2
// 3
// 4
// 5
// 6
// 7

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifdef DEBUG
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int t;
	t = 1;
	//cin >> t;
	For(T, t) write();
	return 0;
}