#include <bits/stdc++.h>
using namespace std;
#define pb(i) push_back(i)
#define For(i, n) for(int i = 0; i < n; ++i)
#define qFor(i, x, n) for(int i = x; i < n; ++i)
#define read(x) cin >> x
#define rFor(i, n) for(int i = n - 1; i >= 0; --i)
#define see(i) cout << i << endl
#define look(i) cout << i << " " 
#define look_pair(i, j) cout << i << " " << j << endl
#define pa pair<int, int>
#define vi vector<int>
#define vpi vector<pa>
#define ll long long
const int MAXN = 1e9;
 
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll mult(ll a, ll b, ll mod) {
    if (b == 1) return a;
    if (b % 2 == 0) {
        ll t = mult(a, b / 2, mod);
        return (2 * t) % mod;
    }
    return (mult(a, b - 1, mod) + a) % mod;
}

ll pows(ll a, ll b, ll mod) {
    if (b == 0) return 1;
    if (b % 2 == 0) {
        ll t = pows(a, b / 2, mod);
        return mult(t, t, mod) % mod;
    }
    return (mult(pows(a, b - 1, mod), a, mod)) % mod;
}

bool ferma(ll n) {
    if (n == 2) return true;
    srand(time(NULL));
    For(i, 100) {
        ll a = (rand() % (n - 2) ) + 2;
        if (gcd(a, n) != 1) {
            return false;
        }
        if (pows(a, n - 1, n) != 1) {
            return false;
        }
    }
    return true;

}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    ll n;
    cin >> n;
    bool is_prime = ferma(n);
    if (is_prime) cout << "YES";
             else cout << "NO";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}