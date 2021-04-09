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
void print(vt<T> & a, int n) {
    For(i, n) cout << a[i] << " " ;
    cout << endl;
}

const int p = 31;
const int N = 1e5 + 1e3;
vt<int> hashes(N);
vt<int> power(N, 1);

int getnum(char c) {
    return (c - 'a' + 1);
}

void getpower(string s) {
    int n = s.length();
    for (int i = 1; i < n; ++i) {
        power[i] = power[i - 1] * p;
    }
}
 
void gethashes(string s) {
    int n = s.length();
    for (int i = 1; i <= n; ++i) {
        hashes[i] = hashes[i - 1] + getnum(s[i - 1]) * power[i - 1];
    }
}

int gethash(string s) {
    int n = s.length();
    int myhash = 0;
    for (int i = 0; i < n; ++i) {
        myhash += getnum(s[i]) * power[i];
    }
    return myhash;
}


bool find(string text, string word) {
    int textlen = text.length();
    int wordlen = word.length();
    int myhash = gethash(word);
    for (int i = 0; i < textlen - wordlen; ++i) {
        if (hashes[i + wordlen] - hashes[i] == myhash * power[i]) {
            return true;
        }
    }
    return false;
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    string s;
    cin >> s;
    string t;
    cin >> t;
    int n = s.length();
    getpower(s);
    gethashes(s);
    cout << find(s, t);
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}