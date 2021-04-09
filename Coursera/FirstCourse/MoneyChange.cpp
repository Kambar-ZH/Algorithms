#include <iostream>
#include <vector>
using namespace std;

void greedy_change(int money)
{
    vector<int> change;
    int coins[7] = {100, 50, 20, 10, 5, 2, 1};
    int iterator = 0;
    while(money > 0)
    {
        if (money - coins[iterator] >= 0)
        {
            change.push_back(coins[iterator]);
            money -= coins[iterator];
        }
        else
        {
            iterator += 1;
        }
    }
    for (int i = 0; i < change.size(); ++i)
    {
        cout << change[i] << " ";
    }
}

int recursive_change(int money, int n, int coins[])
{
    if (money == 0)
        return 0;
    int MinNumCoins = 10000000;
    cout << "hi" << endl;
    for (int i = 0; i < n; ++i)
    {
        if (money >= coins[i])
        {
            int NumCoins = recursive_change(money - coins[i], n, coins);
            if (NumCoins + 1 < MinNumCoins)
            {
                MinNumCoins = NumCoins + 1;
            }
        }
    }
    return MinNumCoins;
}

int dynamic_programming_change(int money, int n, int coins[])
{
    int MinNumCoins[money + 1];
    for (int i = 0; i < money + 1; ++i)
    {
        MinNumCoins[i] = 0;
    }
    for (int m = 1; m <= money; ++m)
    {
        MinNumCoins[m] = 10000000;
        for (int i = 0; i < n; ++i)
        {
            if (m >= coins[i])
                {
                    int NumCoins = MinNumCoins[m - coins[i]] + 1;
                    if (NumCoins < MinNumCoins[m])
                    {
                        MinNumCoins[m] = NumCoins;
                    }
                }
        }
    }
    return MinNumCoins[money];
}

int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int coins[k];
    for (int i = 0; i < k; ++i)
    {
        cin >> coins[i];
    }
    cout << dynamic_programming_change(n, k, coins);
}