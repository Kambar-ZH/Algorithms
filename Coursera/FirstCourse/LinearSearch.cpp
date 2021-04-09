#include <iostream>
using namespace std;

int LinearSearch(int _array[], int low, int high, int key)
{
    if (high < low)
        return 0;
    if (key == _array[low])
        return low;
    return LinearSearch(_array, low + 1, high, key);
    
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
    cout << LinearSearch(a, 0, n, k);
}