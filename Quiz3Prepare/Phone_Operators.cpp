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
 
int vn = 1;
const int N = 1e5;
int to[10][N];
vt<bool> end(N, false);

void add(string & s) {
    int n = s.length();
    int v = 1;
    For(i, n) {
        char c = s[i] - '0';
        if (to[c][v] == 0) {
            to[c][v] = ++vn;
        }
        v = to[c][v];
    }
    end[v] = true;
}

bool find(string & s) {
    int n = s.size();
    int v = 1;
    For(i, n) {
        char c = s[i] - '0';
        if (to[c][v] == 0) {
            return end[v];
        }
        v = to[c][v];
    }
    return false;
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    For(i, n) {
        string s;
        cin >> s;
        add(s);
    }
    For(i, m) {
        string s;
        cin >> s;
        int n = s.length();
        if (find(s)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}