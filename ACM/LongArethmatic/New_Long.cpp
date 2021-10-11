#include <bits/stdc++.h>
using namespace std;
#define pb(i)               push_back(i)
#define For(i, n)           for(int i = 0; i < n; ++i)
#define qFor(i, x, n)       for(int i = x; i < n; ++i)
#define rFor(i, n)          for(int i = n - 1; i >= 0; --i)
#define see                 cout << endl
#define all(x)              (x).begin(),(x).end()
#define rall(x)             (x).rbegin(),(x).rend()
#define pii                 pair<int, int>
#define vt                  vector
#define ll                  long long
#define ld                  long double
 
const int MAX = 1e9;
const int MOD = 1e9 + 7;
const ll  INF = 1e18;
const ld  PI  = 3.14159265358979323846;
 
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
template<typename T>
void read2(vt<vt<T> > & a) {
    For(i, a.size()) {
        For(j, a[i].size()) {
            cin >> a[i][j];
        }
    }
}

typedef vector<int> lnum;

const int base = 1000*1000*1000;

void show(lnum a) {
    printf ("%d", a.empty() ? 0 : a.back());
    for (int i=(int)a.size()-2; i>=0; --i)
        printf ("%09d", a[i]);
}

void read_L(string s, lnum & a) {
    for (int i=(int)s.length(); i>0; i-=9)
	if (i < 9)
		a.push_back (atoi (s.substr (0, i).c_str()));
	else
		a.push_back (atoi (s.substr (i-9, 9).c_str()));
    while (a.size() > 1 && a.back() == 0)
	a.pop_back();
}

void plus(lnum & a, lnum & b) {
    int carry = 0;
    for (size_t i=0; i<max(a.size(),b.size()) || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        a[i] += carry + (i < b.size() ? b[i] : 0);
        carry = a[i] >= base;
        if (carry)  a[i] -= base;
    }
}

void minus(lnum & a, lnum & b) {
    int carry = 0;
    for (size_t i=0; i<b.size() || carry; ++i) {
        a[i] -= carry + (i < b.size() ? b[i] : 0);
        carry = a[i] < 0;
        if (carry)  a[i] += base;
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}

void mult(lnum & a, int b) {
    int carry = 0;
    for (size_t i=0; i<a.size() || carry; ++i) {
        if (i == a.size())
            a.push_back (0);
        long long cur = carry + a[i] * 1ll * b;
        a[i] = int (cur % base);
        carry = int (cur / base);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
}
 
int div(lnum a, int b) {
    int carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * base;
        a[i] = int (cur / b);
        carry = int (cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return carry;
}

void write()
{
    string s, t; cin >> s >> t;
    lnum a, b; read_L(s, a); read_L(t, a);

    show(a);
}
 
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