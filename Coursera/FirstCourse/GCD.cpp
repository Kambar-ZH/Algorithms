#include <iostream>
using namespace std;

int GCD_Euclid(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return GCD_Euclid(b, a % b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCD_Euclid(a, b);
}