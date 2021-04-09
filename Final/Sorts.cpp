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

void generate(vt<int> & a) {
    For(i, a.size()) {
        a[i] = rand();
    }
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

void heapsort(vt<int> & a) {
    heap kama;
    For(i, a.size()) {
        kama.insert(a[i]);
    }
    while (kama.tree.size()) {
        a[kama.tree.size() - 1] = kama.get_max();
        kama.delete_top();
    }
}

void merge(vt<int> & a, int l, int m, int r) {
    int ptr1 = l;
    int ptr2 = m + 1;
    vt<int> tmp;
    while (ptr1 <= m && ptr2 <= r) {
        if (a[ptr1] < a[ptr2]) {
            tmp.push_back(a[ptr1]);
            ptr1++;
        } else {
            tmp.push_back(a[ptr2]);
            ptr2++;    
        }
    }
    while (ptr1 <= m) {
        tmp.push_back(a[ptr1]);
        ptr1++;
    }
    while (ptr2 <= r) {
        tmp.push_back(a[ptr2]);
        ptr2++;    
    }
    for (int i = l; i <= r; ++i) {
        a[i] = tmp[i - l];
    }
}

void mergesort(vt<int> & a, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);

    merge(a, l, m, r);
}
 
int partition(vt<int> & a, int l, int r) {
    int p = a[r];
    int ptr = l;
    for (int i = l; i < r; ++i) {
        if (a[i] <= p) {
            swap(a[i], a[ptr]);
            ptr++;
        }
    }
    swap(a[r], a[ptr]);
    return ptr;
}

void quicksort(vt<int> & a, int l, int r) {
    if (l >= r) return;
    int pivot = partition(a, l, r);
    quicksort(a, l, pivot - 1);
    quicksort(a, pivot + 1, r);
}

void check(vt<int> & a, vt<int> & b, vt<int> & c) {
    For(i, a.size()) {
        if (a[i] != b[i] && a[i] != c[i]) {
            cout << "WRONG";
            exit(0);
        }
    }
    cout << "GOOD";
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vt<int> a(n), b, c;
    generate(a);
    b = c = a;
    mergesort(a, 0, n - 1);
    quicksort(b, 0, n - 1);
    heapsort(c);
    // print(a);
    // print(b);
    // print(c);
    check(a, b, c);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}