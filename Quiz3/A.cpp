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
 
vt<int> pf(string s) {
    int n = s.length();
    vt<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }
    return p;
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    int m = s.length();
    vt<int> hash(m), power(m);
    int p = 31;
    power[0] = 1;
    for (int i = 1; i < m; i++)
    {
        power[i] = power[i - 1] * p;
    }
    hash[0] = (s[0] - 'a' + 1);
    qFor(i, 1, m) {
        hash[i] = hash[i - 1] + (s[i] - 'a' + 1) * power[i];
    }
    int cnt = 0;
    for(int i = 0; i < s.size() / 2; i++) {
        int t1 = hash[i] * power[i + 1];
        int t2 = hash[i * 2 + 1] - hash[i];
        if (t1 == t2) {
            cnt++;
        }
    }
    cout << cnt;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}