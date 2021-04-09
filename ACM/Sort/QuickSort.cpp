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

int split(vt<int> & a, const int & l, const int & r) {
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

int find(int k, int l, int r, vt<int> & a) {
    while (true) {
        int m = split(a, l, r);
        if (m == k) {
            return a[m];
        } else if (m > k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
}

void quick_sort(vt<int> & a, int l, int r) {
    if (l < r) {
        int m = split(a, l, r);
        quick_sort(a, l, m - 1);
        quick_sort(a, m + 1, r);
    }
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    read(n);
    vt<int> a(n), b;
    For(i, n) a[i] = rand() % n;
    b = a;
    sort(b.begin(), b.end());
    For(i, n) {
        int res = find(i, 0, n - 1, a);
        cout << res << " " << a[i] << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}