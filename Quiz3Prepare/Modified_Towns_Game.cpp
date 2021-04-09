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
int to[26][N];
bool end[N];

void add(vt<char> & s) {
    int n = s.size();
    int v = 1;
    rFor(i, n) {
        char c = s[i] - 'a';
        if (to[c][v] == 0) {
            to[c][v] = ++vn;
        }
        v = to[c][v];
    }
    end[v] = true;
}

int find(string & s) {
    int n = s.length();
    int v = 1;
    int cnt = 0;
    For(i, n) {
        char c = s[i] - 'a';
        if (to[c][v] == 0) {
            if (end[v])
                return cnt;
            return 0;
        }
        cnt++;
        v = to[c][v];
    }
    if (end[v])
        return cnt;
    return 0;
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    vt<char> t;
    string tt;
    cin >> tt;
    tt[0] = char(tt[0] + 32);
    For(i, tt.length()) {
        t.push_back(tt[i]);
    }
    reverse(t.begin(), t.end());
    For(i, tt.length()) {
        add(t);
        t.pop_back();
    }
    int n;
    cin >> n;
    vt<string> a[401];
    For(i, n) {
        string s;
        cin >> s;
        s[0] = char(s[0] + 32);
        int tmp = find(s);
        a[tmp].push_back(s);
    }
    for (int i = 400; i >= 0; --i) {
        if (a[i].size() >= 1) {
            cout << a[i].size() << endl;
            For(j, a[i].size()) {
                a[i][j][0] = char(a[i][j][0] - 32);
                cout << a[i][j] << endl;
            }
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}