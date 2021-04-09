#include <iostream> 
using namespace std;

void counting_sort(int n, int a[])
{
    int maximum = a[0];
    for (int i = 1; i < n; ++i)
    {
        if (maximum < a[i])
        {
            maximum = a[i];
        }
    }
    int counter[maximum];
    for (int i = 0; i < maximum; ++i)
    {
        counter[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        counter[a[i]] += 1;
    }
    for (int i = 0; i < maximum + 1; ++i)
    {
        if (counter[i] != 0)
            cout << i << " ";
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
    counting_sort(n, a);
}