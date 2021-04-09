#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
 
bool is_prime(int n)
{
    if (n == 1)
        return true;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void factorization(int n)
{
    vector<int> v;
    for (int i = 2; i <= sqrt(n); ++i)
    {
        while(n % i == 0)
        {
            v.push_back(i);
            n = n / i;
        }
    }
    if (n != 1)
    {
        v.push_back(n);
    }
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
}

void dividers(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if (i * i != n)
            {
                v.push_back(n / i);
            }
        }
    }
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    dividers(n);
    return 0;
}