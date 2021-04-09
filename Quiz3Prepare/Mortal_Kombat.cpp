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
        while (j > 0 && s[j] != s[i]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) j++;
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
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    For(i, m - n) {
        s.push_back(s[i % n]);
    }
    vt<int> p = pf(s + '#' + t);
    int maxi = 0;
    qFor(i, m, p.size()) {
        maxi = max(maxi, p[i]);
    }
    cout << maxi / n;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}

/* Dias verison
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
const int prime = 31;
 
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
    string s, t;
    cin >> s >> t;
    int n = s.length();
    int m = t.length();
    int hash = 0;
    vt<int> hash2(m);
    vt<int> power;
    int p = 1;
    For(i, m) {
        power.push_back(p);
        p *= prime; 
    }
    hash2[0] = (t[0] - 'a' + 1);
    qFor(i, 1, m) {
        hash2[i] = hash2[i - 1] + (t[i] - 'a' + 1) * power[i];
    }
    For(i, n) {
        hash += (s[i] - 'a' + 1) * power[i]; 
    }
    vt<int> a(m);
    if (hash == hash2[n - 1]) {
        a[n - 1] = 1;
    }
    for (int i = n; i < m; ++i) {
        int tmp = (hash2[i] - hash2[i - n]);
        int tmp2 = hash * power[i - n + 1];
        if (tmp == tmp2) {
            a[i] = a[i - n] + 1;
        }
    }
    cout << a[m - 1] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}*/