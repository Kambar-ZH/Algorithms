#include <iostream>
using namespace std;

int grouping_childs(int n, float a[])
{
    int R, i;
    R = 0;
    i = 0;
    while (i <= n)
    {
        float left, right;
        left = a[i]; 
        right = a[i] + 1;
        R += 1;
        cout << "Plus group" << endl;
        i += 1;
        while (i <= n && right >= a[i])
        {
            i += 1;
        }
        cout << endl;
    }
    return R;
}

int main()
{
    int n;
    cin >> n;
    float a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int result;
    result = grouping_childs(n, a);
    cout << result;
    return 0;
}