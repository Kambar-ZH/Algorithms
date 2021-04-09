#include <iostream>
#include <cmath>
using namespace std;

int binary_search(int _array[], int low, int high, int key)
{
    if (high < low)
        return low - 1;
    int mid;
    mid = low + ceil((high - low) / 2);
    if (key == _array[mid])
        return mid;
    else if (key < _array[mid])
        return binary_search(_array, low, mid, key);
    else
        return binary_search(_array, mid, high, key);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int k;
    cin >> k;
    cout << binary_search(a, 0, n - 1, k);
}