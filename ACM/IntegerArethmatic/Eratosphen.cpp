#include <iostream>
#include <vector>
using namespace std;
 
bool sieve[1000001];
vector<int> primes;

void compute_primes(int n)
{
    for (int i = 2; i <= n; ++i) // Заполняем все числа 1
    {
        sieve[i] = true;
    }
    for (int i = 2; i <= n; ++i)
    {
        if (sieve[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= n; j += i)
            {
                sieve[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    compute_primes(n);
    for (int i = 0; i < primes.size(); ++i)
    {
        cout << primes[i] << " ";
    }
    return 0;
}