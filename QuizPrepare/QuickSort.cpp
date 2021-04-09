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
 
int partition(vector<int> & a, int l, int r) {
    int pivot = a[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

void quick_sort(vector<int> & a, int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vector<int> a(n);
    For(i, n) cin >> a[i];
    quick_sort(a, 0, n - 1);  
    For(i, n) cout << a[i] << " "; 
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}