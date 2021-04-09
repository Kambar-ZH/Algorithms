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
const ll MAXN = 1e18;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " " ;
    cout << endl;
}
 
int partition(vt<ll> & a, int l, int r) {
    ll p = a[r];
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

void quicksort(vt<ll> & a, int l, int r) {
    if (l >= r) return;
    int pivot = partition(a, l, r);
    quicksort(a, l, pivot - 1);
    quicksort(a, pivot + 1, r);
}

void findprefix(vt<ll> & prefix, vt<ll> & a, int n) {
    prefix[0] = a[0]; 
    qFor(i, 1, n) {
        prefix[i] += prefix[i - 1] + a[i];
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
    vt<ll> a(n);
    read(a);
    vt<ll> prefix(n + 1);
    findprefix(prefix, a, n);
    print(prefix);
    quicksort(prefix, 0, n);
    ll minimum = MAXN;
    for(int i = 1; i <= n; i++){ 
        ll res = prefix[i] - prefix[i - 1];
        minimum = min(res, minimum);
    }
} 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}