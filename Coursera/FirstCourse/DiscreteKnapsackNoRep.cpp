#include <iostream>
using namespace std;
// NOT CORRECT
int knapsack_no_rep(int n, int k, int a[], int b[])
{
    int value[n + 1][k + 1];
    for (int i = 0; i < n + 1; ++i)
    {
        value[i][0] = 0;
    }
    for (int w = 0; w < k + 1; ++w)
    {
        value[0][w] = 0;
    }
    for (int w = 1; w < k + 1; ++w)
    {
        for (int i = 1; i < n + 1; ++i)
        {
            value[i
            ][w] = value[i][w - 1];
            if (a[w] <= i)
            {
                int val = value[i - a[w]][w - 1] + b[w];
                if (value[i][w] < val)
                {
                    value[i][w] = val;
                }
            }
        }
    }
    return value[n][k];
}

int main()
{
    int n; 
    cin >> n;
    int k;
    cin >> k;
    int a[k], b[k];
    for (int i = 0; i < k; ++i)
    {
        cin >> a[i] >> b[i];
    }
    int result = knapsack_no_rep(n, k, a, b);
    cout << result;
}