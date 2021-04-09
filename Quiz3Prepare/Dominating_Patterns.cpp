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

void write(int & k)
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    vt<pair<int, string> > ss(k);
    For(i, k) {
        ss[i].first = 0;
        cin >> ss[i].second;
    }
    string t;
    cin >> t;
    int m = t.length();
    vt<int> hash2(m), power;
    int p = 1;
    For(i, m) {
        power.push_back(p);
        p *= prime; 
    }
    hash2[0] = (t[0] - 'a' + 1);
    qFor(i, 1, m) {
        hash2[i] = hash2[i - 1] + (t[i] - 'a' + 1) * power[i];
    }
    int maxi = 0;
    For(kk, k) {
        string s = ss[kk].second;
        int n = s.length();
        int hash = 0;
        For(i, n) {
            hash += (s[i] - 'a' + 1) * power[i]; 
        }
        if (hash == hash2[n - 1]) {
            ss[kk].first++;
        }
        for (int i = n; i < m; ++i) {
            int tmp = (hash2[i] - hash2[i - n]);
            int tmp2 = hash * power[i - n + 1];
            if (tmp == tmp2) {
                ss[kk].first++;
            }
        }
        maxi = max(maxi, ss[kk].first);
    }
    cout << maxi << endl;
    For(kk, k) {
        if (ss[kk].first == maxi) {
            cout << ss[kk].second << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    while (cin >> T) {
        if (T == 0) break;
        write(T);
    }
    return 0;
}