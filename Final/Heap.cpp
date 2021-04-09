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
#define ls ind + ind + 1
#define rs ind + ind + 2
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
 
struct heap {
	vt<int> tree;
	void insert(int v) {
		tree.push_back(v);
		shift_up(tree.size() - 1);
	}
	void shift_up(int ind) {
		if (ind == 0) return;
		int parent = ind / 2;
		if (tree[ind] > tree[parent]) {
			swap(tree[ind], tree[parent]);
			shift_up(parent);
		}
	}
	void delete_top() {
		if (tree.empty()) {
			return;
		}
		swap(tree[0], tree[tree.size() - 1]);
		tree.pop_back();
		shift_down(0);
	}
	void shift_down(int ind) {
		if (ls >= tree.size() && rs >= tree.size()) {
			return;
		}
		if (tree[ind] < tree[ls] && rs >= tree.size()) {
			swap(tree[ind], tree[ls]);
			shift_down(ls);
		} else {
			int maxi = rs;
			if (tree[ls] > tree[rs]) {
				maxi = ls;
			}
			swap(tree[ind], tree[maxi]);
			shift_down(maxi);
		}
	}
	int get_max() {
		if (tree.empty()) {
			return -1;
		}
		return tree[0];
	}
};

void write()
{
#ifdef DEBUG
	freopen("output.txt", "w", stdout);
	freopen("input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	heap kama;
	For(i, n) {
		int op;
		cin >> op;
		if (op == 1) {
			int x;
			cin >> x;
			kama.insert(x);
		} else if (op == 2) {
			kama.delete_top();
		} else {
			cout << kama.get_max() << endl;
		}
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	write();
	return 0;
}