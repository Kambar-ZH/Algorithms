#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int SIZE;
    cin >> SIZE;
    int ITEMS_NUM;
    cin >> ITEMS_NUM;
    int weights[ITEMS_NUM], price[ITEMS_NUM];
    for (int i = 0; i < ITEMS_NUM; ++i)
    {
        cin >> weights[i] >> price[i];
    }
    int matrix[ITEMS_NUM + 1][SIZE + 1];
    for (int i = 0; i < ITEMS_NUM + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            matrix[i][j] = 0;
        }
    }
    for (int i = 0; i < ITEMS_NUM + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                continue;
            }
            else if (j >= weights[i - 1])
            {
                matrix[i][j] = max(price[i - 1] + matrix[i - 1][j - weights[i - 1]], matrix[i - 1][j]);
            }
            else
            {
                matrix[i][j] = matrix[i - 1][j];
            }   
        }
    }
    for (int i = 0; i < ITEMS_NUM + 1; i++)
    {
        for (int j = 0; j < SIZE + 1; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}