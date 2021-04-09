// Problem D. Mutual Sort
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
 
void merge(vector<pair<int, int> > & a, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<pair<int, int> > b, c;
    for(int i = 0; i < n1; ++i) {
        b.push_back(a[i + l]);
    }
    for (int i = 0; i < n2; ++i) {
        c.push_back(a[i + m + 1]);
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (b[i].second < c[j].second) {
            a[k] = b[i];
            i++;
        } else if (b[i].second > c[j].second) {
            a[k] = c[j];
            j++;
        } else {
            if (b[i].first < c[j].first) {
                a[k] = b[i];
                i++;
            } else {
                a[k] = c[j];
                j++;
            }
        }
        k++;
    }

    while (i < n1) {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = c[j];
        j++;
        k++;
    }
}

void merge_sort(vector<pair<int, int> > & a, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge_sort(a, l, m, r);
    }
}

void write()
{
#ifdef DEBUG
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > a(n);
    For(i, n) {
        int x;
        cin >> x;
        a[i] = {x, MAXN};
    }   
    For(i, m) {
        int x;
        cin >> x;
        For(j, n) {
            if (a[j].first == x) {
                a[j] = {x, i};
            }
        }
    }
    merge_sort(a, 0, n - 1);
    For(i, n) {
        cout << a[i].first << " ";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}