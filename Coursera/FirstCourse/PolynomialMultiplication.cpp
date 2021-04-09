#include <iostream>
#include <vector>
using namespace std;

void poly_multy(int n, int _first[], int _second[])
{
    vector<int> product(2 * n - 1);
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        product[i] = 0;
    }
    for (int i= 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            product[i+j] += _first[i] * _second[j];
        }
    }
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        cout << product[i] << " ";
    }
}



int main()
{
    int n;
    cin >> n;
    int _first[n];
    int _second[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> _first[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin >> _second[i];
    }
    poly_multy(n, _first, _second);
    return 0;
}