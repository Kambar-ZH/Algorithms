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
 
struct date {
    int month, day, year;
};

bool compare(date a, date b) {
    if (a.year > b.year) {
        return 1;
    } else if (a.year < b.year) {
        return 0;
    }
    if (a.month > b.month) {
        return 1;
    } else if (a.month < b.month) {
        return 0;
    }
    if (a.day > b.day) {
        return 1;
    } else if (a.day < b.day) {
        return 0;
    }
    return 0;
}

void merge(vector<date> & a, int l, int m, int r) {
    vector<date> tmp1, tmp2;
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
        if (compare(tmp2[j], tmp1[i])) {
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

void merge_sort(vector<date> & a, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
    }
}


void write()
{
    int n;
    cin >> n;
    vector<date> a(n);
    For(i, n) {
        cin >> a[i].day >> a[i].month >> a[i].year;
    }
    merge_sort(a, 0, n - 1);
    For(i, n) {
        cout << a[i].day << " " << a[i].month << " " << a[i].year << endl;
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    write();
    return 0;
}