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

// long long counter = 0;

void merge(vt<int> & b, int left, int middle, int right) {
    int left2 = left,  middle2 = middle + 1;
    vt<int> temporary;
    while (left2 <= middle || middle2 <= right) {
        if (left2 <= middle && middle2 <= right) {
            if(b[left2] < b[middle2]) {
                temporary.push_back(b[left2]);
                left2++;
                // counter += middle2 - middle - 1;
            } else {
                temporary.push_back(b[middle2]);
                middle2++;
            }
        } else if (left2 > middle) {
            temporary.push_back(b[middle2]);
            middle2++;
        } else {
            temporary.push_back(b[left2]);
            left2++;
            // counter += middle2 - middle - 1;
        }
    }
    for (int i = left; i <= right; ++i) {
        b[i] = temporary[i - left];
    }
}
 
void merge_sort(vt<int> & b, int left, int right) {
    if (left >= right) return;
    int middle = (left + right) / 2;
    merge_sort(b, left, middle);
    merge_sort(b, middle + 1, right);
    merge(b, left, middle, right);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n;
    vt<int> a(n);
    For(i, n) cin >> a[i];
    merge_sort(a, 0, n - 1);
    // cout << counter;
    For(i, n) look(a[i]);
    return 0;
}