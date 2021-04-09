#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define read(x) cin >> x
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define vt vector
#define ll long long
const int MAXN = 1e9;
 
struct heap {
	int limit;
	vt<int> tree;
	heap(int limit) {
		this->limit = limit + 1;
		tree.push_back(0);
	}

	void insert(int value) {
		if (size() == limit) {
			error(-1);
			return;
		}
		tree.push_back(value);
		int res = shift_up(size() - 1);
	}

	int shift_up(int index) {
		if (index == 1) {
			return index;
		}
		if (tree[index] > tree[index / 2]) {
			swap(tree[index], tree[index / 2]);
			return shift_up(index / 2);
		}
		return index;
	}

	int shift_down(int index) {
		if (index * 2 >= (int)size()) {
			return index;
		}
		int tmp = index;
		if (tree[tmp] < tree[index * 2]) {
			tmp = index * 2;
		} 
		if (index * 2 + 1 < size() && tree[tmp] < tree[index * 2 + 1]) {
			tmp = index * 2 + 1;
		}
		if (tmp != index) {
			swap(tree[tmp], tree[index]);
			return shift_down(tmp);
		} 
		return index;
	}

	int extract_maximum() {
		int maximum = tree[1];
		swap(tree[1], tree[size() - 1]);
		tree.pop_back();
		int result = shift_down(1);
		return maximum;
	}

	void deletion(int index) {
		if (index < 1 || size() == 1 || index >= size()) {
			error(-1);
			return;
		}
		see(tree[index]);
		swap(tree[index], tree[size() - 1]);
		tree.pop_back();
		shift_down(index);
	}

	void increase(int index, int value) {
		tree[index] += value;
		int result = shift_up(index);
		see(result);
	}

	void decrease(int index, int value) {
		tree[index] -= value;
		int result = shift_down(index);
		see(result);
	}

	void print() {
		qFor(i, 1, (int)size()) {
			look(tree[i]);
		}
		see("");
	}

	int size() {
		return tree.size();
	}

	void error(int order) {
		see(order);
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
	heap hp(n);
	For(i, n) {
		int x;
		cin >> x;
		hp.insert(x);
	}
	vt<int> answer;
	For(z, n) {
		answer.push_back(hp.extract_maximum());
	}
	rFor(i, n) {
		look(answer[i]);
	}
}
 
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	write();
	return 0;
}