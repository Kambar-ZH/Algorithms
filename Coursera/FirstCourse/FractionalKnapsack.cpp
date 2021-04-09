#include <iostream>
#include <map>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    int value, weight;
    map<int, int> food;
    for (int i = 0; i < n; ++i)
    {
        cin >> value >> weight;
        food.insert( pair<int, int>(value, weight));
    }
    map<int, int>::iterator it = food.begin();
    float result = 0;
    int it_second = it->second;
    for (int i = 0; i < k; i++)
    {
        if (it->second == 0)
        {
            it++;
            it_second = it->second;
        }
        result += it->first / it_second;
        cout << result << endl;
        food[it->first] -= 1;
    }
}