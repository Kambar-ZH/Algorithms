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
#define vt vector
#define itn int
const int MAXN = 1e9;
vt<int> appear(100000, 1);
vt<bool> prime(100000, true);
 
void eratosphen(int n) {
    qFor(i, 2, n / 2) {
        for (int j = 2 * i; j < n; j += i) {
            appear[j] *= i;
        }
    }
}



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    eratosphen(n + 1);
    int counter = 0;
    qFor(i, 4, n + 1) {
        cout << appear[i] << " " << i << endl;
        if (appear[i] == i) counter++;
    }
    see(counter);
    return 0;
}