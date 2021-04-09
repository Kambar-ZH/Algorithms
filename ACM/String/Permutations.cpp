#include <iostream>
#include <vector>
using namespace std;
 
bool find(int a, vector<int> & array)
{
    for (int i = 0; i < array.size(); ++i)
    {
        if (a == array[i])
            return true;
    }
    return false;
}

int permutations(int n, vector<int> & prefix, int m = -1)
{
    (m == -1) ? (m = n) : m;
    if (m == 0)
    {
        for (int i = 0; i < prefix.size(); ++i)
        {
            cout << prefix[i] << " ";
        }
        cout << endl;
        return 0;
    }
    for (int i = 1; i < n + 1; ++i)
    {
        if (find(i, prefix))
            continue;
        prefix.push_back(i);
        permutations(n, prefix, m - 1);
        prefix.pop_back();
    }
} 

int main()
{
    int n; // читаем
    cin >> n;
    vector<int> prefix;
    permutations(n, prefix);
    return 0;
}