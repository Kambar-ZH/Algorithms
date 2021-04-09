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
#define ll long long
const int MAXN = 1e9;
 
struct letter {
    int ch, prior;
};

bool compare(letter a, letter b) {
    if (a.prior < b.prior) {
        return 1;
    } else if (a.prior > b.prior) {
        return 0;
    }
    if (a.ch > b.ch) {
        return 1;
    } else if (a.ch < b.ch) {
        return 0;
    }
    return 1;
}

int partition(vector<letter> & a, int l, int r) {
    letter pivot = a[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++) {
        if (!compare(a[j], pivot)) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

void quick_sort(vector<letter> & a, int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

void write()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    vector<letter> a(n);
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'a' || str[i] == 'o' || str[i] == 'i' || str[i] == 'e' || str[i] == 'u') {
            a[i].ch = str[i];
            a[i].prior = 1;
        } else {
            a[i].ch = str[i];
            a[i].prior = 0;
        }
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << char(a[i].ch);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}