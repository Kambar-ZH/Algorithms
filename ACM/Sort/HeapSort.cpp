#include <bits/stdc++.h>
using namespace std;
 
void heapify(int data[], int n, int i)
{
    int lar = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && data[lar] < data[l])
        lar = l;
    if (r < n && data[lar] < data[r])
        lar = r;
    if (lar != i)
    {
        swap(data[i], data[lar]);
        heapify(data, n, lar);
    }
}

void heap_sort(int data[], int n)
{
    for (int i = n / 2 - 1; i >= 0; --i)
    {
        heapify(data, n, i);
    }

    for (int i = n - 1; i >= 0; --i)
    {
        swap(data[0], data[i]);
        heapify(data, i, 0);
    }
}

int main()
{
    int n;
    cin >> n;
    int data[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> data[i];
    }
    heap_sort(data, n);
    for (int i = 0; i < n; ++i)
    {
        cout << data[i] << " ";
    }
    return 0;
}