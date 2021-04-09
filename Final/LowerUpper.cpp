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

int lowerBound(vt<int> & a, int x) {
    int l = 0, r = a.size() - 1, m; 
    while (l < r) {
        m = (l + r) / 2;
        if (a[m] >= x) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int upperBound(vt<int> & a, int x) {
    int l = 0, r = a.size() - 1, m; 
    while (l < r) {
        m = r - (r - l) / 2;
        if (a[m] > x) {
            r = m - 1;
        } else {
            l = m;
        }
    }
    return r;
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    vt<int> a(n);
    read(a);
    int q;
    cin >> q;
    For(qq, q) {
        int x;
        cin >> x;
        cout << lowerBound(a, x) << " " << upperBound(a, x) << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}