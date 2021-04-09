#include <bits/stdc++.h>
using namespace std;
 
bool compare(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    if (a.second < b.second) {
        return 1;
    } else if (a.second > b.second) {
        return 0;
    }
    if (a.first.second < b.first.second) {
        return 1;
    } else if (a.first.second > b.first.second) {
        return 0;
    } 
	if (a.first.first < b.first.first) {
        return 1;
    } else if (a.first.first > b.first.first) {
        return 0;
    } 
    return 1;
}

int partition(vector<pair<pair<int, int>, int> > & a, int l, int r) {
    pair<pair<int, int>, int> pivot = a[r];
    int i = (l - 1);
    for (int j = l; j <= r - 1; j++) {
        if (compare(a[j], pivot)) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

void quick_sort(vector<pair<pair<int, int>, int> > & a, int l, int r) {
    if (l < r) {
        int pi = partition(a, l, r);
        quick_sort(a, l, pi - 1);
        quick_sort(a, pi + 1, r);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first.first >> a[i].first.second >> a[i].second;
    }
    quick_sort(a, 0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i].first.first << " " << a[i].first.second << " " << a[i].second << endl;
    }
    return 0;
}