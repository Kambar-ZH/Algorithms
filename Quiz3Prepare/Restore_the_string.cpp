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
    vt<ll> a;
    a.push_back(0);
    For(i, n) {
        ll x;
        cin >> x;
        a.push_back(x);
    }   
    vt<ll> powers;
    ll p = 1;
    For(i, n) {
        powers.push_back(p);
        p *= 2;
    }
    string res = "";
    qFor(i, 1, n + 1) {
        char c = (a[i] - a[i - 1]) / powers[i - 1] + 'a';
        res.push_back(c);
    }
    cout << res << endl;
}

hash[i] = hash[i - 1] + (s[i] - 'a') * p;
(s[i] - 'a') * p = hash[i] - hash[i - 1];
s[i] - 'a' = (hash[i] - hash[i - 1]) / p;
s[i] = (hash[i] - hash[i - 1]) / p + 'a';

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}