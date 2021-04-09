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

vt<int> get_hashes(string & s) {
    int n = s.length();
    vt<int> powers(n);
    vt<int> hashes_v(n + 1);
    int prime = 31;
    powers[0] = 1;
    for (int i = 1; i < n; i++)
    {
        powers[i] = powers[i - 1] * prime;
    }
    hashes_v[1] = s[0] - 'a' + 1;
    for (int i = 2; i <= n; ++i) {
        hashes_v[i] = hashes_v[i - 1] + (s[i - 1] - 'a' + 1) * powers[i - 1];
    }
    return hashes_v;
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.length();
    set<int> hashes;
    vt<int> main_hash = get_hashes(s);
    vt<int> powers(5000);
    int prime = 31;
    powers[0] = 1;
    for (int i = 1; i <= 5000; i++)
    {
        powers[i] = powers[i - 1] * prime;
    }
    map<int, pair<pair<int, int>, int> > m;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            int total = (main_hash[j] - main_hash[i]) / powers[i];
            hashes.insert(total);
            m[total] = {{i, j}, 0};
        }
    }

    For(kk, k - 1) {
        string t;
        cin >> t;
        int mm = t.length();
        vt<int> dep_hash = get_hashes(t);
        for (int i = 0; i <= mm; ++i) {
            for (int j = i + 1; j <= mm; ++j) {
                int total = (dep_hash[j] - dep_hash[i]) / powers[i];
                if (hashes.find(total) != hashes.end()) {
                    if (m[total].second == kk + 1) continue;
                    if (m[total].second != kk) {
                        m[total].second = -1;
                    }
                    if (m[total].second != -1) {
                        m[total].second = kk + 1;
                    }
                }
            }
        }
    }
    int maximum = 0;
    for (auto i : m) {
        if (i.second.second == k - 1) {
            maximum = max(maximum, i.second.first.second - i.second.first.first);
        }
    }
    for (auto i : m) {
        if (i.second.second == k - 1 && i.second.first.second - i.second.first.first == maximum) {
            for (int j = i.second.first.first; j < i.second.first.second; ++j) {
                cout << s[j];
            }
            return;
        }
    }

}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}