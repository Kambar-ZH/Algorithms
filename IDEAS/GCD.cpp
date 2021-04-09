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

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
 
// we have an array that obtained by
// getting gcd(x, y) where x and y are 
// values from initial array
// help us to find the minimal initial array
// https://codeforces.com/gym/307122/problem/F

void write()
{
    int n;
    cin >> n;
    vt<int> a(n);
    read(a);
    set<int> st, st2;
    For(i, n) {
        st2.insert(a[i]);
    }
    sort(rall(a));
    vt<int> ans{a[0]};
    vt<int> ok(n);
    st.insert(a[0]);
    For(i, n) {
        for (int j = 0; j <= i; ++j) {
            int tmp = gcd(a[i], a[j]);
            if (st.find(tmp) == st.end()) {
                ok[i] = 1;
                ok[j] = 1;
                st.insert(tmp);
            } 
            if (st2.find(tmp) == st2.end()) {
                cout << -1 << endl;
                return;
            }
        }
        if (ok[i]) {
            ans.push_back(a[i]);
        }
    }
    cout << ans.size() << endl;
    print(ans);
}

// 2 4 6 12

// gcd(a, b) = 2; -> 2
// gcd(c, d) = 4; -> 2 ^ 2
// gcd(e, f) = 6; -> 2 * 3
// gcd(g, h) = 12; -> 2 ^ 2 * 3

// 12

// 4 6 12
 
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