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
 
void merge(vector<int> & a, int l, int m, int r) {
    vector<int> tmp1, tmp2;
    int n1 = m - l + 1;
    int n2 = r - m;
    for (int i = 0; i < n1; ++i) {
        tmp1.push_back(a[i + l]);
    }
    for (int i = 0; i < n2; ++i) {
        tmp2.push_back(a[i + m + 1]);
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (tmp2[j] > tmp1[i]) {
            a[k] = tmp1[i];
            i++;
        } else {
            a[k] = tmp2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = tmp1[i];
        i++;
        k++;
    }

    while (j < n2) {
        a[k] = tmp2[j];
        j++;
        k++;
    }
}

void merge_sort(vector<int> & a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void show(vector<int> & a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        cout << a[m] << " ";
        show(a, l, m);
        show(a, m + 1, r);
    }
}

void write()
{
    int n;
    cin >> n;
    n = pow(2, n) - 1;
    vector<int> a(n);
    For(i, n) cin >> a[i];
    merge_sort(a, 0, n - 1);
    show(a, 0, n);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}