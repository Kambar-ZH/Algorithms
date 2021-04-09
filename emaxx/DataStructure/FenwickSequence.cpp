#include <bits/stdc++.h>

using namespace std;

int n;
int seq[100000];  //последовательность

int a[1000001];  //массив, соответствующий дереву Фенвика
int f[1000001];  //дерево Фенвика

int get_max(int x) {
    int result = INT_MIN;

    for (; x >= 0; x = (x & (x + 1)) - 1) {
        result = max(result, f[x]);
    }

    return result;
}

//(val >= a[idx])
void assign(int idx, int val) {
    a[idx] = val;

    for (; idx <= 1000000; idx |= idx + 1) {
        f[idx] = max(f[idx], val);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> seq[i];
    }

    for (int i = 0; i < n; i++) {
        int x = seq[i];
        int prev_max = get_max(x - 1);  //максимальная длина, которую можно продолжить

        if (prev_max + 1 > a[x]) {
            assign(x, prev_max + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << f[i] << " ";
    }
    int ans = get_max(n);
    cout << ans << endl;
}