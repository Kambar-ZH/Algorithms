#include <iostream>
using namespace std;
 
int euclid_gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    int temp = a;
    a = b;
    b = temp % b;
    euclid_gcd(a, b);
}

int lcm(int a, int b)
{
    return a * b / euclid_gcd(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b);
    return 0;
}