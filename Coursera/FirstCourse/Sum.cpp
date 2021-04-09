#include <iostream>
#include <vector>
using namespace std;

long long maximum_pair_mult(int n, const vector<int>& v)
{
    long long max_number_index = 1;
    long long second_max_number_index = 0;
    if (v[0] >= v[1])
    {
        max_number_index = 0;
        second_max_number_index = 1;
    }
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > v[max_number_index])
        {
            max_number_index = i;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (v[i] > v[second_max_number_index] and v[i] < v[max_number_index])
        {
            second_max_number_index = i;
        }
    }
    cout << v[max_number_index]) << " " << v[second_max_number_index];
    return ((long long)(v[max_number_index])) * v[second_max_number_index];
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i];
    }
    long long result;
    result = maximum_pair_mult(n, v);
    cout << result;
}