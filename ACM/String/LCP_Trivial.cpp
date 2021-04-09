#include <bits/stdc++.h>
using namespace std;
 
int main()
{   
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }
    string first = words[0];
    int maximum = 10;
    for (int i = 1; i < n; i++)
    {
        int counter = 0;
        for (int j = 0; j < first.length(); j++)
        {
            if (first[j] == words[i][j])
                counter += 1;
            else
                break;
        }
        if (maximum > counter)
            maximum = counter;
    }
    cout << maximum;
    return 0;
}