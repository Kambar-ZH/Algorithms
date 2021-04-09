#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int> sequence(n, 0);
    sequence[0] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i - 1; j >= 0 ; j--)
        {
            if (arr[i] > arr[j])
            {
                sequence[i] = max(sequence[j] + 1, sequence[i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << sequence[i] << " ";
    }
    
    return 0;
}