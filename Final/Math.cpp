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
const int MOD = 1e9 + 7;
 
template<typename T>
void read(vt<T> & a) {
    For(i, a.size()) cin >> a[i];
}
template<typename T>
void print(vt<T> & a) {
    For(i, a.size()) cout << a[i] << " " ;
    cout << endl;
}

int N = 1e5 + 1e3; 
vt<bool> isprime(N, true);

void findPrimes(int n) {
    isprime[0] = isprime[1] = false;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (isprime[i]) {
            for (int j = 2 * j; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }
}

vt<int> factorize(int n) {
    vt<int> factors;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        factors.push_back(n);
    }
    return factors;
}

ll binpow(ll a, ll b) {
    if (b == 0) return 1;
    ll tmp = binpow(a, b / 2);
    if (b % 2 == 1) {
        return ((a * tmp) % MOD * tmp) % MOD;
    }
    return (tmp * tmp) % MOD;
}

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}



void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}