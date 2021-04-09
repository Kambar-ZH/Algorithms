#include <iostream>
using namespace std;

void selection_sort(int n, int a[])
{
    int minindex;
    for (int i = 0; i < n; ++i)
    {
        minindex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minindex])
            {
                minindex = j;
            }
        }
        swap(a[i], a[minindex]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    selection_sort(n, a);
}