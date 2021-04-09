#include <iostream> 
using namespace std;

int knapsack_rep(int n, int k, int a[], int b[])
{
    int value[n + 1];
    for (int w = 0; w < n + 1; ++w)
    {
        value[w] = 0;
        for (int i = 0; i < k; ++i)
        {
            if (a[i] <= w)
            {
                int val = value[w - a[i]]  + b[i];
                if (val > value[w])
                {
                    value[w] = val;
                }
            }
        }
    }
    return value[n];
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int a[k];
    int b[k];
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i] >> b[i];
    }
    int result = knapsack_rep(n, k, a, b);
    cout << result;
}