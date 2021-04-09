#include <iostream>
#include <cmath>
using namespace std;

int MinAndMax(int n, int k, int numbers[], int operations[])
{
    int min = 1000000;
    int max = -1000000;
    int M[n][k];
    for (int i = 0; i < )
}

int main()
{
    string equation;
    cin >> equation;
    int n = ceil(equation.size());
    int k = floor(equation.size());
    int numbers[n];
    int operations[k]
    for (int i = 0; i < equation.size(); ++i)
    {
        if (i % 2 == 0)
        {
            numbers.append(equation[i]);
        }
        else
        {
            operations.append(equation[i]);
        }
    }

}